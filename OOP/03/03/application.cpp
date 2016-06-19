#include "stdafx.h"
#include "application.h"

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
		throw AllocationMemoryError();
	}
	Point point(100, 100, 100);
	this->camera->add(&point);
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
	c.Execute(this->object,this->camera,index);
}