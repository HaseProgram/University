#include "stdafx.h"
#include "modificaterotation.h"

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

/////////////////////////////////////////////////////

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

////////////////////////////////////////////////////

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

