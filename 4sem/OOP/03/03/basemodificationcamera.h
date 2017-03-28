#pragma once

/*!
\brief  Base modification for any camera
\author Dmitry Zaitsev
\version 1.0
\date 04 June 2016

Set base interface for camera modification
*/

#include "basemodification.h"
#include "cameramatrixmodification.h"

class BaseCamera;
class Camera;
class BaseModificationCamera : public BaseModification
{
public:
	BaseModificationCamera() {};
	~BaseModificationCamera() {};

	virtual void run(BaseCamera*) = 0;
};