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
#include "factorymodificatemovement.h"
#include "factorymodificatescale.h"

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

class ModificateRotateY : public Command
{
public:
	ModificateRotateY(double angle, Point center)
	{
		this->angle = angle;
		this->center = center;
	}

	~ModificateRotateY()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FactoryModification* factory = new FactoryModificationRotateY(this->angle, this->center);
		object->modificate(factory->getModification());
	}

private:
	double angle;
	Point center;
};

class ModificateRotateZ : public Command
{
public:
	ModificateRotateZ(double angle, Point center)
	{
		this->angle = angle;
		this->center = center;
	}

	~ModificateRotateZ()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FactoryModification* factory = new FactoryModificationRotateZ(this->angle, this->center);
		object->modificate(factory->getModification());
	}

private:
	double angle;
	Point center;
};

class ModificateMoveX : public Command
{
public:
	ModificateMoveX(double shift)
	{
		this->shift = shift;
	}

	~ModificateMoveX()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FactoryModification* factory = new FactoryModificationMoveX(this->shift);
		object->modificate(factory->getModification());
	}

private:
	double shift;
};

class ModificateMoveY : public Command
{
public:
	ModificateMoveY(double shift)
	{
		this->shift = shift;
	}

	~ModificateMoveY()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FactoryModification* factory = new FactoryModificationMoveY(this->shift);
		object->modificate(factory->getModification());
	}

private:
	double shift;
};

class ModificateMoveZ : public Command
{
public:
	ModificateMoveZ(double shift)
	{
		this->shift = shift;
	}

	~ModificateMoveZ()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FactoryModification* factory = new FactoryModificationMoveZ(this->shift);
		object->modificate(factory->getModification());
	}

private:
	double shift;
};

class ModificateScale : public Command
{
public:
	ModificateScale(double k, Point center)
	{
		this->k = k;
		this->center = center;
	}

	~ModificateScale()
	{
	}

	virtual void Execute(BaseObject* object)
	{
		FactoryModification* factory = new FactoryModificationScale(this->k, this->center);
		object->modificate(factory->getModification());
	}

private:
	double k;
	Point center;
};