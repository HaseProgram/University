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
}

bool CompositeObject::check()
{
	return this->objects.count() != 0;
}

void CompositeObject::clear()
{
	this->objects.clear();
}