#include "stdafx.h"
#include "interface.h"
#include "draw.h"

void reverse_y(line* Line, int height)
{
	Line->y1 = height - Line->y1;
	Line->y2 = height - Line->y2;
}

void replace_xy(line* Line, int x, int y)
{
	Line->x1 = Line->x1 + x;
	Line->y1 = Line->y1 + y;
	Line->x2 = Line->x2 + x;
	Line->y2 = Line->y2 + y;
}

int sign(double x)
{
	if (x > 0)  return 1;
	return -1;
}

void draw(int method, scene sceneSettings, line Line)
{
	switch (method)
	{
	case STANDART:
		standart(sceneSettings, Line);
		break;
	case BREZ_INT:
		brez_int(sceneSettings, Line);
		break;
	case BREZ_DBL:
		brez_dbl(sceneSettings, Line);
		break;
	case BREZ_NST:
		brez_nst(sceneSettings, Line);
		break;
	case CDA:
		cda(sceneSettings, Line);
		break;
	}
}

void draw_sun(int method, int angle, scene sceneSettings)
{
	line Line;
	Line.x1 = 525;
	Line.y1 = 332;
	for (int a = 0; a < 360; a += angle)
	{
		double ang = a * M_PI / 180.0;
		Line.x2 = (int)round(Line.x1 + cos(ang) * 200);
		Line.y2 = (int)round(Line.y1 + sin(ang) * 200);
		draw(method, sceneSettings, Line);
	}
}

COLORREF pixel_with_alpha(int x, int y, double Alpha, scene sceneSettings)
{
	COLORREF colorLN = sceneSettings.ln_color;
	
	int rBG = GetRValue(GetPixel(sceneSettings.hdc,x,y));
	int gBG = GetGValue(GetPixel(sceneSettings.hdc, x, y));
	int bBG = GetBValue(GetPixel(sceneSettings.hdc, x, y));

	int rLN = GetRValue(colorLN);
	int gLN = GetGValue(colorLN);
	int bLN = GetBValue(colorLN);

	int rR = rBG + (rLN - rBG) * Alpha;
	int gR = gBG + (gLN - gBG) * Alpha;
	int bR = bBG + (bLN - bBG) * Alpha;

	SetPixel(sceneSettings.hdc, x, y, RGB(rR, gR, bR));
	return RGB(rR, gR, bR);
}

void standart(scene sceneSettings, line Line)
{
	SelectObject(sceneSettings.hdc, CreatePen(PS_SOLID, 1, sceneSettings.ln_color));
	MoveToEx(sceneSettings.hdc, Line.x1, Line.y1, NULL);
	LineTo(sceneSettings.hdc, Line.x2, Line.y2);
}

void brez_int(scene sceneSettings, line Line)
{
	double dx, dy;
	int sx, sy;
	double tan;
	int fl;
	int f_err;

	if ((Line.x1 == Line.x2) && (Line.y1 == Line.y2))
	{
		SetPixel(sceneSettings.hdc, Line.x1, Line.y1, sceneSettings.ln_color);
	}
	else
	{
		dx = Line.x2 - Line.x1;
		dy = Line.y2 - Line.y1;
		sx = sign(dx);
		sy = sign(dy);
		dx = fabs(dx);
		dy = fabs(dy);
		tan = dy / dx;

		if (tan > 1)
		{
			double w = dx;
			dx = dy;
			dy = w;
			tan = 1 / tan;
			fl = 1;
		}
		else
			fl = 0;

		f_err = 2 * dy - dx;

		double x = Line.x1;
		double y = Line.y1;

		for (double i = 1; i < dx + 1; i++)
		{
			SetPixel(sceneSettings.hdc, floor(x), floor(y), sceneSettings.ln_color);
			if (f_err >= 0)
			{
				if (fl)
					x += sx;
				else
					y += sy;
				f_err -= 2 * dx;
			}
			if (f_err <  0)
			{
				if (fl)
					y += sy;
				else
					x += sx;
			}
			f_err += 2 * dy;
		}
	}

}

void brez_dbl(scene sceneSettings, line Line)
{
	double dx, dy;
	double sx, sy;
	double tan;
	int fl;
	double f_err;

	if ((Line.x1 == Line.x2) && (Line.y1 == Line.y2))
	{
		SetPixel(sceneSettings.hdc, Line.x1, Line.y1, sceneSettings.ln_color);
	}
	else
	{
		dx = Line.x2 - Line.x1;
		dy = Line.y2 - Line.y1;
		sx = sign(dx);
		sy = sign(dy);
		dx = fabs(dx);
		dy = fabs(dy);
		tan = dy / dx;

		if (tan > 1)
		{
			double w = dx;
			dx = dy;
			dy = w;
			tan = 1 / tan;
			fl = 1;
		}
		else
			fl = 0;


		f_err = tan - 0.5;

		double x = Line.x1;
		double y = Line.y1;

		for (int i = 1; i < dx + 1; i++)
		{
			SetPixel(sceneSettings.hdc, x, y, sceneSettings.ln_color);
			if (f_err >= 0)                            //////
			{
				if (fl)
					x += sx;
				else
					y += sy;
				f_err -= 1.0;
			}
			if (f_err < 0)
			{
				if (fl)
					y += sy;
				else
					x += sx;
			}
			f_err += tan;
		}
	}

}

void cda(scene sceneSettings, line Line)
{
	double delt;
	double dx, dy;

	if ((Line.x1 == Line.x2) && (Line.y1 == Line.y2))
	{
		SetPixel(sceneSettings.hdc, Line.x1, Line.y1, sceneSettings.ln_color);
	}
	else
	{
		dx = (Line.x2 - Line.x1);
		dy = (Line.y2 - Line.y1);

		if (fabs(dx) >= fabs(dy))
			delt = fabs(dx);
		else
			if (fabs(dy) >= fabs(dx))
				delt = fabs(dy);

		dx /= delt;
		dy /= delt;
		double x = Line.x1;
		double y = Line.y1;
		for (double i = 1; i < delt + 1; i++)
		{
			SetPixel(sceneSettings.hdc, int(x + 0.5), int(y + 0.5), sceneSettings.ln_color);
			x += dx;
			y += dy;
		}
	}

}

void brez_nst(scene sceneSettings, line Line)
{
	int I = 256;

	if ((Line.x1 == Line.x2) && (Line.y1 == Line.y2))
	{
		SetPixel(sceneSettings.hdc, Line.x1, Line.y1, sceneSettings.ln_color);
	}
	else
	{
		int curr_x = Line.x1;
		int curr_y = Line.y1;

		int dx = Line.x2 - Line.x1;
		int dy = Line.y2 - Line.y1;
		int sx = sign(dx);
		int sy = sign(dy);
		dx = fabs(dx);
		dy = fabs(dy);

		int sw;
		if (dx > dy)
		{
			sw = 0;
		}
		else
		{
			sw = 1;

			int t = dx;
			dx = dy;
			dy = t;
		}

		double m = (double)dy / dx;

		double e = I / 2;
		m *= I;

		double w = I - m;


		pixel_with_alpha(curr_x, curr_y, e / I, sceneSettings);

		for (int i = 1; i < dx + 1; ++i)
		{

			if (e < w)
			{
				if (sw == 0)
					curr_x += sx;
				else
					curr_y += sy;

				e += m;
			}
			else
			{

				curr_x += sx;
				curr_y += sy;

				e -= w;

			}
			pixel_with_alpha(curr_x, curr_y, e / I, sceneSettings);
		}
	}

}