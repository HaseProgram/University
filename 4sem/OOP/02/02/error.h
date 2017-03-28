#pragma once
#include <exception>

class Error : public std::exception
{

public:
	virtual const char* out()
	{
		return "Error occured";
	}

};

class MemoryError : public Error
{

public:
	const char* out()
	{
		return "Allocation memory occured!";
	}

};

class PrintError : public Error
{

public:
	const char* out()
	{
		return "List is empty";
	}

};

class WrongLink : public Error
{

public:
	const char* out()
	{
		return "Wrong link pointer";
	}

};

class Last : public Error
{

public:
	const char* out()
	{
		return "Cannon delete last element";
	}

};