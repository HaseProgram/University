#pragma once

enum e_command
{
	LOAD, QUIT, DRAW, MODIFY
};

typedef struct
{
	double X, Y, Z;
} nodecoordinates;

typedef struct
{
	int node1, node2;
} edgecoordinates;

struct node
{
	int Number;
	nodecoordinates* Items;
};

struct edge
{
	int Number;
	edgecoordinates* Items;
};

struct model
{
	char* fileName;
	FILE* file;
	struct node Node;
	struct edge Edge;
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

struct view
{
	struct model Model;
	struct context_params Scene;
	//struct modification_params Modification;
};