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
		throw AllocationMemoryError();
	}
	Point* point1 = new Point(100, 100, 100);
	Point* point2 = new Point(0, 0, 0);
	Camera* cam = new Camera(point1, point2, 0, 0, 0);
	this->camera->add(cam);
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