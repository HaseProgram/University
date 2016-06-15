#pragma once

/*!
\brief  Draw base class
\author Dmitry Zaitsev
\version 1.0
\date 21 May 2016

Interface for drawing
*/

#include "model.h"
#include "camera.h"
#include "systemdrawer.h"

class BaseDrawer
{
public:
	virtual void drawmodel(Model&, Camera&) = 0;

protected:
	SystemDrawer* systemDrawer;
};