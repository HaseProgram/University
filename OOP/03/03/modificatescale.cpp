#include "stdafx.h"
#include "modificatescale.h"

/*
	BASE_SCALE
*/

void BaseScale::modificateX(Point* point)
{
	double tx = (point->getX() - center->getX()) * this->k + center->getX();
	point->setX(tx);
}

void BaseScale::modificateY(Point* point)
{
	double ty = (point->getY() - center->getY()) * this->k + center->getY();
	point->setY(ty);
}

void BaseScale::modificateZ(Point* point)
{
	double tz = (point->getZ() - center->getZ()) * this->k + center->getZ();
	point->setZ(tz);
}

/*
	SCALE
*/

Scale::Scale()
{
}

Scale::Scale(double k, Point center)
{
	this->k = k;
	this->center = &center;
}

Scale::~Scale()
{
}

void Scale::run(Point* point)
{
	this->modificateX(point);
	this->modificateY(point);
	this->modificateZ(point);
}