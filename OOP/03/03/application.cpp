#include "stdafx.h"
#include "application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::Call(Command &c)
{
	c.Execute(this->sm);
}