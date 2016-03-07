#include "stdafx.h"

double x2(double x)
{
	return pow(x, 2);
}

function myFunc()
{
	switch (currentItem())
	{
	case 0:
		return sin;
		break;
	case 1:
		return x2;
		break;
	case 2:
		return log;
		break;
	default:
		return sin;
		break;
	}
}

void createSequence() {
	function f = myFunc();

}