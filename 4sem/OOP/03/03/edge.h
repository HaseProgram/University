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

class Edge : public BaseObject
{
public:
	Edge();
	Edge(Point* firstPoint, Point* secondPoint);

	~Edge();

	void setFirstPoint(Point* newFirstPoint);
	void setSecondPoint(Point* newSecondPoint);

	Point* getFirstPoint();
	Point* getSecondPoint();

	virtual void modificate(BaseModificationObject*) override;

private:
	Point* firstPoint;
	Point* secondPoint;
};