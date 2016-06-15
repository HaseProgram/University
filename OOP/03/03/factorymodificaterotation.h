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

	virtual BaseModificationObject* getModification()
	{
		return (BaseModificationObject*) new RotateX(this->angle, this->center);
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

	virtual BaseModificationObject* getModification()
	{
		return (BaseModificationObject*) new RotateY(this->angle, this->center);
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

	virtual BaseModificationObject* getModification()
	{
		return (BaseModificationObject*) new RotateZ(this->angle, this->center);
	}

private:
	double angle;
	Point center;
};
