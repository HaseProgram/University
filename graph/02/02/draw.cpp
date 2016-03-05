#include "stdafx.h"

coordinates coordinatesArray;
int dotsCount = 0;
int centerX = 800;
int centerY = 350;
int HEIGHT = 700;

int paperWidth = 700;
int paperHeight = 500;

double DX, DY, scale;

void remap(point *MyPoint, POINT *NewMyPoint, double centerX, double centerY, double HEIGHT, int arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		NewMyPoint[i].x = MyPoint[i].x + centerX;
		NewMyPoint[i].y = HEIGHT - (centerY + MyPoint[i].y);
	}
}

void scaleCoord(point *coordinatesArray, point *scCoordArray, int centerX, int centerY, int HEIGHT, int arrLen)
{
	double minX = coordinatesArray[0].x;
	double maxX = coordinatesArray[0].x;
	double minY = coordinatesArray[0].y;
	double maxY = coordinatesArray[0].y;
	for (int i = 0; i < arrLen; i++)
	{
		scCoordArray[i].x = coordinatesArray[i].x;
		scCoordArray[i].y = coordinatesArray[i].y;
		if (coordinatesArray[i].x < minX)
		{
			minX = coordinatesArray[i].x;
		}
		if (coordinatesArray[i].x > maxX)
		{
			maxX = coordinatesArray[i].x;
		}
		if (coordinatesArray[i].y < minY)
		{
			minY = coordinatesArray[i].y;
		}
		if (coordinatesArray[i].y > maxY)
		{
			maxY = coordinatesArray[i].y;
		}
	}
	DX = -minX - abs(minX - maxX) / 2;
	DY = -minY - abs(minY - maxY) / 2;
	if (arrLen == 1)
	{
		scale = 1;
	}
	else
	{
		double scaleX = (paperWidth - 100) / abs(minX - maxX);
		double scaleY = (paperHeight - 100) / abs(minY - maxY);
		if (scaleX > scaleY)
		{
			scale = scaleY;
		}
		else
		{
			scale = scaleX;
		}
	}
	for (int i = 0; i < arrLen; i++)
	{
		scCoordArray[i].x = floor(scale*(coordinatesArray[i].x + DX));
		scCoordArray[i].y = floor(scale*(coordinatesArray[i].y + DY));
	}
}



void fillCoordArray(HWND hwndTable)
{
	int amountOfRows = ListView_GetItemCount(hwndTable);
	WCHAR tempX[5], tempY[5];
	for (int i = 0; i < amountOfRows; i++)
	{
		ListView_GetItemText(hwndTable, i, 1, tempX, 5);
		ListView_GetItemText(hwndTable, i, 2, tempY, 5);
		coordinatesArray.dot[i].x = _wtof(tempX);
		coordinatesArray.dot[i].y = _wtof(tempY);
	}
	dotsCount = amountOfRows;
}

void printDots(HDC paper)
{
	point scCoordArray[50];
	scaleCoord(coordinatesArray.dot,scCoordArray,centerX,centerY,HEIGHT,dotsCount);
	POINT drCoordArray[50];
	remap(scCoordArray, drCoordArray, centerX, centerY, HEIGHT, dotsCount);
	HBRUSH MyBrush = (HBRUSH)SelectObject(paper, CreateSolidBrush(RGB(0, 0, 0)));
	for (int i = 0; i < dotsCount; i++)
	{
		Ellipse(paper,
			drCoordArray[i].x - 3, drCoordArray[i].y + 3,
			drCoordArray[i].x + 3, drCoordArray[i].y - 3);
	}
	triangle tr;
	circle cr;
	bool drawCircle = FALSE;
	if (dotsCount > 2)
	{
		if (!searchTriangle(coordinatesArray.dot, &tr, dotsCount))
		{
			MessageBox(NULL, L"All dots are collinear!", TEXT("TESTING"), MB_OK);
		}
		else
		{
			cr = getCircle(tr);
			drawCircle = TRUE;
		}
		
		for (int i = 0; i < 3; i++)
		{
			scCoordArray[i].x = floor(scale*(tr.dot[i].x + DX));
			scCoordArray[i].y = floor(scale*(tr.dot[i].y + DY));
		}

		remap(scCoordArray, drCoordArray, centerX, centerY, HEIGHT, 3);
		HPEN hPen = (HPEN)SelectObject(paper, CreatePen(PS_SOLID, 2, RGB(0, 0, 255)));
		MoveToEx(paper, drCoordArray[2].x, drCoordArray[2].y, NULL);
		for (int i = 0; i < 3; i++)
		{
			LineTo(paper, drCoordArray[i].x, drCoordArray[i].y);
		}

		if (drawCircle)
		{

			scCoordArray[0].x = floor(scale*(cr.center.x - cr.r + DX));
			scCoordArray[0].y = floor(scale*(cr.center.y - cr.r + DY));
			scCoordArray[1].x = floor(scale*(cr.center.x + cr.r + DX));
			scCoordArray[1].y = floor(scale*(cr.center.y + cr.r + DY));

			remap(scCoordArray, drCoordArray, centerX, centerY, HEIGHT, 2);
			hPen = (HPEN)SelectObject(paper, CreatePen(PS_SOLID, 2, RGB(255, 0, 0)));
			MyBrush = (HBRUSH)SelectObject(paper, CreateSolidBrush(RGB(255, 255, 255)));

			Ellipse(paper,
				drCoordArray[0].x, drCoordArray[0].y,
				drCoordArray[1].x, drCoordArray[1].y
				);

			double atrArea = (double)calcTrArea(tr.dot[0], tr.dot[1], tr.dot[2]);
			double acrArea = (double)calcCrArea(tr.dot[0], tr.dot[1], tr.dot[2]);

			WCHAR out[256];
			WCHAR oar[256];
			swprintf(out, L"Coords:  %2.f:%2.f  ;  %2.f:%2.f   ;   %2.f:%2.f", tr.dot[0].x, tr.dot[0].y, tr.dot[1].x, tr.dot[1].y, tr.dot[2].x, tr.dot[2].y);
			TextOutW(paper, 330, 15, out, wcslen(out));

			swprintf(oar, L"Area:  Triangle = %2.2f  ;  Circle = %2.2f  ; Subtraction = %2.2f", atrArea, acrArea, atrArea-acrArea);
			TextOutW(paper, 330, 45, oar, wcslen(oar));
		}
	}
}