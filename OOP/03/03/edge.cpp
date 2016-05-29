#include "stdafx.h"
#include "edge.h"

Edge::Edge()
{
}

Edge::Edge(unsigned int firstPoint, unsigned int secondPoint)
{
	this->firstPoint = firstPoint;
	this->secondPoint = secondPoint;
}

Edge::~Edge()
{
}

void Edge::setFirstPoint(unsigned int newFirstPoint)
{
	this->firstPoint = newFirstPoint;
}

void Edge::setSecondPoint(unsigned int newSecondPoint)
{
	this->secondPoint = newSecondPoint;
}

int Edge::getFirstPoint()
{
	return this->firstPoint;
}

int Edge::getSecondPoint()
{
	return this->secondPoint;
}

void Edge::modificate()
{

}