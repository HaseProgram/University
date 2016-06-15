#pragma once

/*!
\brief  Point object
\author Dmitry Zaitsev
\version 2.0
\date 21 May 2016

Set point using this class
*/

#include "baseobject.h"
#include "array.h"

class Point : public BaseObject
{
public:
	Point();
	Point(double X, double Y, double Z);

	~Point();

	void setX(double newX);
	void setY(double newY);
	void setZ(double newZ);

	double getX();
	double getY();
	double getZ();

	Array<double> vector();

	virtual void modificate(BaseModificationObject*) override;

private:
	double X;
	double Y;
	double Z;
};