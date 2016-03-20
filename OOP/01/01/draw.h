#pragma once

void init_context(struct context_params* Scene);
int draw(struct view View);
int draw_scene(struct context_params Scene);
int draw_model(struct view View);
void build_lines(struct view View, struct line* lines);
int allocate_lines(struct line* lines, int Number);
int draw_line(struct view View, struct line lines);

struct line
{
	int x1, x2, y1, y2;
};