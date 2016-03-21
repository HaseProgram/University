#include "stdafx.h"
#include "interface.h"

extern HWND hWnd;
extern HINSTANCE hInst;

void initButtons()
{
	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate ↑"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 15 + 200, 100, 50, 
		hWnd, (HMENU)ID_BUTTON_ROTATE_UP, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate ←"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		15, 100 + 200, 100, 50,
		hWnd, (HMENU)ID_BUTTON_ROTATE_LEFT, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate →"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		260, 100 + 200, 100, 50,
		hWnd, (HMENU)ID_BUTTON_ROTATE_RIGHT, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate ↓"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 185 + 200, 100, 50,
		hWnd, (HMENU)ID_BUTTON_ROTATE_DOWN, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Zoom +"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 100 + 200, 100, 25,
		hWnd, (HMENU)ID_BUTTON_ZOOM_IN, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Zoom -"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 125 + 200, 100, 25,
		hWnd, (HMENU)ID_BUTTON_ZOOM_OUT, hInst, NULL);

}