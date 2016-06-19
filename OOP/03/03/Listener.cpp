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

double angle = 5;
double deltac = 1.2;
double deltaf = 0.8;
double shift = 5;
Point center(0,0,0);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	WORD KEY_CODE;

	struct tscene sc
	{
		50, 50, 600, 1200, RGB(240, 240, 240), GetDC(hWnd)
	};

	static Application* app = new Application();
	static BaseSystemDrawer* SD = new SystemDrawer(sc);
	static Draw* drawcommand = new Draw(SD);

	switch (message)
	{
	case WM_COMMAND:
	case WM_KEYDOWN:
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
			app->Call(*drawcommand,0);
		}
		break;
		case ID_BUTTON_CAMERA_APPLY:
		{
			// scenemanager->camera->set
		}
		break;
		// Next are object rotations
		case 65: // A
		{
			ModificateRotateY* rotycommand = new ModificateRotateY(angle,center);
			app->Call(*rotycommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 68: // D
		{
			ModificateRotateY* rotycommand = new ModificateRotateY(-angle, center);
			app->Call(*rotycommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 87: // W
		{
			ModificateRotateX* rotxcommand = new ModificateRotateX(angle, center);
			app->Call(*rotxcommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 83: // S
		{
			ModificateRotateX* rotxcommand = new ModificateRotateX(-angle, center);
			app->Call(*rotxcommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 81: // Q
		{
			ModificateRotateZ* rotzcommand = new ModificateRotateZ(-angle, center);
			app->Call(*rotzcommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 69: // E
		{
			ModificateRotateZ* rotzcommand = new ModificateRotateZ(angle, center);
			app->Call(*rotzcommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		// Next are object scale
		case 67: // C
		{
			ModificateScale* scalecommand = new ModificateScale(deltac,center);
			app->Call(*scalecommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 70: // F
		{
			ModificateScale* scalecommand = new ModificateScale(deltaf,center);
			app->Call(*scalecommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		// Next are object move
		case VK_LEFT: // <-
		{
			ModificateMoveX* movxcommand = new ModificateMoveX(-shift);
			app->Call(*movxcommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case VK_RIGHT: // ->
		{
			ModificateMoveX* movxcommand = new ModificateMoveX(shift);
			app->Call(*movxcommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case VK_UP:
		{
			ModificateMoveY* movycommand = new ModificateMoveY(-shift);
			app->Call(*movycommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case VK_DOWN: 
		{
			ModificateMoveY* movycommand = new ModificateMoveY(shift);
			app->Call(*movycommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 96: // 0 NUMPAD
		{
			ModificateMoveZ* movzcommand = new ModificateMoveZ(-shift);
			app->Call(*movzcommand, 0);
			app->Call(*drawcommand, 0);
		}
		break;
		case 109: // . NUMPAD
		{
			ModificateMoveZ* movzcommand = new ModificateMoveZ(shift);
			app->Call(*movzcommand, 0);
			app->Call(*drawcommand, 0);
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