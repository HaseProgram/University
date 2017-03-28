#pragma once

/*!
\brief  Composite object
\author Dmitry Zaitsev
\version 2.3
\date 29 May 2016

Let acting with array of objects like with single one as well
*/

#include "exceptioncomposit.h"
#include "basesceneelement.h"
#include "array.h"

class CompositeObject : public BaseSceneElement
{
public:
	CompositeObject();
	~CompositeObject();

	virtual void add(BaseSceneElement*) override;
	virtual void modificate(BaseModification*) override;

	bool check();
	void clear();

	virtual bool composite() override
	{
		return true;
	}

	Array<BaseSceneElement*> objects;
};