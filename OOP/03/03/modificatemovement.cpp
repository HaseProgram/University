#include "stdafx.h"
#include "modificatemovement.h"

/*
	BASE_MOVE
*/

void BaseMove::modificateX(Point* point)
{
	point->setX(point->getX() + this->shift);
}

void BaseMove::modificateY(Point* point)
{
	point->setY(point->getY() + this->shift);
}

void BaseMove::modificateZ(Point* point)
{
	point->setZ(point->getZ() + this->shift);
}

/*
	MOVE_X
*/

MoveX::MoveX()
{
}

MoveX::MoveX(double shift)
{
	this->shift = shift;
}

MoveX::~MoveX()
{
}

void MoveX::run(Point* point)
{
	this->modificateX(point);
}

/*
	MOVE_Y
*/

MoveY::MoveY()
{
}

MoveY::MoveY(double shift)
{
	this->shift = shift;
}

MoveY::~MoveY()
{
}

void MoveY::run(Point* point)
{
	this->modificateY(point);
}

/*
	MOVE_Z
*/

MoveZ::MoveZ()
{
}

MoveZ::MoveZ(double shift)
{
	this->shift = shift;
}

MoveZ::~MoveZ()
{
}

void MoveY::run(Point* point)
{
	this->modificateZ(point);
}

