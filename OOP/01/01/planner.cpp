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
			init_context(&Argument->sceneSettings);
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
			modify_model(&modelSettings, Argument->modificationSettings);
		}
		break;
	case QUIT:
		if (Argument->load)
		{
			close_model(&modelSettings, &Argument->load);
			delete_scene(Argument->sceneSettings);
		}
		break;
	default:
		error = BAD_COMMAND;
	}
	return error;
}