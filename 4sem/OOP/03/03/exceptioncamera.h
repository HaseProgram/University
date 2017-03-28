#pragma once
#include "exception.h"

class CameraWrongVectorSettingsError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not set camera vector. Wrong sourse array size!";
	}
};