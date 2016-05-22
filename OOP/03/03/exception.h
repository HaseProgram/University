#pragma once
#include <exception>

class ExceptionBase : public std::exception
{
public:
	virtual const char* what() const = 0;
};

class MemoryError : public ExceptionBase
{
public:
	virtual const char* what() const
	{
		return "Can not allocate memory while add item in Array";
	}
};

class IteratorAddError : public ExceptionBase
{
public:
	virtual const char* what() const
	{
		return "Can not add item in array. Current item points to NULL";
	}
};

class IteratorDeleteError : public ExceptionBase
{
public:
	virtual const char* what() const
	{
		return "Can not delete item from array. Current item points to NULL";
	}
};