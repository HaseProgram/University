#include "stdafx.h"


void remap(point *MyPoint, POINT *NewMyPoint, double centerX, double centerY, double HEIGHT, int arrLen)
{	
	for (int i = 0; i < arrLen; i++)
	{
		NewMyPoint[i].x = MyPoint[i].x + centerX;
		NewMyPoint[i].y = HEIGHT - (centerY + MyPoint[i].y);
	}
}
