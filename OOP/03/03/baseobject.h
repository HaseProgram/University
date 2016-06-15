#pragma once

/*!
\brief  Base object
\author Dmitry Zaitsev
\version 2.1
\date 29 May 2016

Set base interface for any object
*/

#include "basesceneelement.h"
#include "basemodificationobject.h"

class BaseObject : public BaseSceneElement
{
public:
	/*!
		Need for composite
		\param[in] BaseObject Object we add in composite array
	*/
	virtual void add(BaseObject*) {}

	virtual void modificate(BaseModificationObject*) = 0;
};