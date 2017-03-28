#pragma once

/*!
\brief  Draw class
\author Dmitry Zaitsev
\version 1.0
\date 21 May 2016

Drawing model
*/

#include "basedrawer.h"
#include "exceptiondrawer.h"

class Drawer : public BaseDrawer
{
public:
	Drawer(BaseSystemDrawer*);
	~Drawer();
	virtual void drawmodel(Model*, Camera*) override;
};