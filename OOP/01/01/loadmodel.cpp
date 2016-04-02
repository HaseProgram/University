#include "stdafx.h"
#include "model.h"
#include "loadmodel.h"

int load_model(struct model* modelSettings, char* filename)
{
	struct model bufModelSettings;
	if (!filename)
	{
		return BAD_FILE_NAME;
	}

	LFILE modelFile = open_modelfile(filename);

	if (!modelFile)
	{
		return CANT_OPEN_FILE;
	}
	int error = transfer(&bufModelSettings, modelFile);
	close_modelfile(modelFile);
	if (error == OK)
	{
		close_model(modelSettings, NULL);
		*modelSettings = bufModelSettings;
	}

	return error;
}

int allocate_memory(model* modelSettings, struct node** nodeArray, struct edge** edgeArray)
{
	*nodeArray = getNodeArray(modelSettings);
	*edgeArray = getEdgeArray(modelSettings);
	int error = OK;
	error = allocate_nodes(*nodeArray);
	if (error != OK)
	{
		return error;
	}
	error = allocate_edges(*edgeArray);
	if (error != OK)
	{
		free_nodes(*nodeArray);
	}
	return error;
}

int free_memory(struct node* nodeArray, struct edge* edgeArray)
{
	free_nodes(nodeArray);
	free_edges(edgeArray);
}

int read_from_file(model* modelSettings, LFILE modelFile, struct node* nodeArray, struct edge* edgeArray)
{
	int error = read_nodes(modelSettings, modelFile);
	if (error != OK)
	{
		return error;
	}
	error = read_edges(modelSettings, modelFile);
	return error;
}

int transfer(struct model* modelSettings, LFILE modelFile)
{
	int error = OK;

	error = read_nodes_and_edges_number(modelSettings, modelFile);
	if (error != OK)
		return error;

	node* nodeArray;
	edge* edgeArray;

	error = allocate_memory(modelSettings, &nodeArray, &edgeArray);
	if (error != OK)
	{
		return error;
	}

	error = read_from_file(modelSettings, modelFile, nodeArray, edgeArray);
	if (error != OK)
	{
		free_memory(nodeArray, edgeArray);
	}
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

int read_nodes_and_edges_number(struct model* modelSettings, LFILE modelFile)
{
	struct node* nodeArray = getNodeArray(modelSettings);
	struct edge* edgeArray = getEdgeArray(modelSettings);

	if (fscanf(modelFile, "%d %d\n", &nodeArray->Number, &edgeArray->Number) == 2)
		return OK;
	return BAD_NUMBERS_OF_ITEMS;
}

int read_nodes(struct model* modelSettings, LFILE modelFile)
{
	double x, y, z;

	int error = OK;
	struct node* nodeArray = getNodeArray(modelSettings);
	nodecoordinates* nodeCoordinates = getNodeArrayItems(nodeArray);
	
	for (int i = 0; (error == OK) && (i < getNodeArrayCount(nodeArray)); i++)
	{
		if (fscanf(modelFile, "%lf %lf %lf", &x, &y, &z) != 3)
		{
			error = BAD_NODES_PARAMS;
		}
		else
		{
			if (error == OK)
			{
				setNodeCoordinates(nodeCoordinates + i,x,y,z);
			}
		}
	}
	return error;
}

int read_edges(struct model* modelSettings, LFILE modelFile)
{
	int n1, n2;
	int error = OK;

	struct edge* edgeArray = getEdgeArray(modelSettings);
	struct node* nodeArray = getNodeArray(modelSettings);
	edgecoordinates* edgeCoordinates = getEdgeArrayItems(edgeArray);

	for (int i = 0; error == OK && i < getEdgeArrayCount(edgeArray); i++)
	{
		if (fscanf(modelFile, "%d %d ", &n1, &n2) != 2 ||
			n1 < 0 || 
			n2 < 0 || 
			n1 > getNodeArrayCount(nodeArray) ||
			n2 > getNodeArrayCount(nodeArray))
		{
			error = BAD_EDGES_PARAMS;
		}
		else
		{
			setEdgeCoordinates(edgeCoordinates + i, n1, n2);
		}
	}
	return error;
}

int close_model(struct model* modelSettings, char** fileName)
{
	struct node* nodeArray = getNodeArray(modelSettings);
	struct edge* edgeArray = getEdgeArray(modelSettings);

	free_nodes(nodeArray);
	free_edges(edgeArray);
	
	if (fileName != NULL)
	{
		*fileName = NULL;
	}
	return OK;
}

LFILE open_modelfile(char* modelFileName)
{
	return fopen(modelFileName, "r");
}

void close_modelfile(LFILE modelFile)
{
	fclose(modelFile);
}