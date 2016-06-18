#include "stdafx.h"
#include "compositeobject.h"

CompositeObject::CompositeObject()
{
}

CompositeObject::~CompositeObject()
{
	this->clear();
}

void CompositeObject::add(BaseSceneElement* object)
{
	if (!object)
	{
		throw CompositeObjectAddNULLError();
	}
	this->objects.addItem(object);
}

void CompositeObject::modificate(BaseModification* modification)
{
	IArray<BaseSceneElement*> coaIterrator(this->objects);
	while (coaIterrator.check())
	{
		coaIterrator.value()->modificate(modification);
		coaIterrator.next();
	}
	/*for (unsigned int i = 0; i < this->objects.count(); i++)
	{
		if (!coaIterrator.getByCount(i))
		{
			throw CompositeObjectModificateNULLError();
		}
		coaIterrator.value()->modificate(modification);
	}*/
}

void CompositeObject::clear()
{
	this->objects.clear();
}