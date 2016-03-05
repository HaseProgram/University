// 01.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "01.h"

struct clock cl;

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY01, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY01));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY01));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY01);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   HWND textMove = CreateWindowW(TEXT("static"), TEXT(" Move:    X:            Y:"),
	   WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
	   15, 15, 240, 36,
	   hWnd, NULL,
	   hInstance, NULL);
   HWND hwndEditMoveX = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 95, 23, 30, 20, hWnd, (HMENU)ID_EDIT_MOVEX, NULL, NULL);
   HWND hwndEditMoveY = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 155, 23, 30, 20, hWnd, (HMENU)ID_EDIT_MOVEY, NULL, NULL);
   HWND hwndButtonMove = CreateWindowW(TEXT("BUTTON"), TEXT("Apply"), 
	   WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 195, 23, 50, 20, hWnd, (HMENU)ID_BUTTON_MOVE, hInstance, NULL);


   HWND textScale = CreateWindowW(TEXT("static"), TEXT(" Scale:   Proportions:"),
	   WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
	   15, 66, 240, 30,
	   hWnd, NULL,
	   hInstance, NULL);
   HWND textScaleX = CreateWindowW(TEXT("static"), TEXT("                             X:"),
	   WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
	   15, 96, 240, 30,
	   hWnd, NULL,
	   hInstance, NULL);
   HWND textScaleY = CreateWindowW(TEXT("static"), TEXT("                             Y:"),
	   WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
	   15, 126, 240, 30,
	   hWnd, NULL,
	   hInstance, NULL);
   HWND hwndEditScaleProportions = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 155, 74, 30, 20, hWnd, (HMENU)ID_EDIT_SCALEPROPORTIONS, NULL, NULL);
   HWND hwndEditScaleX = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 155, 104, 30, 20, hWnd, (HMENU)ID_EDIT_SCALEX, NULL, NULL);
   HWND hwndEditScaleY = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 155, 134, 30, 20, hWnd, (HMENU)ID_EDIT_SCALEY, NULL, NULL);
   HWND hwndButtonScale = CreateWindowW(TEXT("BUTTON"), TEXT("Apply"),
	   WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 195, 74, 50, 20, hWnd, (HMENU)ID_BUTTON_SCALE, hInstance, NULL);


   HWND textRotate = CreateWindowW(TEXT("static"), TEXT(" Rotate:         Angle:"),
	   WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
	   15, 117 + 55, 240, 30,
	   hWnd, NULL,
	   hInstance, NULL);
   HWND textRotateX = CreateWindowW(TEXT("static"), TEXT("                             X:"),
	   WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
	   15, 147 + 55, 240, 30,
	   hWnd, NULL,
	   hInstance, NULL);
   HWND textRotateY = CreateWindowW(TEXT("static"), TEXT("                             Y:"),
	   WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_CENTERIMAGE,
	   15, 177 + 55, 240, 30,
	   hWnd, NULL,
	   hInstance, NULL);
   HWND hwndEditRotateAngle = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 155, 125 + 55, 30, 20, hWnd, (HMENU)ID_EDIT_ROTATEANGLE, NULL, NULL);
   HWND hwndEditRotateX = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 155, 155 + 55, 30, 20, hWnd, (HMENU)ID_EDIT_ROTATEX, NULL, NULL);
   HWND hwndEditRotateY = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("0"),
	   WS_CHILD | WS_VISIBLE | WS_BORDER, 155, 185 + 55, 30, 20, hWnd, (HMENU)ID_EDIT_ROTATEY, NULL, NULL);
   HWND hwndButtonRotate = CreateWindowW(TEXT("BUTTON"), TEXT("Apply"),
	   WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 195, 125 + 55, 50, 20, hWnd, (HMENU)ID_BUTTON_ROTATE, hInstance, NULL);


   HWND hwndButtonReset = CreateWindowW(TEXT("BUTTON"), TEXT("Reset"),
	   WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 15, 230 + 55, 50, 20, hWnd, (HMENU)ID_BUTTON_RESET, hInstance, NULL);


   initClock();

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND — обработать меню приложения
//  WM_PAINT — отрисовать главное окно
//  WM_DESTROY — отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND edit;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case ID_BUTTON_MOVE:
				if (HIWORD(wParam) == BN_CLICKED)
				{
					edit = GetDlgItem(hWnd,ID_EDIT_MOVEX);
					TCHAR X[5];
					TCHAR Y[5];
					GetWindowText(edit, X, 5);
					edit = GetDlgItem(hWnd, ID_EDIT_MOVEY);
					GetWindowText(edit, Y, 5);
					if (wcslen(X) != 0 && wcslen(Y) != 0)
					{
						moveClock(_wtof(X),_wtof(Y));
						InvalidateRect(hWnd, 0, true);
					}
				}
				break;
			case ID_BUTTON_SCALE:
				if (HIWORD(wParam) == BN_CLICKED)
				{
					TCHAR prop[5];
					TCHAR X[5];
					TCHAR Y[5];
					edit = GetDlgItem(hWnd, ID_EDIT_SCALEPROPORTIONS);
					GetWindowText(edit, prop, 5);
					edit = GetDlgItem(hWnd, ID_EDIT_SCALEX);
					GetWindowText(edit, X, 5);
					edit = GetDlgItem(hWnd, ID_EDIT_SCALEY);
					GetWindowText(edit, Y, 5);
					if (wcslen(prop) != 0 && wcslen(X) != 0 && wcslen(Y) != 0)
					{
						scaleClock(_wtof(prop), _wtof(X), _wtof(Y));
						InvalidateRect(hWnd, 0, true);
					}
				}
				break;
			case ID_BUTTON_ROTATE:
				if (HIWORD(wParam) == BN_CLICKED)
				{
					TCHAR X[5];
					TCHAR Y[5];
					TCHAR A[5];
					edit = GetDlgItem(hWnd, ID_EDIT_ROTATEX);
					GetWindowText(edit, X, 5);
					edit = GetDlgItem(hWnd, ID_EDIT_ROTATEY);
					GetWindowText(edit, Y, 5);
					edit = GetDlgItem(hWnd, ID_EDIT_ROTATEANGLE);
					GetWindowText(edit, A, 5);
					if (wcslen(X) != 0 && wcslen(Y) != 0 && wcslen(A) != 0)
					{
						rotateClock(_wtof(X), _wtof(Y), (_wtof(A) / 180.0)*3.14);
						InvalidateRect(hWnd, 0, true);
					}
				}
				break;
			case ID_BUTTON_RESET:
				if (HIWORD(wParam) == BN_CLICKED)
				{
					reset();
					InvalidateRect(hWnd, 0, true);
				}
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			draw(hdc);
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

// Обработчик сообщений для окна "О программе".
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
