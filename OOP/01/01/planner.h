#pragma once

enum e_command
{
	LOAD, QUIT, DRAW, MODIFY
};

int doit(enum e_command command, struct model* modelSettings, struct context_params* sceneSettings, struct modification_params* modificationSettings);