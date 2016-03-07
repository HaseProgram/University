#include "stdafx.h"

values Array[30];

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

double getStartValue()
{
	TCHAR buf[10];
	return _wtof(valueFromTextField(ID_EDITBEGINX, buf));
}

void createSequence() {

	function f = myFunc();
	double start = getStartValue();

	for (int i = 0; i < 30; i++)
	{
		Array[i].X = i + start;
		Array[i].Y = f(Array[i].X);
		addDoubleItem(ID_TABLE, i, 0, i);
		addDoubleItem(ID_TABLE, i, 1, Array[i].X);
		addDoubleItem(ID_TABLE, i, 2, Array[i].Y);
	}
}