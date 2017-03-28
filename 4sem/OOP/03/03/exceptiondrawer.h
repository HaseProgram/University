#pragma once
#include "exception.h"

class DrawerEmptyModelError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not draw empty model!";
	}
};
