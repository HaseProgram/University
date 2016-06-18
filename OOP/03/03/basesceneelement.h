#pragma once

/*!
\brief  Base element
\author Dmitry Zaitsev
\version 2.1
\date 29 May 2016

Parent of base camera and base object
*/

#include "basemodification.h"

class BaseSceneElement
{
public:
	/*!
	Need for composite
	\param[in] BaseObject Object we add in composite array
	*/
	virtual void add(BaseSceneElement*) {}

	virtual void modificate(BaseModification*) = 0;

	virtual bool composite()
	{
		return false;
	}

protected:

};
