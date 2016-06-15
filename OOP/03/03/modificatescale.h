#pragma once

/*!
\brief  Scale modification for any object
\author Dmitry Zaitsev
\version 1.0
\date 05 June 2016

Provide object scale
*/

#include "basemodificationobject.h"
#include "point.h"

class BaseScale : public BaseModificationObject
{
public:

	void modificateX(Point*);
	void modificateY(Point*);
	void modificateZ(Point*);

	virtual void run(Point*) = 0;

protected:
	double k;
	Point* center;
};

class Scale : public BaseScale
{
public:
	Scale();
	Scale(double, Point);
	~Scale();

	virtual void run(Point*) override;
};