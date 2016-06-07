#pragma once

/*!
\brief  Returns object of scale action
\author Dmitry Zaitsev
\version 1.0
\date 07 June 2016

Factory pattern
*/

#include "factorymodification.h"
#include "modificatescale.h"

class FactoryModificationScale : public FactoryModification
{
public:
	FactoryModificationScale(double k, Point center)
	{
		this->k = k;
		this->center = center;
	}
	~FactoryModificationScale()
	{
	}

	virtual BaseModification* getModification()
	{
		return (BaseModification*) new Scale(this->k, this->center);
	}

private:
	double k;
	Point center;
};