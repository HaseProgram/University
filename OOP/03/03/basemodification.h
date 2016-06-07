#pragma once

/*!
\brief  Base modification for any object
\author Dmitry Zaitsev
\version 1.0
\date 04 June 2016

Set base interface for object modification
*/

#define _USE_MATH_DEFINES
#include <cmath>

class Point;

class BaseModification
{
public:
	BaseModification() {};
	~BaseModification() {};

	virtual void modificateX(Point* point) = 0;
	virtual void modificateY(Point* point) = 0;
	virtual void modificateZ(Point* point) = 0;

	virtual void run(Point* point) = 0;
};