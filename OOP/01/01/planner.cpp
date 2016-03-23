#include "stdafx.h"
#include "planner.h"
#include "model.h"
#include "loadmodel.h"
#include "draw.h"
#include "modifymodel.h"

int doit(enum e_command command, struct model* modelSettings, struct context_params* sceneSettings, struct modification_params* modificationSettings)
{
	int error = OK;

	switch (command)
	{
	case LOAD:
		error = load_model(modelSettings);
		break;
	case DRAW:
		if (modelSettings->fileName)
		{
			init_context(sceneSettings);
			error = draw(*sceneSettings,*modelSettings);
		}
		else
		{
			error = NO_MODEL;
		}
		break;
	case MODIFY:
		if (modelSettings->fileName)
		{
			modify_model(modelSettings, *modificationSettings);
		}
		break;
	case QUIT:
		if (modelSettings->fileName)
		{
			close_model(modelSettings);
		}
		break;
	default:
		error = BAD_COMMAND;
	}
	return error;
}