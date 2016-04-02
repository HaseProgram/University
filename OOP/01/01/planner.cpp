#include "stdafx.h"
#include "model.h"
#include "modifymodel.h"
#include "loadmodel.h"
#include "draw.h"
#include "planner.h"

int doit(enum e_command command, struct argument* Argument)
{
	int error = OK;

	static struct model modelSettings = init();

	switch (command)
	{
	case LOAD:
		error = load_model(&modelSettings, Argument->load);
		break;
	case DRAW:
		if (Argument->load)
		{
			error = draw(Argument->sceneSettings,modelSettings);
		}
		else
		{
			error = NO_MODEL;
		}
		break;
	case MODIFY:
		if (Argument->load)
		{
			error = modify_model(&modelSettings, Argument->modificationSettings);
		}
		else
		{
			error = NO_MODEL;
		}
		break;
	case QUIT:
		if (Argument->load)
		{
			error = close_model(&modelSettings, &Argument->load);
			//error = delete_scene(Argument->sceneSettings);
		}
		break;
	default:
		error = BAD_COMMAND;
	}
	return error;
}