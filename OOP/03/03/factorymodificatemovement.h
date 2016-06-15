#pragma once

/*!
\brief  Returns object of movement action
\author Dmitry Zaitsev
\version 1.0
\date 07 June 2016

Factory pattern
*/

#include "factorymodification.h"
#include "modificatemovement.h"

class FactoryModificationMoveX : public FactoryModification
{
public:
	FactoryModificationMoveX(double shift)
	{
		this->shift = shift;
	}
	~FactoryModificationMoveX()
	{
	}

	virtual BaseModificationObject* getModification()
	{
		return (BaseModificationObject*) new MoveX(this->shift);
	}

private:
	double shift;
};

class FactoryModificationMoveY : public FactoryModification
{
public:
	FactoryModificationMoveY(double shift)
	{
		this->shift = shift;
	}
	~FactoryModificationMoveY()
	{
	}

	virtual BaseModificationObject* getModification()
	{
		return (BaseModificationObject*) new MoveY(this->shift);
	}

private:
	double shift;
};

class FactoryModificationMoveZ : public FactoryModification
{
public:
	FactoryModificationMoveZ(double shift)
	{
		this->shift = shift;
	}
	~FactoryModificationMoveZ()
	{
	}

	virtual BaseModificationObject* getModification()
	{
		return (BaseModificationObject*) new MoveZ(this->shift);
	}

private:
	double shift;
};