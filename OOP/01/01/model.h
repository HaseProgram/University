#pragma once

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

enum modification_type
{
	ROTATE_XZ, ROTATE_XY, ZOOM
};

struct modification_params
{
	enum modification_type type;
	double param;
};

struct view
{
	struct model Model;
	struct context_params Scene;
	struct modification_params Modification;
};