#include "stdafx.h"
#include "application.h"
#include "camera.h"
Application::Application()
{
	this->object = new CompositeObject;
	if (!this->object)
	{
		throw AllocationMemoryError();
	}
	this->camera = new CompositeObject;
	if (!this->camera)
	{
		delete this->object;
		this->object = nullptr;
		throw AllocationMemoryError();
	}
}

Application::~Application()
{
	delete this->object;
	this->object = nullptr;
	delete this->camera;
	this->camera = nullptr;
}

void Application::Call(Command &c, int index)
{
	c.Execute(this->object, this->camera, index);
}