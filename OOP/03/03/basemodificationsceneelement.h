#pragma once

/*!
\brief  Base modification
\author Dmitry Zaitsev
\version 1.0
\date 04 June 2016

Set base interface for modification (parent of object and camera modification)
*/

#include "basemodification.h"

class Point;
class BaseModificationObject : public BaseModification
{
public:
	BaseModificationObject() {};
	~BaseModificationObject() {};

	virtual void modificateX(Point* point) = 0;
	virtual void modificateY(Point* point) = 0;
	virtual void modificateZ(Point* point) = 0;

	virtual void run(Point* point) = 0;
};