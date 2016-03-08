// 01.cpp: defines the entry point for application.
//

#include "stdafx.h"
#include "01.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // The current instance
HWND hWnd;										// Main window
HWND hwndListView;								// List view
HWND hwndComboBox;								// Combo box
WCHAR szTitle[MAX_LOADSTRING];                  // Title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // Class name of the main window

values* Array;
int currentFunction;
int Polynom;
double SearchX;
double newtonY;
double RealY;
WCHAR out[256];

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

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY01, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    //  Initialize the application:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY01));

    MSG msg;

    // Main message loop:
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
// FUNCTION: MyRegisterClass ()
//
// PURPOSE: Register window class.
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
// FUNCTION: InitInstance (HINSTANCE, int)
//
// PURPOSE: Saves instance processing and creates the main window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Save the instance handle in a global variable

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   LV LVSettings = {
	   15,											// X position
	   45,											// Y position
	   210,											// width
	   500,											// height
	   3,											// amount of columns
	   { TEXT("N"), TEXT("X"), TEXT("Y") },			// name of columns
	   70											// width of column
   };

   hwndListView = createLV(LVSettings);

   CB CBSettings = {
	   15,											// X position
	   15,											// Y position
	   100,											// width
	   200,											// height
	   3,											// amount of items
	   { TEXT("sin"), TEXT("x^2"), TEXT("ln") },	// name of items
   };

   hwndComboBox = createCB(hWnd, CBSettings);

   EDIT EDITSettings;

   EDITSettings = {
	   125,											// X position
	   15,											// Y position
	   100,											// width text
	   40,											// width field
	   24,											// height
	   TEXT(" Start:"),								// Name
	   ID_EDITBEGINX								// Edit ID
   };

   createEditField(EDITSettings);

   EDITSettings = {
	   260,											// X position
	   15,											// Y position
	   100,											// width text
	   15,											// width field
	   24,											// height
	   TEXT(" Polynom:"),							// Name
	   ID_POLYNOM									// Edit ID
   };

   createEditField(EDITSettings);

   EDITSettings = {
	   370,											// X position
	   15,											// Y position
	   130,											// width text
	   45,											// width field
	   24,											// height
	   TEXT(" Search X:"),							// Name
	   ID_SEARCHX									// Edit ID
   };

   createEditField(EDITSettings);

   CreateWindowW(TEXT("BUTTON"), TEXT("Apply"),
	   WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 510, 15, 50, 24, hWnd, (HMENU)ID_BUTTONAPPLY, hInstance, NULL);

   Array = createSequence();

   TCHAR buf[10];
   SearchX = _wtof(valueFromTextField(ID_SEARCHX, buf));
   Polynom = _wtoi(valueFromTextField(ID_POLYNOM, buf));
   newtonY = newton_method(SearchX, Polynom);
   RealY = myFunc()(SearchX);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

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
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
			case ID_COMBO:
				if (HIWORD(wParam) == CBN_SELCHANGE)
				{
					currentFunction = getNewCurrentItem(lParam);
					createSequence();
				}
				break;
			case ID_EDITBEGINX:
				if (HIWORD(wParam) == EN_CHANGE)
				{
					createSequence();
				}
				break;
			case ID_BUTTONAPPLY:
				if (HIWORD(wParam) == BN_CLICKED)
				{
					TCHAR buf[10];
					SearchX = _wtof(valueFromTextField(ID_SEARCHX, buf));
					Polynom = _wtoi(valueFromTextField(ID_POLYNOM, buf));
					newtonY = newton_method(SearchX, Polynom);
					RealY = myFunc()(SearchX);
					InvalidateRect(hWnd, 0, true);
				}
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
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
			MoveToEx(hdc, 240, 15, NULL);
			LineTo(hdc, 240, 600);
			
			swprintf(out, L"Newton method:  %2.2f ; Real value: %2.2f", newtonY, RealY);
			TextOutW(hdc, 260, 50, out, wcslen(out));
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
