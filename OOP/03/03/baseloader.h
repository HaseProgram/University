#pragma once

/*!
\brief  Base class for loader
\author Dmitry Zaitsev
\version 1.0
\date 29 May 2016

Set virtual methods to loader classes. Used Briedge pattern (impl)
Sure it's easier create only BaseLoader->FLoader, without any implimentation, but Tassov requires it.
*/

#include "model.h"

class BaseLoaderImpl;
class BaseLoader
{
public:
	virtual BaseSceneElement* loadModel(BaseSceneElement*) = 0;
	
	BaseLoader(BaseLoaderImpl* impl)
	{
		this->blimpl = impl;
	}

	~BaseLoader()
	{
		delete this->blimpl;
		blimpl = nullptr;
	}
protected:
	BaseLoaderImpl* blimpl;
};

class BaseLoaderImpl
{
public:
	virtual ~BaseLoaderImpl() {};
	virtual BaseSceneElement* loadModel(BaseSceneElement*) = 0;
};