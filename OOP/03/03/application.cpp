#include "stdafx.h"
#include "application.h"

Application::Application()
{
	this->object = new CompositeObject;
	if (!this->object)
	{
		throw AllocationMemoryError();
	}
}

Application::~Application()
{
	delete this->object;
	this->object = nullptr;
}

void Application::Call(Command &c)
{
	c.Execute(this->object);
}