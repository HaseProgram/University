#include "stdafx.h"
#include "interface.h"

HWND WInterface::hWnd;
HINSTANCE WInterface::hInst;

WInterface::WInterface()
{
}

WInterface::WInterface(HWND hWnd, HINSTANCE hInst)
{
	this->hWnd = hWnd;
	this->hInst = hInst;
}

WInterface::~WInterface()
{
}


HWND WInterface::getById(int ID)
{
	return GetDlgItem(this->hWnd, ID);
}

Button::Button()
{
}

Button::Button(WCHAR* TEXT, int ID, int X, int Y, int HEIGHT, int WIDTH)
{
	CreateWindowW(TEXT("BUTTON"), TEXT,
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		X, Y, WIDTH, HEIGHT,
		this->hWnd, (HMENU)ID, this->hInst, NULL);
}

Button::~Button()
{
	DestroyWindow(this->getById(this->ID));
}

Edit::Edit()
{
}

Edit::Edit(WCHAR* TEXT, int ID, int X, int Y, int HEIGHT, int WIDTH)
{
	CreateWindowW(TEXT("Edit"), TEXT,
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | WS_BORDER | ES_CENTER,
		X, Y, WIDTH, HEIGHT,
		this->hWnd, (HMENU)ID, this->hInst, NULL);
}

Edit::~Edit()
{
	DestroyWindow(this->getById(this->ID));
}

int Edit::getInt()
{
	HWND temp = this->getById(this->ID);
	TCHAR text[10];
	GetWindowText(temp, text, 10);
	return _wtoi(text);
}

HDC PInterface::hdc;
LOGFONT PInterface::font;

PInterface::PInterface()
{
}

PInterface::PInterface(HDC hdc)
{
	this->hdc = hdc;
	this->font.lfHeight = 25;
	this->font.lfWidth = 0;
	this->font.lfEscapement = 0;
	this->font.lfOrientation = 0;
	this->font.lfWeight = 500;
	this->font.lfItalic = 0;
	this->font.lfUnderline = 0;
	this->font.lfStrikeOut = 0;
	this->font.lfCharSet = RUSSIAN_CHARSET;
	this->font.lfOutPrecision = 0;
	this->font.lfClipPrecision = 0;
	this->font.lfQuality = 0;
	this->font.lfPitchAndFamily = 0;
	wcscpy_s(this->font.lfFaceName, TEXT("Arial"));
}

PInterface::~PInterface()
{
}

Text::Text()
{
}

Text::Text(WCHAR* TEXT, int X, int Y)
{
	HFONT hfont;
	hfont = ::CreateFontIndirect(&this->font);
	SelectObject(this->hdc, hfont);
	TextOutW(this->hdc, X, Y, TEXT, wcslen(TEXT));
}

Text::~Text()
{
}