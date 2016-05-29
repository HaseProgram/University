#pragma once
#include "exception.h"

class FileLoaderOpenFileError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not open model file!";
	}
};

class FileLoaderReadAmount : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Error while reading amount of models/points/edges!";
	}
};

class FileLoaderReadPoint : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Error while reading point!";
	}
};

class FileLoaderParametersError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Error while reading file! Wrong structure of file!";
	}
};