#pragma once

enum e_command
{
	LOAD, QUIT, DRAW, MODIFY
};

struct node
{
	int Number;
	double* Item;
};

struct edge
{
	int Number;
	int* Item;
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
	int height;
	int width;
};

struct view
{
	struct model Model;
	struct context_params Scene;
	//struct modification_params Modification;
};