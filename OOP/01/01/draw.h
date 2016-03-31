#pragma once

void init_context(struct context_params* sceneSettings);
int draw(struct context_params sceneSettings, struct model modelSettings);
int draw_scene(struct context_params Scene);
int delete_scene(struct context_params Scene);
int draw_model(struct context_params sceneSettings, struct model modelSettings);
void build_lines(struct context_params sceneSettings, struct model modelSettings, struct line* lines);
int allocate_lines(struct line** lines, int Number);
int draw_line(struct context_params sceneSettings, struct line lines);

struct line
{
	int x1, x2, y1, y2;
};

struct context_params
{
	HDC hdc;
	int x;
	int y;
	int height;
	int width;
	COLORREF bg_color;
	COLORREF ln_color;
};