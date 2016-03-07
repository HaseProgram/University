#pragma once

#define ID_EDITBEGINX 500
#define ID_PALENOM 500

typedef struct {
	int XPos;
	int YPos;
	int WidthT;
	int WidthF;
	int Height;
	TCHAR* Name;
	int ID;
} EDIT;

void createEditField(EDIT settings);
TCHAR* valueFromTextField(int ID, TCHAR buf[10]);