#pragma once

/*!
\brief  Start application
\author Dmitry Zaitsev
\version 1.0
\date 21 May 2016

Acting like facade.
*/

#include "scenemanager.h"
#include "command.h"

class Application
{
public:
	Application();
	~Application();
	void Call(Command &c);

private:
	SceneManager* sm;
};