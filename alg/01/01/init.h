#pragma once

typedef double(*function)(double);
typedef struct {
	double X;
	double Y;
} values;

double x2(double x);
function myFunc();
double getStartValue();
void createSequence();
void interface(HWND hWnd, EDIT settings);