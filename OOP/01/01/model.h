#pragma once
#include "edge.h"
#include "node.h"

struct model init();

struct node* getNodeArray(struct model* modelSettings);
struct edge* getEdgeArray(struct model* modelSettings);




struct model
{
	struct node Node;
	struct edge Edge;
};
