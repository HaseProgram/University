#pragma once

/*!
\brief  Edge object
\author Dmitry Zaitsev
\version 1.0
\date 21 May 2016

Set edge using this class
*/

#include "point.h"

class EdgeBase
{
public:
	EdgeBase() {};
	~EdgeBase() {};

	virtual void setFirstPoint(Point*) = 0;
	virtual void setSecondPoint(Point*) = 0;

	virtual Point* getFirstPoint() = 0;
	virtual Point* getSecondPoint() = 0;
};

class Edge : public EdgeBase
{
public:
	Edge(Point* firstPoint, Point* secondPoint)
	{
		this->firstPoint = firstPoint;
		this->secondPoint = secondPoint;
	}

	~Edge()
	{
	}

	virtual void setFirstPoint(Point* newFirstPoint)
	{
		this->firstPoint = newFirstPoint;
	}

	virtual void setSecondPoint(Point* newSecondPoint)
	{
		this->secondPoint = newSecondPoint;
	}

	virtual Point* getFirstPoint()
	{
		return this->firstPoint;
	}

	virtual Point* getSecondPoint()
	{
		return this->secondPoint;
	}

private:
	Point* firstPoint;
	Point* secondPoint;
};