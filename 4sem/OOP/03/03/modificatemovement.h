#pragma once

/*!
\brief  Move modification for any object
\author Dmitry Zaitsev
\version 1.0
\date 06 June 2016

Provide object movement
*/

#include "basemodificationobject.h"
#include "point.h"

class BaseMove : public BaseModificationObject
{
public:

	void modificateX(Point*);
	void modificateY(Point*);
	void modificateZ(Point*);

	virtual void run(Point*) = 0;

protected:
	double shift;
};

class MoveX : public BaseMove
{
public:
	MoveX();
	MoveX(double);
	~MoveX();

	virtual void run(Point*) override;
};

class MoveY : public BaseMove
{
public:
	MoveY();
	MoveY(double);
	~MoveY();

	virtual void run(Point*) override;
};

class MoveZ : public BaseMove
{
public:
	MoveZ();
	MoveZ(double);
	~MoveZ();

	virtual void run(Point*) override;
};