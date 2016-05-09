#include "stdafx.h"
#include "ui.h"
#include "interface.h"

void textUi()
{
	Text(TEXT("Set camera: X:         Y:"), 10, 10);
}

void btnedtUi()
{
	HFONT hfont;
	hfont = CreateFont(18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));

	Edit xEdit(TEXT("0"), ID_EDIT_CAMERA_X, 155, 10, 25, 40);
	SendMessage(xEdit.getById(ID_EDIT_CAMERA_X), WM_SETFONT, (WPARAM)hfont, 0);

	Edit yEdit(TEXT("0"), ID_EDIT_CAMERA_Y, 230, 10, 25, 40);
	SendMessage(xEdit.getById(ID_EDIT_CAMERA_Y), WM_SETFONT, (WPARAM)hfont, 0);

	Button cButton(TEXT("Apply"), ID_BUTTON_CAMERA_APPLY, 280, 10, 25, 60);
}