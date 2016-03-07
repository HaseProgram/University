#pragma once

#define ID_EDITBEGINX 500

typedef struct {
	int XPos;
	int YPos;
	int Width;
	int Height;
	int ID;
} EDIT;

void createEditField(EDIT settings);
TCHAR* valueFromTextField(int ID, TCHAR buf[10]);