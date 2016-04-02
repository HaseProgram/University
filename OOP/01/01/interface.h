#pragma once

#define ID_BUTTON_ROTATE_UP 5000
#define ID_BUTTON_ROTATE_DOWN 5001
#define ID_BUTTON_ROTATE_LEFT 5002
#define ID_BUTTON_ROTATE_RIGHT 5003
#define ID_BUTTON_ZOOM_IN 5004
#define ID_BUTTON_ZOOM_OUT 5005

#include <Commdlg.h>

enum load_type
{
	FROM_FILE, FROM_DATABASE
};

static struct stream
{
	enum load_type type;
} Stream;

void init_context(struct context_params* sceneSettings);

char* get_model_name();
void initButtons();