#include "stdafx.h"
#include "model.h"
#include "loadmodel.h"
#include "convertstring.h"

char* get_model_name()
{
	char *modelFileName;
	char bufFileName[MAX_PATH * 2] = "";
	OPENFILENAME ofn;

	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = (LPCWSTR)TEXT("3D model (*.model)\0*.model\0 All files (*.*)\0*.*\0");
	ofn.lpstrFile = (LPWSTR)bufFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = (LPCWSTR)TEXT("Choose 3D model file");
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = (LPCWSTR)TEXT("*.model");

	if (GetOpenFileName(&ofn))
	{
		delete_zero_symbols(bufFileName);
		modelFileName = (char*)calloc(strlen(bufFileName) + 1, sizeof(char));
		strcpy(modelFileName, bufFileName);
		return modelFileName;
	}
	else
	{
		return NULL;
	}
}

int load_model(struct view* View)
{
	if (!View->Model.fileName)
	{
		return BAD_FILE_NAME;
	}
	View->Model.file = open_model(View->Model.fileName);
	if (!View->Model.file)
	{
		return CANT_OPEN_FILE;
	}
	int error = transfer(View);
	close_model(View->Model.file);
	return error;
}

int transfer(struct view* View)
{
	int error = OK;

	error = read_nodes_and_edges_number(View);
	if (error != OK)
		return error;
	error = read_nodes(View);
	if (error != OK)
		return error;
	error = read_edges(View);
	
	return error;
}

int allocate_nodes(struct view* View)
{
	View->Model.Node.Items = (nodecoordinates*)calloc(View->Model.Node.Number, sizeof(nodecoordinates));
	if (!View->Model.Node.Items)
	{
		return CANT_ALLOCATE_NODES;
	}
	else
	{
		return OK;
	}
}

void free_nodes(struct view* View)
{
	if (View->Model.Node.Items)
		free(View->Model.Node.Items);
	View->Model.Node.Number = 0;
}

int allocate_edges(struct view* View)
{
	View->Model.Edge.Items = (edgecoordinates*)calloc(View->Model.Edge.Number, sizeof(edgecoordinates));
	if (!View->Model.Edge.Items)
	{
		free_nodes(View);
		return CANT_ALLOCATE_EDGES;
	}
	else
	{
		return OK;
	}
}

void free_edges(struct view* View)
{
	if (View->Model.Edge.Items)
		free(View->Model.Edge.Items);
	View->Model.Edge.Number = 0;
}

int read_nodes_and_edges_number(struct view* View)
{
	if (fscanf_s(View->Model.file, "%d %d", &View->Model.Node.Number, &View->Model.Edge.Number) == 2)
		return OK;
	return BAD_NUMBERS_OF_ITEMS;
}

int read_nodes(struct view* View)
{
	double x, y, z;
	int error = allocate_nodes(View);
	if (error != OK)
		return error;
	
	for (int i = 0; (error == OK) && (i < View->Model.Node.Number); i++)
	{
		if (fscanf(View->Model.file, "%lf %lf %lf", &x, &y, &z) != 3)
		{
			error = BAD_NODES_PARAMS;
		}
		else
		{
			if (error == OK)
			{
				(View->Model.Node.Items + i)->X = x;
				(View->Model.Node.Items + i)->Y = y;
				(View->Model.Node.Items + i)->Z = z;
			}
		}
	}
	return error;
}

int read_edges(struct view* View)
{
	int n1, n2;
	int error = allocate_edges(View);
	if (error != OK)
	{
		free_nodes(View);
		return error;
	}

	for (int i = 0; (error == OK) && (i < View->Model.Edge.Number); i++)
	{
		if (fscanf(View->Model.file, "%d %d ", &n1, &n2) != 2 || 
			n1 < 0 || 
			n2 < 0 || 
			n1 > View->Model.Node.Number || 
			n2 > View->Model.Node.Number)
		{
			free_nodes(View);
			error = BAD_EDGES_PARAMS;
		}
		else
		{
			(View->Model.Edge.Items + i)->node1 = n1;
			(View->Model.Edge.Items + i)->node2 = n2;
		}
	}
	return error;
}

FILE* open_model(char* modelFileName)
{
	FILE* modelFile = fopen(modelFileName, "r");
	return modelFile;
}

void close_model(FILE* modelFile)
{
	fclose(modelFile);
}