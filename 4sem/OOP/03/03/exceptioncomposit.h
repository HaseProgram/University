#pragma once
#include "exception.h"

class CompositeObjectAddNULLError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not add NULL object in composit array!";
	}
};

class CompositeObjectModificateNULLError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not modificate NULL object in composit array!";
	}
};
