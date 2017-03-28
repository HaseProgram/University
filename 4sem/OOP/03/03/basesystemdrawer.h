#pragma once

/*!
\brief  System draw base class
\author Dmitry Zaitsev
\version 1.0
\date 21 May 2016

Interface for system drawing
*/

#include "point.h"

struct tscene
{
	int x;
	int y;
	int height;
	int width;
	COLORREF color;
	HDC hdc;
};

struct tpen
{
	int style;
	int width;
	COLORREF color;
};

class BaseSystemDrawer
{
public:
	virtual void drawline(Point, Point) = 0;
	virtual void clearscene() = 0;
	virtual void setpencolor(int, int, int) = 0;
	virtual void setpenwidth(int) = 0;
};