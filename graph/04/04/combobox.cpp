#include "stdafx.h"
#include "combobox.h"

int currentComboBoxItem = 0;

HWND createCB(HWND hWnd, CB settings, int comboID)
{
	HWND hwndComboBox = CreateWindowW(WC_COMBOBOX, TEXT(""), CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		settings.XPos, settings.YPos, settings.Width, settings.Height,
		hWnd, (HMENU)comboID, GetModuleHandle(NULL), NULL);

	for (int i = 0; i < settings.itemAmount; i++)
	{
		addItem(hwndComboBox, settings.itemName[i]);
	}

	return hwndComboBox;
}

void addItem(HWND hwndComboBox, WCHAR* item)
{
	WCHAR buf[100];
	memset(&buf, 0, sizeof(buf));
	wcscpy_s(buf, sizeof(buf) / sizeof(WCHAR), (WCHAR*)item);
	SendMessage(hwndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)buf);
	SendMessage(hwndComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
}

int getCurrentItem(HWND hWnd)
{
	return ComboBox_GetCurSel(hWnd);
}