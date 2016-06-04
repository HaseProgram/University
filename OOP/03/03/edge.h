#pragma once

/*!
\brief  Edge object
\author Dmitry Zaitsev
\version 4.0
\date 21 May 2016

Set edge using this class
*/

#include "baseobject.h"
#include "point.h"

class BaseEdge : public BaseObject
{
public:

	virtual void setFirstPoint(Point*) = 0;
	virtual void setSecondPoint(Point*) = 0;

	virtual Point* getFirstPoint() = 0;
	virtual Point* getSecondPoint() = 0;
	virtual void modificate(BaseModification*) = 0;
};

class Edge : public BaseEdge
{
public:
	Edge();
	Edge(Point* firstPoint, Point* secondPoint);

	~Edge();

	virtual void setFirstPoint(Point* newFirstPoint) override;
	virtual void setSecondPoint(Point* newSecondPoint) override;

	virtual Point* getFirstPoint() override;
	virtual Point* getSecondPoint() override;

	virtual void modificate(BaseModification*) override;

private:
	Point* firstPoint;
	Point* secondPoint;
};