#pragma once

/*!
\brief  Scale modification for any object
\author Dmitry Zaitsev
\version 1.0
\date 05 June 2016

Provide object scale
*/

#include "basemodification.h"
#include "point.h"

class BaseScale : public BaseModification
{
public:

	void modificateX(Point* point) override
	{
		double tx = (point->getX() - center->getX()) * this->k + center->getX();
		point->setX(tx);
	}

	void modificateY(Point* point) override
	{
		double ty = (point->getY() - center->getY()) * this->k + center->getY();
		point->setY(ty);
	}

	void modificateZ(Point* point) override
	{
		double tz = (point->getZ() - center->getZ()) * this->k + center->getZ();
		point->setZ(tz);
	}

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