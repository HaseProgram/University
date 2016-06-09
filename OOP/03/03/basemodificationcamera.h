#pragma once

/*!
\brief  Base modification for any camera
\author Dmitry Zaitsev
\version 1.0
\date 04 June 2016

Set base interface for camera modification
*/

#define _USE_MATH_DEFINES
#include <cmath>

class Point;

class BaseModificationCamera
{
public:
	BaseModificationCamera() {};
	~BaseModificationCamera() {};

	virtual void pitch(double) = 0;
	virtual void yaw(double) = 0;
	virtual void roll(double) = 0;

	virtual void rotateVerticalSphere(double) = 0;
	virtual void rotateHorizontalSphere(double) = 0;

	virtual void run(Point* point) = 0;
};