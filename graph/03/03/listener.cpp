#include "stdafx.h"
#include "listener.h"
#include "draw.h"
#include "interface.h"
#include "combobox.h"

extern HINSTANCE hInst;
extern HWND hWnd;
BOOL flag = TRUE;
//
// FUNCTION: WndProc (HWND, UINT, WPARAM, LPARAM)
//
// PURPOSE: Process the message in the main window.
//
// WM_COMMAND - process the application menu
// WM_PAINT - draw the main window
// WM_DESTROY - send a message to exit and return
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	static scene sceneSettings;

	sceneSettings.hdc = GetDC(hWnd);
	sceneSettings.x = 15;
	sceneSettings.y = 50;
	sceneSettings.height = 550;
	sceneSettings.width = 1000;

	if (flag)
	{
		sceneSettings.bg_color = 0xFFFFFF;
		sceneSettings.ln_color = 0x48333A;
		flag = FALSE;
	}

	PAINTSTRUCT ps;
	HDC hdc;

	int cbIndex;
	HWND angleHWND;
	int angle;
	line Line;

	TCHAR BUF[5];


	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case ID_BUTTON_DRAW:
			cbIndex = getCurrentItem(GetDlgItem(hWnd,ID_COMBO));
			Line = get_line();
			reverse_y(&Line, sceneSettings.height);
			replace_xy(&Line, sceneSettings.x, sceneSettings.y);
			draw(cbIndex, sceneSettings, Line);
			break;
		case ID_BUTTON_SUN:
			cbIndex = getCurrentItem(GetDlgItem(hWnd, ID_COMBO));
			angleHWND = GetDlgItem(hWnd, ID_EDIT_ANGLE);
			GetWindowText(angleHWND, BUF, 5);
			angle = _wtoi(BUF);
			draw_sun(cbIndex, angle, sceneSettings);
			break;
		case ID_BUTTON_LCOLOR:
			color_dialog(&sceneSettings, TRUE);
			init_colorpick(sceneSettings);
			break;
		case ID_BUTTON_BCOLOR:
			color_dialog(&sceneSettings, FALSE);
			init_colorpick(sceneSettings);
			break;
		case ID_BUTTON_CLEAR:
			init_container(&sceneSettings);
			break;
		case IDM_ABOUT:
			DialogBoxW(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		SetFocus(hWnd);
	}
	break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		init_container(&sceneSettings);
		init_colorpick(sceneSettings);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for the "About" window.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}