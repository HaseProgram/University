#include "stdafx.h"
#include "listener.h"
#include "interface.h"
#include "ui.h"
#include "application.h"
#include "fileloader.h"
#include "drawer.h"

extern HINSTANCE hInst;
extern HWND hWnd;

PAINTSTRUCT ps;
HDC hdc;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	struct tscene sc
	{
		50, 50, 600, 1200, RGB(0, 255, 255), GetDC(hWnd)
	};

	static Application* app = new Application();
	static BaseSystemDrawer* SD = new SystemDrawer(sc);

	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);

		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_OPEN:
		{
			OpenDialog dialog;
			Load* loadcommand = new Load(dialog.getfilename());
			app->Call(*loadcommand,0);



			Draw* drawcommand = new Draw(SD);
			app->Call(*drawcommand,0);
		}
			break;
		case ID_BUTTON_CAMERA_APPLY:
		{
			// scenemanager->camera->set
		}
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_CREATE:
	{
		WInterface wInterface(hWnd, hInst);
		btnedtUi();
	}
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		PInterface pInterface(hdc);
		textUi();
		pInterface.~PInterface();

		Draw* drawcommand = new Draw(SD);
		app->Call(*drawcommand, 0);

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