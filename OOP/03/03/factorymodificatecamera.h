#pragma once

/*!
\brief  Returns object of camera movement action
\author Dmitry Zaitsev
\version 1.0
\date 09 June 2016

Factory pattern
*/

#include "factorymodification.h"
#include "modificatecamera.h"

class FactoryModificationCameraPitch : public FactoryModification
{
public:
	FactoryModificationCameraPitch(double angle)
	{
		this->angle = angle;
	}
	~FactoryModificationCameraPitch()
	{
	}

	virtual BaseModification* getModification() override
	{
		return new Pitch(this->angle);
	}

private:
	double angle;
};