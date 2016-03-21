#include "stdafx.h"
#include "listener.h"
#include "interface.h"
#include "planner.h"
#include "model.h"
#include "loadmodel.h"

extern HINSTANCE hInst;
extern struct view View;
extern HWND hWnd;

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
	int error = OK;
	NMHDR *childNotification;
	WORD KEY_CODE;

	switch (message)
	{
	case WM_COMMAND:
	case WM_KEYDOWN:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDM_OPEN:
			View.Model.fileName = get_model_name();
			if (View.Model.fileName)
			{
				doit(LOAD, &View);
				doit(DRAW, &View);
			}
			break;
		case ID_BUTTON_ROTATE_UP:
		case VK_UP:
			View.Modification.type = ROTATE_XZ;
			View.Modification.param = 5;
			doit(MODIFY, &View);
			doit(DRAW, &View);
			break;
		case ID_BUTTON_ROTATE_DOWN:
		case VK_DOWN:
			View.Modification.type = ROTATE_XZ;
			View.Modification.param = -5;
			doit(MODIFY, &View);
			doit(DRAW, &View);
			break;
		case ID_BUTTON_ROTATE_LEFT:
		case VK_LEFT:
			View.Modification.type = ROTATE_XY;
			View.Modification.param = -5;
			doit(MODIFY, &View);
			doit(DRAW, &View);
			break;
		case ID_BUTTON_ROTATE_RIGHT:
		case VK_RIGHT:
			View.Modification.type = ROTATE_XY;
			View.Modification.param = 5;
			doit(MODIFY, &View);
			doit(DRAW, &View);
			break;
		case ID_BUTTON_ZOOM_IN:
			View.Modification.type = ZOOM;
			View.Modification.param = 1.5;
			doit(MODIFY, &View);
			doit(DRAW, &View);
			break;
		case ID_BUTTON_ZOOM_OUT:
			View.Modification.type = ZOOM;
			View.Modification.param = 0.7;
			doit(MODIFY, &View);
			doit(DRAW, &View);
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
		switch (error)
		{
		
		}
		SetFocus(hWnd);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

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