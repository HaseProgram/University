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

int load_model(struct model* modelSettings, char* filename)
{
	if (!filename)
	{
		return BAD_FILE_NAME;
	}

	FILE* modelFile = open_modelfile(filename);

	if (!modelFile)
	{
		return CANT_OPEN_FILE;
	}
	int error = transfer(modelSettings, modelFile);
	close_modelfile(modelFile);
	return error;
}

int transfer(struct model* modelSettings, FILE* modelFile)
{
	int error = OK;

	error = read_nodes_and_edges_number(modelSettings, modelFile);
	if (error != OK)
		return error;
	error = read_nodes(modelSettings, modelFile);
	if (error != OK)
		return error;
	error = read_edges(modelSettings, modelFile);
	
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

int read_nodes_and_edges_number(struct model* modelSettings, FILE* modelFile)
{
	struct node* nodeArray = getNodeArray(modelSettings);
	struct edge* edgeArray = getEdgeArray(modelSettings);

	if (fscanf(modelFile, "%d %d\n", &nodeArray->Number, &edgeArray->Number) == 2)
		return OK;
	return BAD_NUMBERS_OF_ITEMS;
}

int read_nodes(struct model* modelSettings, FILE* modelFile)
{
	double x, y, z;
	struct node* nodeArray = getNodeArray(modelSettings);

	int error = allocate_nodes(nodeArray);
	if (error != OK)
		return error;

	nodecoordinates* nodeCoordinates = getNodeArrayItems(nodeArray);
	
	for (int i = 0; (error == OK) && (i < getNodeArrayCount(nodeArray)); i++)
	{
		if (fscanf(modelFile, "%lf %lf %lf", &x, &y, &z) != 3)
		{
			free_nodes(nodeArray);
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

int read_edges(struct model* modelSettings, FILE* modelFile)
{
	int n1, n2;

	struct node* nodeArray = getNodeArray(modelSettings);
	struct edge* edgeArray = getEdgeArray(modelSettings);

	int error = allocate_edges(edgeArray);
	if (error != OK)
	{
		free_nodes(nodeArray);
		return error;
	}

	edgecoordinates* edgeCoordinates = getEdgeArrayItems(edgeArray);

	for (int i = 0; (error == OK) && (i < getEdgeArrayCount(edgeArray)); i++)
	{
		if (fscanf(modelFile, "%d %d ", &n1, &n2) != 2 ||
			n1 < 0 || 
			n2 < 0 || 
			n1 > getNodeArrayCount(nodeArray) ||
			n2 > getNodeArrayCount(nodeArray))
		{
			free_nodes(nodeArray);
			free_edges(edgeArray);
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

void close_model(struct model* modelSettings, char** fileName)
{
	struct node* nodeArray = getNodeArray(modelSettings);
	struct edge* edgeArray = getEdgeArray(modelSettings);

	free_nodes(nodeArray);
	free_edges(edgeArray);
	*fileName = NULL;
}

FILE* open_modelfile(char* modelFileName)
{
	return fopen(modelFileName, "r");
}

void close_modelfile(FILE* modelFile)
{
	fclose(modelFile);
}