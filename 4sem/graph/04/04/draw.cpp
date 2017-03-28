#include "stdafx.h"
#include "draw.h"
#include "interface.h"


void draw(efigure figure, params parameters, int alg, scene sceneSettings)
{
																																							alg = 2;
	switch (figure)
	{
	case ELLIPSE:
		switch (alg)
		{
		case 0:
			ellipse_parameters(parameters, sceneSettings);
			break;
		case 1:
			ellipse_average(parameters, sceneSettings);
			break;
		case 2:
			ellipse_standart(parameters, sceneSettings);
			break;
		}
		break;
	case CIRCLE:
		switch (alg)
		{
		case 0:
			circle_equantion(parameters, sceneSettings);
			break;
		case 1:
			circle_parameters(parameters, sceneSettings);
			break;
		case 2:
			circle_brezenhem(parameters, sceneSettings);
			break;
		case 3:
			circle_average(parameters, sceneSettings);
			break;
		case 4:
			circle_standart(parameters, sceneSettings);
			break;
		}
		break;
	case SPEKTRE:
		spektre(alg, parameters, sceneSettings);
		break;
	}
}

void ellipse_parameters(params parameters, scene sceneSettings)
{
	double d = 10 * 2.0 / min(parameters.width, parameters.height);
	for (double i = 0.0; i < 360.0; i += d)
	{
		double a = i * M_PI / 180.0;
		double x = parameters.centerX - cos(a) * parameters.width / 2.0;
		double y = parameters.centerY - sin(a) * parameters.height / 2.0;
		SetPixel(sceneSettings.hdc, round(x), round(y), sceneSettings.ln_color);
	}
}

void ellipse_average(params parameters, scene sceneSettings)
{
	double a = parameters.width * parameters.width / 4.0, b = parameters.height * parameters.height / 4.0;
	double x = 0, y = parameters.height / 2.0;
	SetPixel(sceneSettings.hdc, parameters.centerX, parameters.centerY + y, sceneSettings.ln_color);
	SetPixel(sceneSettings.hdc, parameters.centerX, parameters.centerY - y, sceneSettings.ln_color);
	double border = sqrt(a * a / (a + b));
	while (x < border)
	{
		++x;
		if ((b * (x + 1) * (x + 1) + a * (y - 0.5) * (y - 0.5) - a * b) > 0)
			--y;
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY - y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY - y, sceneSettings.ln_color);

	}
	while (y >= 0)
	{
		if ((b * (x + 0.5) * (x + 0.5) + a * (y - 1) * (y - 1) - a * b) < 0)
			++x;
		--y;
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY - y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY - y, sceneSettings.ln_color);
	}
}

void ellipse_standart(params parameters, scene sceneSettings)
{
	Ellipse(sceneSettings.hdc, 
		parameters.centerX - parameters.width / 2,
		parameters.centerY - parameters.height / 2,
		parameters.centerX + parameters.width / 2,
		parameters.centerY + parameters.height / 2);
}

void circle_equantion(params parameters, scene sceneSettings)
{
	for (double x = parameters.radiusMax, y = 0; x >= y; y += 1, x = sqrt(parameters.radiusMax * parameters.radiusMax - y * y))
	{
		SetPixel(sceneSettings.hdc, round(parameters.centerX + x), round(parameters.centerY + y), sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, round(parameters.centerX + y), round(parameters.centerY + x), sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, round(parameters.centerX - x), round(parameters.centerY + y), sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, round(parameters.centerX + y), round(parameters.centerY - x), sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, round(parameters.centerX + x), round(parameters.centerY - y), sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, round(parameters.centerX - y), round(parameters.centerY + x), sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, round(parameters.centerX - x), round(parameters.centerY - y), sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, round(parameters.centerX - y), round(parameters.centerY - x), sceneSettings.ln_color);
	}
}

void circle_parameters(params parameters, scene sceneSettings)
{
	double d = 10.0 / parameters.radiusMax;
	for (double i = 0.0; i < 360.0; i += d)
	{
		double a = i * M_PI / 180.0;
		double x = parameters.centerX - cos(a) * parameters.radiusMax;
		double y = parameters.centerY - sin(a) * parameters.radiusMax;
		SetPixel(sceneSettings.hdc, round(x), round(y), sceneSettings.ln_color);
	}
}

void circle_brezenhem(params parameters, scene sceneSettings)
{
	int x = 0, y = parameters.radiusMax;
	int k = parameters.radiusMax * parameters.radiusMax;
	SetPixel(sceneSettings.hdc, parameters.centerX, parameters.centerY + y, sceneSettings.ln_color);
	SetPixel(sceneSettings.hdc, parameters.centerX, parameters.centerY - y, sceneSettings.ln_color);
	while (y >= 0)
	{
		int d = (x + 1) * (x + 1) + (y - 1) * (y - 1) - k;
		if (d >= 0)
			y--;
		if (d <= 0)
			x++;
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY - y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY - y, sceneSettings.ln_color);
	}
}

void circle_average(params parameters, scene sceneSettings)
{
	double r = parameters.radiusMax * parameters.radiusMax;
	double x = 0, y = parameters.radiusMax;
	SetPixel(sceneSettings.hdc, parameters.centerX, parameters.centerY + y, sceneSettings.ln_color);
	SetPixel(sceneSettings.hdc, parameters.centerX, parameters.centerY - y, sceneSettings.ln_color);
	double border = sqrt(r / 2.0);
	while (x < border)
	{
		++x;
		if (r * ((x + 1) * (x + 1) + (y - 0.5) * (y - 0.5) - r) > 0)
			--y;
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY - y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY - y, sceneSettings.ln_color);
	}
	while (y >= 0)
	{
		if (r * ((x + 0.5) * (x + 0.5) + (y - 1) * (y - 1) - r) < 0)
			++x;
		--y;
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY + y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX + x, parameters.centerY - y, sceneSettings.ln_color);
		SetPixel(sceneSettings.hdc, parameters.centerX - x, parameters.centerY - y, sceneSettings.ln_color);
	}
}

void circle_standart(params parameters, scene sceneSettings)
{
	SelectObject(sceneSettings.hdc, CreatePen(PS_SOLID, 1, sceneSettings.ln_color));
	Ellipse(sceneSettings.hdc,
		parameters.centerX - parameters.radiusMax,
		parameters.centerY - parameters.radiusMax,
		parameters.centerX + parameters.radiusMax,
		parameters.centerY + parameters.radiusMax);
}

void spektre(int alg, params parameters, scene sceneSettings)
{
	parameters.centerX = 513;
	parameters.centerY = 290;
	for (; parameters.radiusMax >= parameters.radiusMin; parameters.radiusMax -= parameters.radiusStep)
	{
		draw(CIRCLE, parameters, 3, sceneSettings);
	}
}