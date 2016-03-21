#include "stdafx.h"
#include "planner.h"
#include "model.h"
#include "loadmodel.h"
#include "draw.h"
#include "modifymodel.h"

int doit(enum e_command command, struct view* View)
{
	int error = OK;

	switch (command)
	{
	case LOAD:
		error = load_model(View);
		break;
	case DRAW:
		if (View->Model.fileName)
		{
			init_context(&View->Scene);
			error = draw(*View);
		}
		else
		{
			error = NO_MODEL;
		}
		break;
	case MODIFY:
		if (View->Model.fileName)
		{
			modify_model(View);
		}
		break;
	case QUIT:
		if (View->Model.fileName)
		{
			close_model(View);
		}
		break;
	default:
		error = BAD_COMMAND;
	}
	return error;
}