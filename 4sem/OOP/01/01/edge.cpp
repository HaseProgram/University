#include "stdafx.h"
#include "edge.h"

int getEdgeArrayCount(struct edge* edgeArray)
{
	return edgeArray->Number;
}

struct edgecoordinates* getEdgeArrayItems(struct edge* edgeArray)
{
	return edgeArray->Items;
}