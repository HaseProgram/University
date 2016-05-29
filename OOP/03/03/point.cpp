#include "stdafx.h"
#include "point.h"

Point::Point()
{
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}

Point::Point(double X, double Y, double Z)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

Point::~Point()
{
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
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

void Point::modificate()
{

}