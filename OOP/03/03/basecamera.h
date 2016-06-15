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
	virtual void modificate(BaseModificationCamera*) = 0;

protected:

};
