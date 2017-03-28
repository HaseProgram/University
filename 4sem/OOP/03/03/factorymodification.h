#pragma once

/*!
\brief  Returns object modification action
\author Dmitry Zaitsev
\version 1.0
\date 06 June 2016

Base factory pattern
*/

#include "basemodification.h"

class FactoryModification
{
public:
	FactoryModification() {}
	~FactoryModification() {}
	virtual BaseModification* getModification() = 0;
};