#include "stdafx.h"
#include "modificatescale.h"

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