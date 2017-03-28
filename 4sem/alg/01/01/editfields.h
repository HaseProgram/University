#pragma once

#define ID_EDITBEGINX 507
#define ID_POLYNOM 508
#define ID_SEARCHX 509

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