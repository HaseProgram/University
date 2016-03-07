#pragma once

#define ID_EDITBEGINX 500

typedef struct {
	int XPos;
	int YPos;
	int Width;
	int Height;
	int ID;
} EDIT;

void createEditField(HWND hWnd, EDIT settings);
TCHAR* valueFromTextField(HWND hWnd, int ID);