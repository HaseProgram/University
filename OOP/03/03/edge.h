#pragma once

/*!
\brief  Edge object
\author Dmitry Zaitsev
\version 3.0
\date 21 May 2016

Set edge using this class
*/

#include "baseobject.h"

class BaseEdge : public BaseObject
{
public:

	virtual void setFirstPoint(unsigned int) = 0;
	virtual void setSecondPoint(unsigned int) = 0;

	virtual int getFirstPoint() = 0;
	virtual int getSecondPoint() = 0;
	virtual void modificate() = 0;
};

class Edge : public BaseEdge
{
public:
	Edge();
	Edge(unsigned int firstPoint, unsigned int secondPoint);

	~Edge();

	virtual void setFirstPoint(unsigned int newFirstPoint) override;
	virtual void setSecondPoint(unsigned int newSecondPoint) override;

	virtual int getFirstPoint() override;
	virtual int getSecondPoint() override;

	virtual void modificate() override;

private:
	int firstPoint;
	int secondPoint;
};