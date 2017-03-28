#pragma once

/*!
\brief  Start application
\author Dmitry Zaitsev
\version 2.0
\date 21 May 2016

Acting like facade.
*/

#include "command.h"

class Application
{
public:
	Application();
	~Application();
	void Call(Command &c, int index);
private:
	BaseSceneElement* object;
	BaseSceneElement* camera;
};