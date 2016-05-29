#pragma once

/*!
\brief  Base class for loader
\author Dmitry Zaitsev
\version 1.0
\date 29 May 2016

Set virtual methods to loader classes
*/

#include "model.h"

class BaseLoader
{
public:

	virtual Point& readPoint() = 0;
	virtual Edge& readEdge() = 0;

	virtual Model* readModel() = 0;

	virtual BaseObject* loadModel() = 0;
};
