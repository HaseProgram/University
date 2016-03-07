#include "stdafx.h"

extern HINSTANCE hInst;

void createEditField(HWND hWnd, EDIT settings)
{
	CreateWindowW(TEXT("static"), TEXT(" Start:"),
		WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
		settings.XPos, settings.YPos, settings.Width, settings.Height,
		hWnd, NULL,
		hInst, NULL);
	CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		settings.XPos + 45, settings.YPos + (settings.Height - 20) / 2, settings.Width - 50, 20,
		hWnd, (HMENU)settings.ID, NULL, NULL);
}

TCHAR* valueFromTextField(HWND hWnd, int ID)
{
	TCHAR buf[10];

	HWND edit = GetDlgItem(hWnd, ID);
	GetWindowText(edit, buf, 10);

	return buf;
}