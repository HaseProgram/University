#include "stdafx.h"

extern values Array[30];
double searchX;
double searchY;

int position()
{
	if (searchX <= Array[0].X)
	{
		return 0;
	}

	if (searchX >= Array[29].X)
	{
		return 29;
	}

	for (int i = 0; i < 29; i++)
	{
		if ((searchX >= Array[i].X) && (searchX < Array[i+1].X))
		{
			return i + 1;
		}
	}
}

void searchNodes()
{
	int pos = position();
}