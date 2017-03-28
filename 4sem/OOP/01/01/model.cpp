#include "stdafx.h"
#include "model.h"

struct model init()
{
	struct model Model;
	struct edge* Edge = &Model.Edge;
	struct node* Node = &Model.Node;
	Edge->Items = NULL;
	Edge->Number = 0;
	Node->Items = NULL;
	Node->Number = 0;
	return Model;
}


struct node* getNodeArray(struct model* modelSettings)
{
	return &modelSettings->Node;
}

struct edge* getEdgeArray(struct model* modelSettings)
{
	return &modelSettings->Edge;
}