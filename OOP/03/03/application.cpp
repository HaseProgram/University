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
}

Application::~Application()
{
	delete this->object;
	this->object = nullptr;
}

void Application::Call(Command &c, int index)
{
	c.Execute(this->object,this->camera,index);
}