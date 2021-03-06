#pragma once

/*!
\brief  Base camera
\author Dmitry Zaitsev
\version 2.1
\date 29 May 2016

Set base interface for camera
*/

#include "basesceneelement.h"
#include "basemodificationcamera.h"

class BaseCamera : public BaseSceneElement
{
public:
	/*!
	Need for composite
	\param[in] BaseObject Object we add in composite array
	*/
	virtual void add(BaseCamera*) {}

	virtual void pitch(double) = 0;
	virtual void yaw(double) = 0;
	virtual void roll(double) = 0;

	virtual void rotateVerticalSphere(double) = 0;
	virtual void rotateHorizontalSphere(double) = 0;

	virtual void modificate(BaseModification* mod)
	{
		this->modificate((BaseModificationCamera*)mod);
	}

	virtual void modificate(BaseModificationCamera*) = 0;

protected:

};
