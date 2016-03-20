#include "stdafx.h"
#include "planner.h"
#include "model.h"
#include "loadmodel.h"
#include "draw.h"

int doit(enum e_command command, struct view* View)
{
	int error = OK;

	switch (command)
	{
	case LOAD:
		error = load_model(View);
		break;
	case DRAW:
		init_context(&View->Scene);
		error = draw(*View);
	default:
		error = BAD_COMMAND;
	}
	return error;
}