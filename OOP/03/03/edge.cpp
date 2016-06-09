#include "stdafx.h"
#include "edge.h"

Edge::Edge()
{
}

Edge::Edge(Point* firstPoint, Point* secondPoint)
{
	this->firstPoint = firstPoint;
	this->secondPoint = secondPoint;
}

Edge::~Edge()
{
}

void Edge::setFirstPoint(Point* newFirstPoint)
{
	this->firstPoint = newFirstPoint;
}

void Edge::setSecondPoint(Point* newSecondPoint)
{
	this->secondPoint = newSecondPoint;
}

Point* Edge::getFirstPoint()
{
	return this->firstPoint;
}

Point* Edge::getSecondPoint()
{
	return this->secondPoint;
}

void Edge::modificate(BaseModification* modification)
{
	this->getFirstPoint()->modificate(modification);
	this->getSecondPoint()->modificate(modification);
}