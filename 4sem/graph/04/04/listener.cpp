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

	int cbIndex;

	static scene sceneSettings = init_scene(hWnd);
	params parameters;

	PAINTSTRUCT ps;
	HDC hdc;
	
	HWND bufHWND;
	TCHAR buf[5];

	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case ID_BUTTON_DRAW_ELLIPSE:
			cbIndex = getCurrentItem(GetDlgItem(hWnd, ID_COMBO_ELLIPSE));

			bufHWND = GetDlgItem(hWnd, ID_EDIT_ELLIPSE_CENTER_X);
			GetWindowText(bufHWND, buf, 5);
			parameters.centerX = _wtoi(buf);

			bufHWND = GetDlgItem(hWnd, ID_EDIT_ELLIPSE_CENTER_Y);
			GetWindowText(bufHWND, buf, 5);
			parameters.centerY = _wtoi(buf);

			bufHWND = GetDlgItem(hWnd, ID_EDIT_ELLIPSE_HEIGHT);
			GetWindowText(bufHWND, buf, 5);
			parameters.height = _wtoi(buf);

			bufHWND = GetDlgItem(hWnd, ID_EDIT_ELLIPSE_WIDTH);
			GetWindowText(bufHWND, buf, 5);
			parameters.width = _wtoi(buf);

			draw(ELLIPSE, parameters, cbIndex, sceneSettings);
			break;
		case ID_BUTTON_DRAW_CIRCLE:
			cbIndex = getCurrentItem(GetDlgItem(hWnd, ID_COMBO_CIRCLE));

			bufHWND = GetDlgItem(hWnd, ID_EDIT_CIRCLE_CENTER_X);
			GetWindowText(bufHWND, buf, 5);
			parameters.centerX = _wtoi(buf);

			bufHWND = GetDlgItem(hWnd, ID_EDIT_CIRCLE_CENTER_Y);
			GetWindowText(bufHWND, buf, 5);
			parameters.centerY = _wtoi(buf);

			bufHWND = GetDlgItem(hWnd, ID_EDIT_CIRCLE_RADIUS);
			GetWindowText(bufHWND, buf, 5);
			parameters.radiusMin = _wtoi(buf);
			parameters.radiusMax = _wtoi(buf);

			draw(CIRCLE, parameters, cbIndex, sceneSettings);
			break;
		case ID_BUTTON_DRAW_SPEKTRE:
			cbIndex = getCurrentItem(GetDlgItem(hWnd, ID_COMBO_SPEKTRE));

			bufHWND = GetDlgItem(hWnd, ID_EDIT_SPEKTRE_RADIUS_MIN);
			GetWindowText(bufHWND, buf, 5);
			parameters.radiusMin = _wtoi(buf);

			bufHWND = GetDlgItem(hWnd, ID_EDIT_SPEKTRE_RADIUS_MAX);
			GetWindowText(bufHWND, buf, 5);
			parameters.radiusMax = _wtoi(buf);

			bufHWND = GetDlgItem(hWnd, ID_EDIT_SPEKTRE_RADIUS_STEP);
			GetWindowText(bufHWND, buf, 5);
			parameters.radiusStep = _wtoi(buf);

			draw(SPEKTRE, parameters, cbIndex, sceneSettings);
			break;
		case ID_BUTTON_CLEAR:
			draw_scene(sceneSettings);
			break;
		case ID_BUTTON_LCOLOR:
			change_color(&sceneSettings, TRUE);
			break;
		case ID_BUTTON_BCOLOR:
			change_color(&sceneSettings, FALSE);
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
		draw_scene(sceneSettings);
		init_colorpick(sceneSettings);
		init_text(sceneSettings);
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