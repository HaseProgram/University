#pragma once
#include <windowsx.h>
#include <CommCtrl.h>

#define ID_COMBO 5500

typedef struct {
	int XPos;
	int YPos;
	int Width;
	int Height;
	int itemAmount;
	WCHAR* itemName[100];
} CB;

HWND createCB(HWND hWnd, CB settings);
void addItem(HWND hwndComboBox, WCHAR* item);
int getCurrentItem(HWND hWnd);