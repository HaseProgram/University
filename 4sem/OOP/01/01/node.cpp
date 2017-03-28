#include "stdafx.h"
#include "node.h"

int getNodeArrayCount(struct node* nodeArray)
{
	return nodeArray->Number;
}

struct nodecoordinates* getNodeArrayItems(struct node* nodeArray)
{
	return nodeArray->Items;
}