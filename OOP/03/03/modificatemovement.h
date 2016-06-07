#pragma once

/*!
\brief  Move modification for any object
\author Dmitry Zaitsev
\version 1.0
\date 06 June 2016

Provide object movement
*/

#include "basemodification.h"
#include "point.h"

class BaseMovement : public BaseModification
{
public:

	void modificateX(Point* point) override
	{
		point->setX(point->getX() + this->shift);
	}

	void modificateY(Point* point) override
	{
		point->setY(point->getY() + this->shift);
	}

	void modificateZ(Point* point) override
	{
		point->setZ(point->getZ() + this->shift);
	}

	virtual void run(Point*) = 0;

protected:
	double shift;
};

class Scale : public BaseMovement
{
public:
	Scale();
	Scale(double, Point);
	~Scale();

	virtual void run(Point*) override;
};