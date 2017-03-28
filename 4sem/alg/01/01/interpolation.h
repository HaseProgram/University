#pragma once
typedef struct {
	int up, down;
} Range;

int position(double x);
Range findRange(int polynom, double x);
double newton_method(double x, int polynom);