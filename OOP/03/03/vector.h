#pragma once

/*!
\brief  Geometric vector
\author Dmitry Zaitsev
\version 1.0
\date 08 June 2016

Vector as well. Required for camera setting and it's modification.
*/

#include "array.h"
#include "exceptionvector.h"
#include <cmath>

class Vector
{
public:
	Vector();
	Vector(double, double, double);
	~Vector();

	void setX(double);
	void setY(double);
	void setZ(double);
	void setL(double);
	
	double length();
	double scalar(Vector, Vector);
	double angle(Vector, Vector);

	Vector normalize();
	Vector cross(Vector, Vector);

	Vector& operator=(Array<double>&);
	Vector& operator=(Array<double>&&);

private:
	Array<double> v;
};