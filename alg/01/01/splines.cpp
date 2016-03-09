#include "stdafx.h"

extern values* Array;

Spline* buildSpline()
{
	int i;

	Spline* splines;
	splines = (Spline*)malloc(30 * sizeof(Spline));

	for (i = 0; i < 30; i++)
	{
		splines[i].x = Array[i].X;
		splines[i].a = Array[i].Y;
	}

	splines[0].c = 0;

	//Вычисление прогоночных коэффицинтов(прямой ход прогонки)
	double *ksi = (double*)malloc((29) * sizeof(double));
	double *teta = (double*)malloc((29) * sizeof(double));
	ksi[0] = teta[0] = 0;

	double A, B, C, F, h_i, h_i1, z;

	for (i = 1; i < 29; ++i)

	{
		h_i = Array[i].X - Array[i - 1].X;
		h_i1 = Array[i + 1].X - Array[i].X;

		A = h_i;
		B = h_i1;
		C = 2.0 * (h_i + h_i1);
		F = 6.0 * ((Array[i + 1].Y - Array[i].Y) / h_i1 - (Array[i].Y - Array[i - 1].Y) / h_i);

		z = (A * ksi[i - 1] + C);

		ksi[i] = -B / z;
		teta[i] = (F - A * teta[i - 1]) / z;
	}

	splines[29].c = (F - A * teta[28]) / (C + A * ksi[28]);

	//Нахождение решения(обратный ход прогонки)
	for (i = 28; i >= 0; i--)
	{
		splines[i].c = ksi[i] * splines[i + 1].c + teta[i];
	}

	free(ksi);
	free(teta);

	//По известным с[i] находим значения b[i] и d[i]
	for (i = 29; i >= 0; --i)
	{
		h_i = Array[i].X - Array[i - 1].X;

		splines[i].d = (splines[i].c - splines[i - 1].c) / h_i;
		splines[i].b = h_i * (2.0 * splines[i].c + splines[i - 1].c) / 6.0 + (Array[i].Y - Array[i - 1].Y)
			/ h_i;
	}

	return splines;
}



double splines_method(double x)
{
	Spline *s, *splines;
	int i = 0, j = 29;

	splines = buildSpline();

	//Если х лежит между граничными точками сетки, производим бианарный поиск нужного эл-та
	//массива
	if (x <= splines[0].x)
	{
		s = splines + 1;
	}
	else if (x >= splines[29].x)
	{
		s = splines + 29;
	}
	else
	{
		while (i + 1 < j)
		{
			int k = i + (j - i) / 2;

			if (x <= splines[k].x)
			{
				j = k;
			}
			else
			{
				i = k;
			}
		}

		s = splines + j;
	}

	double dx = (x - s->x);


	return s->a + (s->b + (s->c / 2.0 + s->d * dx / 6.0) * dx) * dx;
}
