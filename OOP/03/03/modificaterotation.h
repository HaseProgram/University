#pragma once

/*!
\brief  Rotate modification for any object
\author Dmitry Zaitsev
\version 1.0
\date 04 June 2016

Provide rotation
*/

#include "basemodificationobject.h"
#include "point.h"

class BaseRotate : public BaseModificationObject
{
public:

	void modificateX(Point*);
	void modificateY(Point*);
	void modificateZ(Point*);

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

