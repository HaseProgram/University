#pragma once

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

HWND createLV(LV settings);
BOOL addColumn(HWND hwndLV, LV settings);
BOOL addItem(HWND hwndLV, int rowIndex, int colIndex, WCHAR* item);
BOOL addDoubleItem(int ID, int rowIndex, int colIndex, double item);
