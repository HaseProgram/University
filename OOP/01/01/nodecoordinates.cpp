#include "stdafx.h"
#include "nodecoordinates.h"

void setNodeCoordinates(nodecoordinates* srcDest, double x, double y, double z)
{
	srcDest->X = x;
	srcDest->Y = y;
	srcDest->Z = z;
}