#pragma once

/*!
	\brief  Get action and process it.
	\author Dmitry Zaitsev
	\version 1.0
	\date 21 May 2016
	
	Process command in form of object
*/

#include "fileloader.h"
#include "drawer.h"
#include "factorymodificaterotation.h"
#include "factorymodificatemovement.h"
#include "factorymodificatescale.h"
#include "factorymodificatecamera.h"

class Command
{
public:
	virtual void Execute(BaseSceneElement*, BaseSceneElement*, int) = 0;
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FLoader* loader = new FLoader(this->filename);
		loader->loadModel((BaseObject*)object);
	}

private:
	const char* filename;
};

class Draw : public Command
{
public:
	Draw(BaseSystemDrawer* systemDrawer)
	{
		this->BSD = systemDrawer;
	}

	~Draw()
	{
	}

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		this->BSD->clearscene();
		
	}

private:
	BaseSystemDrawer* BSD;
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationRotateX(this->angle,this->center);
		BaseModificationObject* o = (BaseModificationObject*)factory->getModification();
		if (index > 0 && object->composite())
		{
			CompositeObject* obj = (CompositeObject*)object;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			object = individualObject.value();
		}
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationRotateY(this->angle, this->center);
		BaseModificationObject* o = (BaseModificationObject*)factory->getModification();
		if (index > 0 && object->composite())
		{
			CompositeObject* obj = (CompositeObject*)object;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			object = individualObject.value();
		}
		object->modificate(o);
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationRotateZ(this->angle, this->center);
		BaseModificationObject* o = (BaseModificationObject*)factory->getModification();
		if (index > 0 && object->composite())
		{
			CompositeObject* obj = (CompositeObject*)object;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			object = individualObject.value();
		}
		object->modificate(o);
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationMoveX(this->shift);
		BaseModificationObject* o = (BaseModificationObject*)factory->getModification();
		if (index > 0 && object->composite())
		{
			CompositeObject* obj = (CompositeObject*)object;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			object = individualObject.value();
		}
		object->modificate(o);
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationMoveY(this->shift);
		BaseModificationObject* o = (BaseModificationObject*)factory->getModification();
		if (index > 0 && object->composite())
		{
			CompositeObject* obj = (CompositeObject*)object;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			object = individualObject.value();
		}
		object->modificate(o);
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationMoveZ(this->shift);
		BaseModificationObject* o = (BaseModificationObject*)factory->getModification();
		if (index > 0 && object->composite())
		{
			CompositeObject* obj = (CompositeObject*)object;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			object = individualObject.value();
		}
		object->modificate(o);
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

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationScale(this->k, this->center);
		BaseModificationObject* o = (BaseModificationObject*)factory->getModification();
		if (index > 0 && object->composite())
		{
			CompositeObject* obj = (CompositeObject*)object;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			object = individualObject.value();
		}
		object->modificate(o);
	}

private:
	double k;
	Point center;
};

class ModificateCameraPitch : public Command
{
public:
	ModificateCameraPitch(double angle)
	{
		this->angle = angle;
	}

	~ModificateCameraPitch()
	{
	}

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationCameraPitch(this->angle);
		BaseModificationCamera* o = (BaseModificationCamera*)factory->getModification();
		camera->modificate(o);
	}

private:
	double angle;
};

class ModificateCameraYaw : public Command
{
public:
	ModificateCameraYaw(double angle)
	{
		this->angle = angle;
	}

	~ModificateCameraYaw()
	{
	}

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationCameraYaw(this->angle);
		BaseModificationCamera* o = (BaseModificationCamera*)factory->getModification();
		if (index > 0 && camera->composite())
		{
			CompositeObject* obj = (CompositeObject*)camera;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			camera = individualObject.value();
		}
		camera->modificate(o);
	}

private:
	double angle;
};

class ModificateCameraRoll : public Command
{
public:
	ModificateCameraRoll(double angle)
	{
		this->angle = angle;
	}

	~ModificateCameraRoll()
	{
	}

	virtual void Execute(BaseSceneElement* object, BaseSceneElement* camera, int index) override
	{
		FactoryModification* factory = new FactoryModificationCameraRoll(this->angle);
		if (index > 0 && camera->composite())
		{
			CompositeObject* obj = (CompositeObject*)camera;
			IArray<BaseSceneElement*> individualObject(obj->objects);
			individualObject.getByCount(index);
			camera = individualObject.value();
		}
		camera->modificate(factory->getModification());
	}

private:
	double angle;
};
