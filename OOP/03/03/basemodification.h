#pragma once

/*!
\brief  Base modification for anything (model and camera)
\author Dmitry Zaitsev
\version 1.0
\date 09 June 2016

Set base interface for  modification
*/

#define _USE_MATH_DEFINES
#include <cmath>

class BaseSceneElement;
class BaseModification
{
public:
	BaseModification() {};
	~BaseModification() {};

	virtual void run(BaseSceneElement*) = 0;
};