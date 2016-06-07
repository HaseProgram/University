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

	virtual void modificateX(Point* point) override
	{
		this->angle = this->angle * M_PI / 180.0;
		double ty = 
			(point->getY() - center->getY()) * cos(this->angle) - 
			(point->getZ() - center->getZ()) * sin(this->angle);
		double tz = 
			(point->getY() - center->getY()) * sin(this->angle) + 
			(point->getZ() - center->getZ()) * cos(this->angle);
		point->setY(ty);
		point->setZ(tz);
	}

	virtual void modificateY(Point* point) override
	{
		this->angle = this->angle * M_PI / 180.0;
		double tx =
			(point->getX() - center->getX()) * cos(this->angle) -
			(point->getZ() - center->getZ()) * sin(this->angle);
		double tz =
			(point->getX() - center->getX()) * sin(this->angle) +
			(point->getZ() - center->getZ()) * cos(this->angle);
		point->setY(tx);
		point->setZ(tz);
	}

	virtual void modificateZ(Point* point) override
	{
		this->angle = this->angle * M_PI / 180.0;
		double tx =
			(point->getX() - center->getX()) * cos(this->angle) -
			(point->getY() - center->getY()) * sin(this->angle);
		double ty =
			(point->getX() - center->getX()) * sin(this->angle) +
			(point->getY() - center->getY()) * cos(this->angle);
		point->setY(tx);
		point->setZ(ty);
	}

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

