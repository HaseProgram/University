#pragma once
#include "Commdlg.h"

#define ID_BUTTON_CLEAR 500
#define ID_BUTTON_LCOLOR 501
#define ID_BUTTON_BCOLOR 502
#define ID_BUTTON_DRAW_ELLIPSE 503
#define ID_BUTTON_DRAW_CIRCLE 504
#define ID_BUTTON_DRAW_SPEKTRE 505

#define ID_EDIT_ELLIPSE_CENTER_X 600
#define ID_EDIT_ELLIPSE_CENTER_Y 601
#define ID_EDIT_ELLIPSE_HEIGHT 602
#define ID_EDIT_ELLIPSE_WIDTH 603

#define ID_EDIT_CIRCLE_CENTER_X 604
#define ID_EDIT_CIRCLE_CENTER_Y 605
#define ID_EDIT_CIRCLE_RADIUS 606

#define ID_EDIT_SPEKTRE_RADIUS_MIN 607
#define ID_EDIT_SPEKTRE_RADIUS_MAX 608
#define ID_EDIT_SPEKTRE_RADIUS_STEP 609

#define ID_COMBO_ELLIPSE 700
#define ID_COMBO_CIRCLE 701
#define ID_COMBO_SPEKTRE 702

scene init_scene(HWND hWnd);

void draw_scene(scene sceneSettings);
void init_buttons();
void init_colorpick(scene sceneSettings);
void change_color(scene* sceneSettings, BOOL  flag);
void init_text(scene sceneSettings);
void init_editfields();
void init_combobox();