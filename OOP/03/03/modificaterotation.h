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

class Rotate : public BaseModification
{
public:

	void modificateX(Point* point)
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

	void modificateY(Point* point)
	{
		this->angle = this->angle * M_PI / 180.0;
		double ty =
			(point->getX() - center->getX()) * cos(this->angle) -
			(point->getZ() - center->getZ()) * sin(this->angle);
		double tz =
			(point->getX() - center->getX()) * sin(this->angle) +
			(point->getZ() - center->getZ()) * cos(this->angle);
		point->setY(ty);
		point->setZ(tz);
	}

	void modificateZ(Point* point)
	{
		this->angle = this->angle * M_PI / 180.0;
		double ty =
			(point->getX() - center->getX()) * cos(this->angle) -
			(point->getY() - center->getY()) * sin(this->angle);
		double tz =
			(point->getX() - center->getX()) * sin(this->angle) +
			(point->getY() - center->getY()) * cos(this->angle);
		point->setY(ty);
		point->setZ(tz);
	}

	virtual void run(Point*) = 0;

protected:
	double angle;
	Point* center;
};

class RotateX : public Rotate
{
public:
	RotateX();
	RotateX(double, Point);
	~RotateX();

	virtual void run(Point*) override;
};

class RotateY : public Rotate
{
public:
	RotateY();
	RotateY(double, Point);
	~RotateY();

	virtual void run(Point*) override;
};

class RotateZ : public Rotate
{
public:
	RotateZ();
	RotateZ(double, Point);
	~RotateZ();

	virtual void run(Point*) override;
};