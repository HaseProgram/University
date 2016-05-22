#pragma once

/*!
	\brief  Get action and process it.
	\author Dmitry Zaitsev
	\version 1.0
	\date 21 May 2016
	
	Process command in form of object
*/

#include "scenemanager.h"

class Command
{
public:
	virtual void Execute(SceneManager* sm) = 0;
};

class Load : public Command
{
public:
	Load(const char* filename)
	{
		this->filename = filename;
	}

	~Load()
	{
	}

	virtual void Execute(SceneManager* sm)
	{

	}

private:
	const char* filename;
};