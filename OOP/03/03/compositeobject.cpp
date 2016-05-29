#include "stdafx.h"
#include "compositeobject.h"

CompositeObject::CompositeObject()
{
}

CompositeObject::~CompositeObject()
{
	this->clear();
}

void CompositeObject::add(BaseObject* object)
{
	if (!object)
	{
		throw CompositeObjectAddNULLError();
	}
	this->objects.add(object);
}

void CompositeObject::modificate()
{
	for (int i = 0; i < this->objects.count(); i++)
	{
		if (!this->objects.getByCount(i))
		{
			throw CompositeObjectModificateNULLError();
		}
		this->objects.value()->modificate();
	}
}

void CompositeObject::clear()
{
	this->objects.clear();
}