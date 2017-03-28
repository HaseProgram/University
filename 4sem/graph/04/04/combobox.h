#pragma once
#include <windowsx.h>
#include <CommCtrl.h>

typedef struct {
	int XPos;
	int YPos;
	int Width;
	int Height;
	int itemAmount;
	WCHAR* itemName[100];
} CB;

HWND createCB(HWND hWnd, CB settings, int comboID);
void addItem(HWND hwndComboBox, WCHAR* item);
int getCurrentItem(HWND hWnd);