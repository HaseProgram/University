#pragma once
#include <CommCtrl.h>

#define ID_TABLE 5000
#define ID_FIRSTCOLUMN 6000

typedef struct {
	int XPos;
	int YPos;
	int Width;
	int Height;
	int columnAmount;
	WCHAR* columnName[100];
	int columnWidth;
} LV;

HWND createLV(HWND hWnd, LV settings);
BOOL addColumn(HWND hwndLV, LV settings);
BOOL addItem(HWND hwndLV, int rowIndex, int colIndex, WCHAR* item);
