#pragma once
#include "edgecoordinates.h"

int getEdgeArrayCount(struct edge* edgeArray);
struct edgecoordinates* getEdgeArrayItems(struct edge* edgeArray);

struct edge
{
	int Number;
	edgecoordinates* Items;
};