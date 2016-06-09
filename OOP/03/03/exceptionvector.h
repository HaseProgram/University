#pragma once
#include "exception.h"

class VectorSizeError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Array size doesn't set vector!";
	}
};