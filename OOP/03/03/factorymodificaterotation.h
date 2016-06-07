#pragma once

/*!
\brief  Returns object of rotation action
\author Dmitry Zaitsev
\version 1.0
\date 06 June 2016

Factory pattern
*/

#include "factorymodification.h"
#include "modificaterotation.h"

class FactoryModificationRotateX : public FactoryModification
{
public:
	FactoryModificationRotateX(double angle, Point center)
	{
		this->angle = angle;
		this->center = center;
	}
	~FactoryModificationRotateX()
	{
	}

	virtual BaseModification* getModification()
	{
		return (BaseModification*) new RotateX(this->angle, this->center);
	}

private:
	double angle;
	Point center;
};

class FactoryModificationRotateY : public FactoryModification
{
public:
	FactoryModificationRotateY(double angle, Point center)
	{
		this->angle = angle;
		this->center = center;
	}
	~FactoryModificationRotateY()
	{
	}

	virtual BaseModification* getModification()
	{
		return (BaseModification*) new RotateY(this->angle, this->center);
	}

private:
	double angle;
	Point center;
};

class FactoryModificationRotateZ : public FactoryModification
{
public:
	FactoryModificationRotateZ(double angle, Point center)
	{
		this->angle = angle;
		this->center = center;
	}
	~FactoryModificationRotateZ()
	{
	}

	virtual BaseModification* getModification()
	{
		return (BaseModification*) new RotateZ(this->angle, this->center);
	}

private:
	double angle;
	Point center;
};
