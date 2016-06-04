#pragma once

/*!
\brief  Composite object
\author Dmitry Zaitsev
\version 2.3
\date 29 May 2016

Let acting with array of objects like with single one as well
*/

#include "exceptioncomposit.h"
#include "baseobject.h"
#include "array.h"

class CompositeObject : public BaseObject
{
public:
	CompositeObject();
	~CompositeObject();

	virtual void add(BaseObject*) override;
	virtual void modificate(BaseModification*) override;

	void clear();

	Array<BaseObject*> objects;
};