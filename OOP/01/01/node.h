#pragma once
#include "nodecoordinates.h"


int getNodeArrayCount(struct node* nodeArray);
struct nodecoordinates* getNodeArrayItems(struct node* nodeArray);


struct node
{
	int Number;
	nodecoordinates* Items;
};