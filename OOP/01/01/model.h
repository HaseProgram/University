#pragma once

struct model init();

struct node* getNodeArray(struct model* modelSettings);
struct edge* getEdgeArray(struct model* modelSettings);
int getNodeArrayCount(struct node* nodeArray);
int getEdgeArrayCount(struct edge* edgeArray);
struct nodecoordinates* getNodeArrayItems(struct node* nodeArray);
struct edgecoordinates* getEdgeArrayItems(struct edge* edgeArray);


struct nodecoordinates
{
	double X, Y, Z;
};

struct edgecoordinates
{
	int node1, node2;
};

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
	struct node Node;
	struct edge Edge;
};
