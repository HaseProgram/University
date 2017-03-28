#pragma once
#include "draw.h"
#include "Commdlg.h"

#define ID_BUTTON_DRAW 500
#define ID_BUTTON_CLEAR 501
#define ID_BUTTON_SUN 512

#define ID_BUTTON_LCOLOR 502
#define ID_BUTTON_BCOLOR 503

#define ID_EDIT_X1 600
#define ID_EDIT_Y1 601
#define ID_EDIT_X2 602
#define ID_EDIT_Y2 603
#define ID_EDIT_ANGLE 604


line get_line();

void color_dialog(scene* sceneSettings, BOOL flag);
void init_colorpick(scene sceneSettings);
void init_edit_fields();
void init_combobox();
void init_buttons();
void init_container(scene* sceneSettings);