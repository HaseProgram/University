#pragma once

#include "modifymodel.h"
#include "draw.h"

enum e_command
{
	LOAD, QUIT, DRAW, MODIFY
};

struct argument
{
	char* load;
	struct context_params sceneSettings;
	struct modification_params modificationSettings;
};

int doit(enum e_command command, struct argument* Argument);