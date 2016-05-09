#pragma once

/*!
\brief  Interaction with interface
\author Dmitry Zaitsev
\version 1.0
\date 09 May 2016

Creating edit fields, buttons, get/set values, text etc
*/

class WInterface
{
public:
	WInterface();
	WInterface(HWND hWnd, HINSTANCE hInst);
	~WInterface();
	HWND getById(int ID);

protected:
	static HWND hWnd;
	static HINSTANCE hInst;

};

class Button : public WInterface
{
private:
	int ID;
	int X;
	int Y;
	int HEIGHT;
	int WIDTH;
public:
	Button();
	Button(WCHAR* TEXT, int ID, int X, int Y, int HEIGHT, int WIDTH);
	~Button();
};

class Edit : public WInterface
{
private:
	int ID;
	int X;
	int Y;
	int HEIGHT;
	int WIDTH;
public:
	Edit();
	Edit(WCHAR* TEXT, int ID, int X, int Y, int HEIGHT, int WIDTH);
	~Edit();
	int getInt();
};

class PInterface
{
public:
	PInterface();
	PInterface(HDC hdc);
	~PInterface();

protected:
	static HDC hdc;
	static LOGFONT font;
};

class Text : public PInterface
{
private:
	int X;
	int Y;
public:
	Text();
	Text(WCHAR* TEXT, int X, int Y);
	~Text();
};