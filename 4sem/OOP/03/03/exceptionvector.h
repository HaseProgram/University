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

class VectorSourceSizeError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Source array size doesn't set vector! Can not complete construct!";
	}
};