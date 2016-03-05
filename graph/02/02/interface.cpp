#include "stdafx.h"
extern HINSTANCE hInst;

double mRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

HWND createTable(HWND hWnd)
{
	struct {
		int XPos = 16;
		int YPos = 55;
		int Width = 228;
		int Height = 600;
	} table;

	int columnAmount = 3;

	WCHAR* columnName[256] = { TEXT("N"), TEXT("X"), TEXT("Y") };

	HWND hwndTable = CreateWindowW(WC_LISTVIEW, TEXT(""),
		WS_CHILD | LVS_REPORT | LVS_EDITLABELS,
		table.XPos, table.YPos, table.Width, table.Height,
		hWnd, (HMENU)ID_TABLE, GetModuleHandle(NULL), NULL);

	ShowWindow(hwndTable, SW_SHOWDEFAULT);
	UpdateWindow(hwndTable);
	addColumn(hwndTable,columnAmount,columnName);
	//WCHAR* item[256] = { TEXT("X"), TEXT("Y"), TEXT("Z") };
	//addItem(hwndTable,columnAmount,item);
	return hwndTable;
}

BOOL addColumn(HWND hwndTable, int columnAmount, WCHAR** columnName)
{
	LVCOLUMN column;
	int columnCount;

	int columnWidth = 76;

	column.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

	for (columnCount = 0; columnCount < columnAmount; columnCount++)
	{
		column.iSubItem = columnCount;
		column.pszText = columnName[columnCount];
		column.cx = columnWidth;
		column.fmt = LVCFMT_CENTER;

		if (ListView_InsertColumn(hwndTable, columnCount, &column) == -1)
			return FALSE;
	}

	return TRUE;
}

BOOL addItem(HWND hwndTable, int amountColumns, WCHAR** item)
{
	LVITEM cell;
	WCHAR buf[10];

	cell.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	cell.stateMask = 0;
	cell.iSubItem = 1;
	cell.state = 0;

	int currentRow = ListView_GetItemCount(hwndTable);
	if (currentRow == 50)
		return FALSE;
	cell.iItem = currentRow;

	cell.iSubItem = 0;
	_itow_s(currentRow, buf, 10);

	cell.pszText = (LPWSTR)buf;
	ListView_InsertItem(hwndTable, &cell);
	ListView_SetItemText(hwndTable, currentRow, 0, (LPWSTR)buf);

	for (int i = 0; i < amountColumns-1; i++)
	{
		cell.iSubItem = i+1;
		cell.pszText = item[i];
		ListView_InsertItem(hwndTable, &cell);
		ListView_SetItemText(hwndTable, currentRow, i+1, item[i]);
	}
	fillCoordArray(hwndTable);
	return TRUE;
}

BOOL searchItem(HWND hwndTable, int amountColumns, WCHAR** item)
{
	int amountOfRows = ListView_GetItemCount(hwndTable);
	WCHAR tempX[5], tempY[5];
	for (int i = 0; i < amountOfRows; i++)
	{
		ListView_GetItemText(hwndTable, i, 1, tempX, 5);
		ListView_GetItemText(hwndTable, i, 2, tempY, 5);
		if (!wcscmp(tempX,item[0]) && !wcscmp(tempY,item[1]))
		{
			return TRUE;
		}
	}
	return FALSE;
}

void deleteItem(HWND hwndTable)
{
	LVITEM cell;
	WCHAR buf[10];

	cell.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	cell.stateMask = 0;
	cell.iSubItem = 1;
	cell.state = 0;

	int selected;
	selected = ListView_GetSelectionMark(hwndTable);
	ListView_DeleteItem(hwndTable,selected);

	for (int i = selected; i < ListView_GetItemCount(hwndTable); i++)
	{
		cell.iSubItem = 0;
		_itow(i, buf, 10);

		cell.pszText = (LPWSTR)buf;
		ListView_InsertItem(hwndTable, &cell);
		ListView_SetItemText(hwndTable, i, 0, (LPWSTR)buf);
	}
	fillCoordArray(hwndTable);
}

void fillRandom(HWND hwndTable)
{
	ListView_DeleteAllItems(hwndTable);

	point dot;
	WCHAR buf[10];
	WCHAR *item[2];
	item[0] = (WCHAR*)malloc(10 * sizeof(WCHAR));
	item[1] = (WCHAR*)malloc(10 * sizeof(WCHAR));
	for (int i = 0; i < 50; i++)
	{
		dot.x = mRand(-500,500);
		dot.y = mRand(-400, 400);
		_itow(dot.x, buf, 10);
		wcscpy(item[0],buf);
		_itow(dot.y, buf, 10);
		wcscpy(item[1], buf);
		addItem(hwndTable, 3, item);
	}
}

void createUI(HWND hWnd)
{
	struct {
		int XPos = 15;
		int YPos = 15;
		int Width = 240;
		int Height = 36;
	} text;

	struct {
		int XPos = 105;
		int YPos = 23;
		int Width = 40;
		int Height = 20;
	} fieldX;

	struct {
		int XPos = 165;
		int YPos = 23;
		int Width = 40;
		int Height = 20;
	} fieldY;

	struct {
		int XPos = 215;
		int YPos = 23;
		int Width = 30;
		int Height = 20;
	} button;

	struct {
		int XPos = 15;
		int YPos = 15;
		int Width = 240;
		int Height = 36;
	} textA;

	HWND textAdd = CreateWindowW(TEXT("static"), TEXT(" Add dot:    X:            Y:"),
		WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
		text.XPos, text.YPos, text.Width, text.Height,
		hWnd, NULL,
		hInst, NULL);
	HWND hwndEditX = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE | WS_BORDER, 
		fieldX.XPos, fieldX.YPos, fieldX.Width, fieldX.Height,
		hWnd, (HMENU)ID_EDIT_X, NULL, NULL);
	HWND hwndEditY = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		fieldY.XPos, fieldY.YPos, fieldY.Width, fieldY.Height,
		hWnd, (HMENU)ID_EDIT_Y, NULL, NULL);
	HWND hwndButton = CreateWindowW(TEXT("BUTTON"), TEXT("Add"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 
		button.XPos, button.YPos, button.Width, button.Height,
		hWnd, (HMENU)ID_BUTTON_ADD, hInst, NULL);

}