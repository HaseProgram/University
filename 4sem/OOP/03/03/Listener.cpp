#include "stdafx.h"
#include "listener.h"
#include "interface.h"
#include "ui.h"
#include "application.h"
#include "fileloader.h"
#include "drawer.h"

extern HINSTANCE hInst;
//extern HWND hWnd;

PAINTSTRUCT ps;
HDC hdc;

double angle = 5;
double cangle = 0.1;
double mcangle = 0.005;
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

	try
	{
		static Application* app = new Application();
		if (!app)
		{
			throw AllocationMemoryError();
		}

		static BaseSystemDrawer* SD = new SystemDrawer(sc);
		if (!SD)
		{
			delete app;
			app = nullptr;
			throw AllocationMemoryError();
		}

		static Draw* drawcommand = new Draw(SD);
		if (!drawcommand)
		{
			delete app;
			app = nullptr;
			delete SD;
			SD = nullptr;
			throw AllocationMemoryError();
		}

		try
		{
			switch (message)
			{
			case WM_COMMAND:
			case WM_KEYDOWN:
			{
				int wmId = LOWORD(wParam);

				switch (wmId)
				{
				case IDM_OPEN:
				{
					OpenDialog dialog;
					Load* loadcommand = new Load(dialog.getfilename());
					if (!loadcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*loadcommand, 0);

					Point* point1 = new Point(10, 10, 50);
					if (!point1)
					{
						throw AllocationMemoryError();
					}

					Point* point2 = new Point(10, 10, 10);
					if (!point2)
					{
						throw AllocationMemoryError();
					}

					LoadCamera* loadcameracommand = new LoadCamera(point1, point2);
					if (!loadcameracommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*loadcameracommand, 0);

					app->Call(*drawcommand, 0);
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
					ModificateRotateY* rotycommand = new ModificateRotateY(angle, center);
					if (!rotycommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotycommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 68: // D
				{
					ModificateRotateY* rotycommand = new ModificateRotateY(-angle, center);
					if (!rotycommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotycommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 87: // W
				{
					ModificateRotateX* rotxcommand = new ModificateRotateX(angle, center);
					if (!rotxcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotxcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 83: // S
				{
					ModificateRotateX* rotxcommand = new ModificateRotateX(-angle, center);
					if (!rotxcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotxcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 81: // Q
				{
					ModificateRotateZ* rotzcommand = new ModificateRotateZ(-angle, center);
					if (!rotzcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotzcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 69: // E
				{
					ModificateRotateZ* rotzcommand = new ModificateRotateZ(angle, center);
					if (!rotzcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotzcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				// Next are object scale
				case 67: // C
				{
					ModificateScale* scalecommand = new ModificateScale(deltac, center);
					if (!scalecommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*scalecommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 70: // F
				{
					ModificateScale* scalecommand = new ModificateScale(deltaf, center);
					if (!scalecommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*scalecommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				// Next are object move
				case VK_LEFT: // <-
				{
					ModificateMoveX* movxcommand = new ModificateMoveX(-shift);
					if (!movxcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*movxcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case VK_RIGHT: // ->
				{
					ModificateMoveX* movxcommand = new ModificateMoveX(shift);
					if (!movxcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*movxcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case VK_UP:
				{
					ModificateMoveY* movycommand = new ModificateMoveY(-shift);
					if (!movycommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*movycommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case VK_DOWN:
				{
					ModificateMoveY* movycommand = new ModificateMoveY(shift);
					if (!movycommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*movycommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 96: // 0 NUMPAD
				{
					ModificateMoveZ* movzcommand = new ModificateMoveZ(-shift);
					if (!movzcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*movzcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 109: // . NUMPAD
				{
					ModificateMoveZ* movzcommand = new ModificateMoveZ(shift);
					if (!movzcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*movzcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				// Next are camera modifications
				case 104: // 8 NUMPAD
				{
					ModificateCameraPitch* pitchcommand = new ModificateCameraPitch(cangle);
					if (!pitchcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*pitchcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 98: // 2 NUMPAD
				{
					ModificateCameraPitch* pitchcommand = new ModificateCameraPitch(-cangle);
					if (!pitchcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*pitchcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 100: // 4 NUMPAD
				{
					ModificateCameraYaw* yawcommand = new ModificateCameraYaw(cangle);
					if (!yawcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*yawcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 102: // 6 NUMPAD
				{
					ModificateCameraYaw* yawcommand = new ModificateCameraYaw(-cangle);
					if (!yawcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*yawcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 103: // 7 NUMPAD
				{
					ModificateCameraRotateVerticalSphere* rotcommand = new ModificateCameraRotateVerticalSphere(mcangle);
					if (!rotcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 105: // 9 NUMPAD
				{
					ModificateCameraRotateVerticalSphere* rotcommand = new ModificateCameraRotateVerticalSphere(-mcangle);
					if (!rotcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 97: // 1 NUMPAD
				{
					ModificateCameraRotateHorizontalSphere* rotcommand = new ModificateCameraRotateHorizontalSphere(mcangle);
					if (!rotcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotcommand, 0);
					app->Call(*drawcommand, 0);
				}
				break;
				case 99: // 3 NUMPAD
				{
					ModificateCameraRotateHorizontalSphere* rotcommand = new ModificateCameraRotateHorizontalSphere(-mcangle);
					if (!rotcommand)
					{
						throw AllocationMemoryError();
					}
					app->Call(*rotcommand, 0);
					app->Call(*drawcommand, 0);
				}
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
				HWND test = GetDlgItem(hWnd, 13223123);
			}
			case WM_PAINT:
			{
				hdc = BeginPaint(hWnd, &ps);
				PInterface pInterface(hdc);
				textUi();

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
		}
		catch (BaseException& exception)
		{
			delete app;
			app = nullptr;
			delete SD;
			SD = nullptr;
			delete drawcommand;
			drawcommand = nullptr;
			throw;
		}
	}
	catch (BaseException &exception)
	{
		WCHAR msg[256];
		MultiByteToWideChar(0, 0, exception.what(), 255, msg, 256);
		MessageBox(NULL, msg, TEXT("ERROR"), MB_OK);
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