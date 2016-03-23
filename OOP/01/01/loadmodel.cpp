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

int load_model(struct model* modelSettings)
{
	if (!modelSettings->fileName)
	{
		return BAD_FILE_NAME;
	}
	modelSettings->file = open_modelfile(modelSettings->fileName);
	if (!modelSettings->file)
	{
		return CANT_OPEN_FILE;
	}
	int error = transfer(modelSettings);
	close_modelfile(modelSettings->file);
	return error;
}

int transfer(struct model* modelSettings)
{
	int error = OK;

	error = read_nodes_and_edges_number(modelSettings);
	if (error != OK)
		return error;
	error = read_nodes(modelSettings);
	if (error != OK)
		return error;
	error = read_edges(modelSettings);
	
	return error;
}

int allocate_nodes(struct node* nodeArray)
{
	nodeArray->Items = (nodecoordinates*)calloc(nodeArray->Number, sizeof(nodecoordinates));
	if (!nodeArray->Items)
	{
		return CANT_ALLOCATE_NODES;
	}
	else
	{
		return OK;
	}
}

void free_nodes(struct node* nodeArray)
{
	if (nodeArray->Items)
		free(nodeArray->Items);
	nodeArray->Items = NULL;
	nodeArray->Number = 0;
}

int allocate_edges(struct edge* edgeArray)
{
	edgeArray->Items = (edgecoordinates*)calloc(edgeArray->Number, sizeof(edgecoordinates));
	if (!edgeArray->Items)
	{
		return CANT_ALLOCATE_EDGES;
	}
	else
	{
		return OK;
	}
}

void free_edges(struct edge* edgeArray)
{
	if (edgeArray->Items)
		free(edgeArray->Items);
	edgeArray->Items = NULL;
	edgeArray->Number = 0;
}

int read_nodes_and_edges_number(struct model* modelSettings)
{
	struct node* nodeArray = &modelSettings->Node;
	struct edge* edgeArray = &modelSettings->Edge;

	if (fscanf(modelSettings->file, "%d %d\n", &nodeArray->Number, &edgeArray->Number) == 2)
		return OK;
	return BAD_NUMBERS_OF_ITEMS;
}

int read_nodes(struct model* modelSettings)
{
	double x, y, z;
	struct node* nodeArray = &modelSettings->Node;

	int error = allocate_nodes(nodeArray);
	if (error != OK)
		return error;

	nodecoordinates* nodeCoordinates;
	nodeCoordinates = nodeArray->Items;
	
	for (int i = 0; (error == OK) && (i < nodeArray->Number); i++)
	{
		if (fscanf(modelSettings->file, "%lf %lf %lf", &x, &y, &z) != 3)
		{
			error = BAD_NODES_PARAMS;
		}
		else
		{
			if (error == OK)
			{
				nodeCoordinates[i].X = x;
				nodeCoordinates[i].Y = y;
				nodeCoordinates[i].Z = z;
			}
		}
	}
	return error;
}

int read_edges(struct model* modelSettings)
{
	int n1, n2;

	struct node* nodeArray = &modelSettings->Node;
	struct edge* edgeArray = &modelSettings->Edge;

	int error = allocate_edges(edgeArray);
	if (error != OK)
	{
		free_nodes(nodeArray);
		return error;
	}

	edgecoordinates* edgeCoordinates;
	edgeCoordinates = edgeArray->Items;

	for (int i = 0; (error == OK) && (i < edgeArray->Number); i++)
	{
		if (fscanf(modelSettings->file, "%d %d ", &n1, &n2) != 2 ||
			n1 < 0 || 
			n2 < 0 || 
			n1 > nodeArray->Number ||
			n2 > nodeArray->Number)
		{
			free_nodes(nodeArray);
			error = BAD_EDGES_PARAMS;
		}
		else
		{
			edgeCoordinates[i].node1 = n1;
			edgeCoordinates[i].node2 = n2;
		}
	}
	return error;
}

void close_model(struct model* modelSettings)
{
	struct node* nodeArray = &modelSettings->Node;
	struct edge* edgeArray = &modelSettings->Edge;

	free_nodes(nodeArray);
	free_edges(edgeArray);
	free(modelSettings->fileName);
	modelSettings->fileName = NULL;
}

FILE* open_modelfile(char* modelFileName)
{
	FILE* modelFile = fopen(modelFileName, "r");
	return modelFile;
}

void close_modelfile(FILE* modelFile)
{
	fclose(modelFile);
}