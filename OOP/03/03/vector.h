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
	Vector(const Vector& cvector);
	Vector(Array<double> arr);
	Vector(double, double, double);
	~Vector();

	Array<double> getArray();

	void setX(double);
	void setY(double);
	void setZ(double);
	void setL(double);

	double getX() const;
	double getY() const;
	double getZ() const;
	double getL() const;

	double operator[](int);
	
	double length();
	static double scalar(Vector, Vector);
	double angle(Vector, Vector);

	Vector normalize();
	static Vector cross(Vector, Vector); 

	Vector& operator=(Array<double>&);
	Vector& operator=(Array<double>&&);

private:
	Array<double> v;
};