#pragma once
#include "exception.h"

class MemoryError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not allocate memory while add item in Array";
	}
};

class IteratorAddError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not add item in array. Current item points to NULL";
	}
};

class IteratorDeleteError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not delete item from array. Current item points to NULL";
	}
};

class IteratorAccessElementError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not access item of NULL!";
	}
};

class IteratorAccessArrayError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not operate with NULL array!";
	}
};