#include "stdafx.h"

extern HWND hWnd;

HWND createLV(LV settings)
{

	HWND hwndLV = CreateWindowW(WC_LISTVIEW, TEXT(""),
		WS_CHILD | LVS_REPORT | LVS_EDITLABELS,
		settings.XPos, settings.YPos, settings.Width, settings.Height,
		hWnd, (HMENU)ID_TABLE, GetModuleHandle(NULL), NULL);

	ShowWindow(hwndLV, SW_SHOWDEFAULT);
	UpdateWindow(hwndLV);

	addColumn(hwndLV, settings);
	return hwndLV;
}

BOOL addColumn(HWND hwndLV, LV settings)
{
	LVCOLUMN column;
	int columnCount;

	column.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

	for (columnCount = 0; columnCount < settings.columnAmount; columnCount++)
	{
		column.iSubItem = columnCount;
		column.pszText = settings.columnName[columnCount];
		column.cx = settings.columnWidth;
		column.fmt = LVCFMT_CENTER;

		if (ListView_InsertColumn(hwndLV, columnCount, &column) == -1)
			return FALSE;
	}

	return TRUE;
}

BOOL addItem(HWND hwndLV, int rowIndex, int colIndex, WCHAR* item)
{
	LVITEM cell;

	cell.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	cell.stateMask = 0;
	cell.state = 0;

	if (ListView_GetItemCount(hwndLV) <= rowIndex)
	{
		for (int i = ListView_GetItemCount(hwndLV); i <= rowIndex; i++)
		{
			cell.iItem = i;
			cell.iSubItem = 0;
			cell.pszText = L"";
			ListView_InsertItem(hwndLV, &cell);
		}
	}

	cell.iItem = rowIndex;
	cell.iSubItem = colIndex;
	cell.pszText = item;
	ListView_SetItem(hwndLV, &cell);
	ListView_SetItemText(hwndLV, rowIndex, colIndex, item);

	return TRUE;
}

BOOL addDoubleItem(int ID, int rowIndex, int colIndex, double item)
{
	HWND hwndLV = GetDlgItem(hWnd, ID);
	TCHAR buf[128];
	if(colIndex ==0)
		swprintf(buf, L"%0.f", item);
	else 
		swprintf(buf, L"%f", item);
	return addItem(hwndLV, rowIndex, colIndex, buf);
}
