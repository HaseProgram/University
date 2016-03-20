#include "stdafx.h"
#include "planner.h"
#include "model.h"
#include "loadmodel.h"

int doit(enum e_command command, struct view* View)
{
	int error = OK;

	switch (command)
	{
	case LOAD:
		error = load_model(View);
		break;
	default:
		error = BAD_COMMAND;
	}
	return error;
}