#pragma once

enum e_command
{
	LOAD, QUIT, DRAW, MODIFY
};

int doit(enum e_command command, struct view* params);