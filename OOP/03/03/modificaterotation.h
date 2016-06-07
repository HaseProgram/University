#pragma once

/*!
\brief  Rotate modification for any object
\author Dmitry Zaitsev
\version 1.0
\date 04 June 2016

Provide rotation
*/

#include "basemodification.h"
#include "point.h"

class BaseRotate : public BaseModification
{
public:

	virtual void modificateX(Point*) override;
	virtual void modificateY(Point*) override;
	virtual void modificateZ(Point*) override;

	virtual void run(Point*) = 0;

protected:
	double angle;
	Point* center;
};

class RotateX : public BaseRotate
{
public:
	RotateX();
	RotateX(double, Point);
	~RotateX();

	virtual void run(Point*) override;
};

class RotateY : public BaseRotate
{
public:
	RotateY();
	RotateY(double, Point);
	~RotateY();

	virtual void run(Point*) override;
};

class RotateZ : public BaseRotate
{
public:
	RotateZ();
	RotateZ(double, Point);
	~RotateZ();

	virtual void run(Point*) override;
};

