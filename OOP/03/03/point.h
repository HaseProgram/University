#pragma once

/*!
\brief  Point object
\author Dmitry Zaitsev
\version 2.0
\date 21 May 2016

Set point using this class
*/

#include "baseobject.h"

class BasePoint : public BaseObject
{
public:

	virtual void setX(double) = 0;
	virtual void setY(double) = 0;
	virtual void setZ(double) = 0;

	virtual double getX() = 0;
	virtual double getY() = 0;
	virtual double getZ() = 0;

	virtual void modificate() = 0;
};

class Point : public BasePoint
{
public:
	Point();
	Point(double X, double Y, double Z);

	~Point();

	virtual void setX(double newX) override;
	virtual void setY(double newY) override;
	virtual void setZ(double newZ) override;

	virtual double getX() override;
	virtual double getY() override;
	virtual double getZ() override;

	virtual void modificate() override;

private:
	double X;
	double Y;
	double Z;
};