#include "stdafx.h"
#include "interface.h"
#include "combobox.h"

extern HWND hWnd;
extern HINSTANCE hInst;


void color_dialog(scene* sceneSettings, BOOL flag)
{
	CHOOSECOLOR cc = { 0 };
	cc.lStructSize = sizeof(cc);
	COLORREF cust_colors[16] = { 0 };
	cc.lpCustColors = cust_colors;

	if (ChooseColor(&cc)) {
		if(flag)
			sceneSettings->ln_color = cc.rgbResult;
		else
			sceneSettings->bg_color = cc.rgbResult;
	}
}




void init_container(scene* sceneSettings)
{
	SelectObject(sceneSettings->hdc, CreatePen(PS_SOLID, 1, 0x00000000));
	SelectObject(sceneSettings->hdc, CreateSolidBrush(sceneSettings->bg_color));

	Rectangle(
		sceneSettings->hdc, 
		sceneSettings->x, sceneSettings->y, 
		sceneSettings->x + sceneSettings->width, sceneSettings->y + sceneSettings->height);

}

line get_line()
{
	HWND x1, y1;
	HWND x2, y2;

	TCHAR X[5], Y[5];

	line Line;

	x1 = GetDlgItem(hWnd, ID_EDIT_X1);
	y1 = GetDlgItem(hWnd, ID_EDIT_Y1);
	x2 = GetDlgItem(hWnd, ID_EDIT_X2);
	y2 = GetDlgItem(hWnd, ID_EDIT_Y2);

	GetWindowText(x1, X, 5);
	GetWindowText(y1, Y, 5);
	Line.x1 = _wtoi(X);
	Line.y1 = _wtoi(Y);

	GetWindowText(x2, X, 5);
	GetWindowText(y2, Y, 5);
	Line.x2 = _wtoi(X);
	Line.y2 = _wtoi(Y);

	return Line;
}

void init_edit_fields()
{
	CreateWindowW(TEXT("static"), TEXT(" X1:            Y1:            X2:            Y2:"),
		WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
		15, 15, 280, 25,
		hWnd, NULL,
		hInst, NULL);

	CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("96"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		45, 17, 30, 20,
		hWnd, (HMENU)ID_EDIT_X1, NULL, NULL);

	CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("48"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		115, 17, 30, 20,
		hWnd, (HMENU)ID_EDIT_Y1, NULL, NULL);

	CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("861"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		185, 17, 30, 20,
		hWnd, (HMENU)ID_EDIT_X2, NULL, NULL);

	CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("433"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		255, 17, 30, 20,
		hWnd, (HMENU)ID_EDIT_Y2, NULL, NULL);


	CreateWindowW(TEXT("static"), TEXT(" Angle:"),
		WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
		650, 15, 90, 25,
		hWnd, NULL,
		hInst, NULL);

	CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("15"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		700, 17, 30, 20,
		hWnd, (HMENU)ID_EDIT_ANGLE, NULL, NULL);
}

void init_colorpick(scene sceneSettings)
{

	SelectObject(sceneSettings.hdc, CreatePen(PS_SOLID, 1, 0x00000000));
	SelectObject(sceneSettings.hdc, CreateSolidBrush(sceneSettings.ln_color));

	Rectangle(
		sceneSettings.hdc,
		15, 610,
		50, 633);

	SelectObject(sceneSettings.hdc, CreatePen(PS_SOLID, 1, 0x00000000));
	SelectObject(sceneSettings.hdc, CreateSolidBrush(sceneSettings.bg_color));

	Rectangle(
		sceneSettings.hdc,
		15, 643,
		50, 666);

}

void init_combobox()
{
	CB settings = {
		305, 15, 160, 250,
		5,
		{ 
			TEXT("Standart"),
			TEXT("Integer Bresenham's"), 
			TEXT("Double Bresenham's"), 
			TEXT("Bresenham's no steps"),
			TEXT("CDA"),
		}
	};
	createCB(hWnd, settings);
}

void init_buttons()
{
	CreateWindowW(TEXT("BUTTON"), TEXT("Choose line color"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		60, 610, 120, 23,
		hWnd, (HMENU)ID_BUTTON_LCOLOR, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Choose bg color"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		60, 643, 120, 23,
		hWnd, (HMENU)ID_BUTTON_BCOLOR, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Draw line"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		475, 15, 100, 23,
		hWnd, (HMENU)ID_BUTTON_DRAW, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Draw sun"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		750, 15, 100, 23,
		hWnd, (HMENU)ID_BUTTON_SUN, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Clear scene"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		895, 610, 120, 23,
		hWnd, (HMENU)ID_BUTTON_CLEAR, hInst, NULL);
}