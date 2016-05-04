#pragma once
#include <exception>

class ItError : public std::exception
{

public:
	virtual const char* out()
	{
		return "Iteration error occured";
	}

};

class Range : public ItError
{

public:
	const char* out()
	{
		return "Attempt to apply item out of range!";
	}

};

class Index : public ItError
{

public:
	const char* out()
	{
		return "Index in [] is out of range!";
	}

};