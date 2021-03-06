#include "stdafx.h"

extern HINSTANCE hInst;
extern HWND hWnd;

void createEditField(EDIT settings)
{
	CreateWindowW(TEXT("static"), settings.Name,
		WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
		settings.XPos, settings.YPos, settings.WidthT, settings.Height,
		hWnd, NULL,
		hInst, NULL);
	CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		settings.XPos + (settings.WidthT - settings.WidthF) - 10, settings.YPos + (settings.Height - 20) / 2, settings.WidthF, 20,
		hWnd, (HMENU)settings.ID, NULL, NULL);
}

TCHAR* valueFromTextField(int ID, TCHAR buf[10])
{

	HWND edit = GetDlgItem(hWnd, ID);
	GetWindowText(edit, buf, 10);

	return buf;
}