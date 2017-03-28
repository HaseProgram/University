#include "stdafx.h"
#include "draw.h"
#include "interface.h"
#include "combobox.h"

extern HWND hWnd;
extern HINSTANCE hInst;

scene init_scene(HWND hWnd)
{
	scene settings = {
		GetDC(hWnd),
		15,
		15,
		550,
		1000,
		0xFFFFFF,
		0x48333A
	};
	return settings;
}

void draw_scene(scene sceneSettings)
{
	SelectObject(sceneSettings.hdc, CreatePen(PS_SOLID, 1, 0x00000000));
	SelectObject(sceneSettings.hdc, CreateSolidBrush(sceneSettings.bg_color));

	Rectangle(
		sceneSettings.hdc,
		sceneSettings.x, sceneSettings.y,
		sceneSettings.x + sceneSettings.width, sceneSettings.y + sceneSettings.height);
}

void init_buttons()
{

	CreateWindowW(TEXT("BUTTON"), TEXT("Draw"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		1277, 135, 60, 23,
		hWnd, (HMENU)ID_BUTTON_DRAW_ELLIPSE, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Draw"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		1277, 285+50, 60, 23,
		hWnd, (HMENU)ID_BUTTON_DRAW_CIRCLE, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Draw"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		1277, 435+100, 60, 23,
		hWnd, (HMENU)ID_BUTTON_DRAW_SPEKTRE, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Choose line color"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		60, 575, 120, 23,
		hWnd, (HMENU)ID_BUTTON_LCOLOR, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Choose bg color"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		60, 603, 120, 23,
		hWnd, (HMENU)ID_BUTTON_BCOLOR, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Clear scene"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		895, 580, 120, 23,
		hWnd, (HMENU)ID_BUTTON_CLEAR, hInst, NULL);
}

void init_colorpick(scene sceneSettings)
{
	SelectObject(sceneSettings.hdc, CreatePen(PS_SOLID, 1, 0x00000000));
	SelectObject(sceneSettings.hdc, CreateSolidBrush(sceneSettings.ln_color));

	Rectangle(
		sceneSettings.hdc,
		15, 575,
		50, 598);

	SelectObject(sceneSettings.hdc, CreateSolidBrush(sceneSettings.bg_color));

	Rectangle(
		sceneSettings.hdc,
		15, 603,
		50, 626);
}

void change_color(scene* sceneSettings, BOOL flag)
{
	CHOOSECOLOR cc = { 0 };
	cc.lStructSize = sizeof(cc);
	COLORREF cust_colors[16] = { 0 };
	cc.lpCustColors = cust_colors;

	if (ChooseColor(&cc)) {
		if (flag)
			sceneSettings->ln_color = cc.rgbResult;
		else
			sceneSettings->bg_color = cc.rgbResult;
	}
	init_colorpick(*sceneSettings);
}

void init_font(LOGFONT* font)
{
	font->lfHeight = 25;
	font->lfWidth = 0;
	font->lfEscapement = 0;
	font->lfOrientation = 0;
	font->lfWeight = 500;
	font->lfItalic = 0;
	font->lfUnderline = 0;
	font->lfStrikeOut = 0;
	font->lfCharSet = RUSSIAN_CHARSET;
	font->lfOutPrecision = 0;
	font->lfClipPrecision = 0;
	font->lfQuality = 0;
	font->lfPitchAndFamily = 0;
	wcscpy(font->lfFaceName, TEXT("Arial"));
}

void init_text(scene sceneSettings)
{

	LOGFONT font;
	init_font(&font);
	

	HFONT hfont;
	hfont = ::CreateFontIndirect(&font);

	SelectObject(sceneSettings.hdc, hfont);

	TCHAR* out;
	
	////////////////////

	out = TEXT("Elipse:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 15, 15,
		out, wcslen(out));

	MoveToEx(sceneSettings.hdc, sceneSettings.x + sceneSettings.width + 15, 40, NULL);
	LineTo(sceneSettings.hdc, sceneSettings.x + sceneSettings.width + 355, 40);

	///////////////////

	out = TEXT("Circle:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 15, 165+50,
		out, wcslen(out));

	MoveToEx(sceneSettings.hdc, sceneSettings.x + sceneSettings.width + 15, 190+50, NULL);
	LineTo(sceneSettings.hdc, sceneSettings.x + sceneSettings.width + 355, 190+50);

	///////////////////

	out = TEXT("Circle spectre:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 15, 315+100,
		out, wcslen(out));

	MoveToEx(sceneSettings.hdc, sceneSettings.x + sceneSettings.width + 15, 340+100, NULL);
	LineTo(sceneSettings.hdc, sceneSettings.x + sceneSettings.width + 355, 340+100);

	//////////////////////////////////////////////////////////////////////////////////////


	font.lfHeight = 18;
	hfont = ::CreateFontIndirect(&font);
	SelectObject(sceneSettings.hdc, hfont);

	///////////////////

	out = TEXT("Center X:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 50, 55,
		out, wcslen(out));

	out = TEXT("Center Y:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 200, 55,
		out, wcslen(out));

	out = TEXT("Height:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 65, 95,
		out, wcslen(out));

	out = TEXT("Width:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 218, 95,
		out, wcslen(out));

	///////////////////

	out = TEXT("Center X:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 50, 205+50,
		out, wcslen(out));

	out = TEXT("Center Y:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 200, 205+50,
		out, wcslen(out));

	out = TEXT("Radius:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 210, 245+50,
		out, wcslen(out));

	///////////////////

	out = TEXT("Min radius:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 45, 355+100,
		out, wcslen(out));

	out = TEXT("Max radius:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 195, 355+100,
		out, wcslen(out));

	out = TEXT("Radius step:");
	TextOutW(sceneSettings.hdc,
		sceneSettings.x + sceneSettings.width + 187, 395+100,
		out, wcslen(out));

}

void init_editfields()
{
	HWND edit;
	HFONT hfont;
	hfont = CreateFont(18,0,0,0,0,0,0,0,0,0,0,0,0,TEXT("Arial"));

	///////////////////

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("513"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 130, 53, 40, 25,
		hWnd, (HMENU)ID_EDIT_ELLIPSE_CENTER_X, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("290"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 280, 53, 40, 25,
		hWnd, (HMENU)ID_EDIT_ELLIPSE_CENTER_Y, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("523"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 130, 93, 40, 25,
		hWnd, (HMENU)ID_EDIT_ELLIPSE_HEIGHT, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("977"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 280, 93, 40, 25,
		hWnd, (HMENU)ID_EDIT_ELLIPSE_WIDTH, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	///////////////////

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("542"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 130, 203+50, 40, 25,
		hWnd, (HMENU)ID_EDIT_CIRCLE_CENTER_X, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("290"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 280, 203+50, 40, 25,
		hWnd, (HMENU)ID_EDIT_CIRCLE_CENTER_Y, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("261"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 280, 243+50, 40, 25,
		hWnd, (HMENU)ID_EDIT_CIRCLE_RADIUS, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	///////////////////

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("29"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 130, 353+100, 40, 25,
		hWnd, (HMENU)ID_EDIT_SPEKTRE_RADIUS_MIN, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("261"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 280, 353+100, 40, 25,
		hWnd, (HMENU)ID_EDIT_SPEKTRE_RADIUS_MAX, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);

	edit = CreateWindowExW(WS_EX_WINDOWEDGE, TEXT("Edit"), TEXT("15"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		1015 + 280, 393+100, 40, 25,
		hWnd, (HMENU)ID_EDIT_SPEKTRE_RADIUS_STEP, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)hfont, 0);


}

void init_combobox()
{
	CB settings;

	settings = {
		1065, 135, 120, 250,
		3,
		{
			TEXT("Parameters"),
			TEXT("Average point"),
			TEXT("Standart"),
		}
	};
	createCB(hWnd, settings, ID_COMBO_ELLIPSE);

	settings = {
		1065, 335, 120, 250,
		5,
		{
			TEXT("By equation"),
			TEXT("Parameters"),
			TEXT("Brezenhem`s"),
			TEXT("Average point"),
			TEXT("Standart"),
		}
	};
	createCB(hWnd, settings, ID_COMBO_CIRCLE);

	settings = {
		1065, 535, 120, 250,
		5,
		{
			TEXT("By equation"),
			TEXT("Parameters"),
			TEXT("Brezenhem`s"),
			TEXT("Average point"),
			TEXT("Standart"),
		}
	};
	createCB(hWnd, settings, ID_COMBO_SPEKTRE);
}