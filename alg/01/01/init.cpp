#include "stdafx.h"

extern int currentFunction;
extern values Array[30];

double x2(double x)
{
	return pow(x, 2);
}

function myFunc()
{
	switch (currentFunction)
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

double getStartValue()
{
	TCHAR buf[10];
	return _wtof(valueFromTextField(ID_EDITBEGINX, buf));
}

values* createSequence() {

	function f = myFunc();
	double start = getStartValue();

	int kostyl = currentFunction;						// best code ever

	for (int i = 0; i < 30; i++)
	{
		Array[i].X = i + start;
		Array[i].Y = f(Array[i].X);
		addDoubleItem(ID_TABLE, i, 0, i);
		addDoubleItem(ID_TABLE, i, 1, Array[i].X);
		addDoubleItem(ID_TABLE, i, 2, Array[i].Y);
	}

	currentFunction = kostyl;							// best code ever

	return Array;
}