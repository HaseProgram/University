#include "stdafx.h"
#include "action.h"

Action::Action()
{
	this->sceneManager = new SceneManager;
}

Action::~Action()
{
	delete this->sceneManager;
}