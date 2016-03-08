#include "stdafx.h"

extern values* Array;

int position(double x)
{
	if (x <= Array[0].X)
	{
		return 0;
	}

	if (x >= Array[29].X)
	{
		return 29;
	}

	for (int i = 0; i < 29 - 1; i++)
	{
		if ((x >= Array[i].X) && (x < Array[i + 1].X))
		{
			return i;
		}
	}

	return -1;
}

Range findRange(int polynom, double x)
{
	Range range;

	int pos = position(x);

	if (polynom % 2 == 0)
	{
		range.up = range.down = polynom / 2;
	}
	else
	{
		range.up = polynom / 2 + 1;
		range.down = polynom / 2;
	}


	if ((pos - range.down) < 0)
	{
		range.down = 0;
		range.up = polynom;
	}
	else if ((pos + range.down) > (29))
	{
		range.up = 29 - 1;
		range.down = 29 - 1 - polynom;
	}
	else
	{
		range.up = pos + range.up;
		range.down = pos - range.down;
	}

	return range;
}

double newton_method(double x, int polynom)
{
	Range range = findRange(polynom, x);

	double res = Array[range.down].Y, F, den;

	int i, j, k;

	for (i = range.down + 1; i <= range.up; i++)
	{
		F = 0.0;

		for (j = range.down; j <= i; j++)
		{
			den = 1.0;

			for (k = range.down; k <= i; k++)
			{
				if (k != j)
				{
					den *= (Array[j].X - Array[k].X);
				}

			}

			F += (Array[j].Y / den);
		}

		for (k = range.down; k < i; k++)
		{
			F *= (x - Array[k].X);
		}

		res += F;

	}

	return res;

}