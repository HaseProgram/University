#include "stdafx.h"
#include "point.h"

Point::Point()
{
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}

Point::Point(Vector vec)
{
	this->X = vec.getX();
	this->Y = vec.getY();
	this->Z = vec.getZ();
}

Point::Point(double X, double Y, double Z)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

Point::~Point()
{
}

void Point::setX(double newX)
{
	this->X = newX;
}

void Point::setY(double newY)
{
	this->Y = newY;
}

void Point::setZ(double newZ)
{
	this->Z = newZ;
}

double Point::getX()
{
	return this->X;
}

double Point::getY()
{
	return this->Y;
}

double Point::getZ()
{
	return this->Z;
}

Array<double> Point::vector()
{
	Array<double> tmp;
	tmp.addItem(this->X);
	tmp.addItem(this->Y);
	tmp.addItem(this->Z);
	double s = 1;
	tmp.addItem(s);
	return tmp;
}

void Point::modificate(BaseModificationObject* modification)
{
	modification->run(this);
}