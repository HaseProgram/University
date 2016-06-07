#pragma once

/*!
	\brief  Get action and process it.
	\author Dmitry Zaitsev
	\version 1.0
	\date 21 May 2016
	
	Process command in form of object
*/

#include "fileloader.h"
#include "factorymodificaterotation.h"

class Command
{
public:
	virtual void Execute(BaseObject*) = 0;
};

class Load : public Command
{
public:
	Load(const char* filename)
	{
		this->filename = filename;
	}

	~Load()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FLoader* loader = new FLoader(this->filename);
		loader->loadModel(object);
	}

private:
	const char* filename;
};

class ModificateRotateX : public Command
{
public:
	ModificateRotateX(double angle, Point center)
	{
		this->angle = angle;
		this->center = center;
	}

	~ModificateRotateX()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FactoryModification* factory = new FactoryModificationRotateX(this->angle,this->center);
		object->modificate(factory->getModification());
	}

private:
	double angle;
	Point center;
};