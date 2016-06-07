#include "stdafx.h"
#include "modificaterotation.h"

/*
	BASE_ROTATE
*/

void BaseRotate::modificateX(Point* point)
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

void BaseRotate::modificateY(Point* point)
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

void BaseRotate::modificateZ(Point* point)
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

/*
	ROTATE_X
*/

RotateX::RotateX()
{
}

RotateX::RotateX(double angle, Point center)
{
	this->angle = angle;
	this->center = &center;
}

RotateX::~RotateX()
{
}

void RotateX::run(Point* point)
{
	this->modificateX(point);
}

/*
	ROTATE_Y
*/

RotateY::RotateY()
{
}

RotateY::RotateY(double angle, Point center)
{
	this->angle = angle;
	this->center = &center;
}

RotateY::~RotateY()
{
}

void RotateY::run(Point* point)
{
	this->modificateY(point);
}

/*
	ROTATE_Z
*/

RotateZ::RotateZ()
{
}

RotateZ::RotateZ(double angle, Point center)
{
	this->angle = angle;
	this->center = &center;
}

RotateZ::~RotateZ()
{
}

void RotateZ::run(Point* point)
{
	this->modificateZ(point);
}

