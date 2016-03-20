#include "stdafx.h"
#include "draw.h"
#include "error.h"
#include "model.h"
#include "correctlines.h"

extern HWND hWnd;

void init_context(struct context_params* Scene)
{
	Scene->hdc = GetDC(hWnd);
	Scene->x = 15;
	Scene->y = 15;
	Scene->height = 670;
	Scene->width = 1000;
	Scene->bg_color = 0x00dddddd;
	Scene->ln_color = 0x0000ff00;
}

int draw(struct view View)
{
	int error;

	error = draw_scene(View.Scene);
	if (error != OK)
	{
		error = DRAW_SCENE_ERROR;
		return error;
	}
	
	error = draw_model(View);
	return error;
}

int draw_scene(struct context_params Scene)
{
	SelectObject(Scene.hdc, CreatePen(PS_SOLID, 1, 0x00000000));
	SelectObject(Scene.hdc, CreateSolidBrush(Scene.bg_color));

	if (Rectangle(Scene.hdc, Scene.x, Scene.y, Scene.x + Scene.width, Scene.y + Scene.height))
		return OK;
	return -1;
}

int draw_model(struct view View)
{
	int error = OK;

	struct line lines;
	error = allocate_lines(&lines, View.Model.Edge.Number);
	if (error != OK)
	{
		return error;
	}

	build_lines(View, &lines);

	int y;
	y = 0;
	y++;

	for (int i = 0; i < View.Model.Edge.Number; i++)
	{
		draw_line(View,*(&lines+i));
	}

	return error;
}

int allocate_lines(struct line* lines, int Number)
{
	lines = (line*)malloc(Number*sizeof(struct line));
	if (!lines)
	{
		return CANT_ALLOCATE_LINES;
	}
	return OK;
}

void build_lines(struct view View, struct line* lines)
{
	for (int i = 0; i < View.Model.Edge.Number; i++)
	{
		(lines + i)->x1 = (int)((View.Model.Node.Items + (View.Model.Edge.Items + i)->node1)->X);
		(lines + i)->y1 = (int)((View.Model.Node.Items + (View.Model.Edge.Items + i)->node1)->Y);
		(lines + i)->x2 = (int)((View.Model.Node.Items + (View.Model.Edge.Items + i)->node2)->X);
		(lines + i)->y2 = (int)((View.Model.Node.Items + (View.Model.Edge.Items + i)->node2)->Y);
	}
	return;
}

int draw_line(struct view View, struct line lines)
{
	reverse_y(&lines, View.Scene.height);

	SelectObject(View.Scene.hdc, CreatePen(PS_SOLID, 2, View.Scene.ln_color));
	MoveToEx(View.Scene.hdc, View.Scene.x + lines.x1, View.Scene.y + lines.y1, NULL);

	return LineTo(View.Scene.hdc, View.Scene.x + lines.x2, View.Scene.y + lines.y2);

}