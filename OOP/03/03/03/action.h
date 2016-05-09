#pragma once

/*!
	\brief  Get action and process it.
	\author Dmitry Zaitsev
	\version 1.0
	\date 09 May 2016
	
	This class gets action from listener and call processer.
*/

#include "scenemanager.h"

class Action
{
private:
	SceneManager* sceneManager;

public:
	Action();
	~Action();

	void setup();

	void loadModel();
	void loadCamera();
	void drawModel();
	void modifyModel();
	void closeModel();
};