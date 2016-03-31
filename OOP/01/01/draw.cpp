#include "stdafx.h"
#include "draw.h"
#include "error.h"
#include "model.h"
#include "correctlines.h"

extern HWND hWnd;

void init_context(struct context_params* sceneSettings)
{
	sceneSettings->hdc = GetDC(hWnd);
	sceneSettings->x = 405;
	sceneSettings->y = 15;
	sceneSettings->height = 670;
	sceneSettings->width = 1000;
	sceneSettings->bg_color = 0xFAF9FA;
	sceneSettings->ln_color = 0x48333A;
}

int draw(struct context_params sceneSettings, struct model modelSettings)
{
	int error;

	error = draw_scene(sceneSettings);
	if (error != OK)
	{
		error = DRAW_SCENE_ERROR;
		return error;
	}
	
	error = draw_model(sceneSettings, modelSettings);
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

int delete_scene(struct context_params Scene)
{
	SelectObject(Scene.hdc, CreatePen(PS_SOLID, 1, 0xFFFFFF));
	SelectObject(Scene.hdc, CreateSolidBrush(0xFFFFFF));

	if (Rectangle(Scene.hdc, Scene.x, Scene.y, Scene.x + Scene.width, Scene.y + Scene.height))
		return OK;
	return -1;
}


int draw_model(struct context_params sceneSettings, struct model modelSettings)
{
	int error = OK;

	struct edge* edgeArray = getEdgeArray(&modelSettings);
	struct line *lines;
	error = allocate_lines(&lines, getEdgeArrayCount(edgeArray));
	if (error != OK)
	{
		return error;
	}

	build_lines(sceneSettings, modelSettings, lines);

	for (int i = 0; i < getEdgeArrayCount(edgeArray); i++)
	{
		draw_line(sceneSettings,*(lines+i));
	}

	free(lines);
	lines = NULL;

	return error;
}

int allocate_lines(struct line** lines, int Number)
{
	*(lines) = (line*)malloc(Number*sizeof(struct line));
	if (!lines)
	{
		return CANT_ALLOCATE_LINES;
	}
	return OK;
}

void build_lines(struct context_params sceneSettings, struct model modelSettings, struct line* lines)
{
	int midX = sceneSettings.width / 2;
	int midY = sceneSettings.height / 2;

	struct node* nodeArray = getNodeArray(&modelSettings);
	struct edge* edgeArray = getEdgeArray(&modelSettings);

	struct edgecoordinates *edgeCoords = getEdgeArrayItems(edgeArray);
	struct nodecoordinates *nodeCoords = getNodeArrayItems(nodeArray);

	int n1, n2;

	for (int i = 0; i < getEdgeArrayCount(edgeArray); i++)
	{
		n1 = edgeCoords[i].node1;
		n2 = edgeCoords[i].node2;

		lines[i].x1 = midX + (int)nodeCoords[n1].X;
		lines[i].y1 = midY + (int)nodeCoords[n1].Y;
		lines[i].x2 = midX + (int)nodeCoords[n2].X;
		lines[i].y2 = midY + (int)nodeCoords[n2].Y;
	}
	return;
}

int draw_line(struct context_params sceneSettings, struct line lines)
{
	reverse_y(&lines, sceneSettings.height);

	SelectObject(sceneSettings.hdc, CreatePen(PS_SOLID, 2, sceneSettings.ln_color));
	MoveToEx(sceneSettings.hdc, sceneSettings.x + lines.x1, sceneSettings.y + lines.y1, NULL);

	return LineTo(sceneSettings.hdc, sceneSettings.x + lines.x2, sceneSettings.y + lines.y2);

}