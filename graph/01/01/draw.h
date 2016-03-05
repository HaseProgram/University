#pragma once

typedef struct
{
	double x;
	double y;
} point;

typedef struct
{
	point ar[4];
} arc;


typedef struct
{
	point el[12];
} ellipse;

typedef struct
{
	point li[2];
} line;


struct clock
{
	ellipse headCircle;

	arc topHead;
	arc bottomHead;
	line leftHead;
	line rightHead;

	ellipse mainCircle;

	line twelve;
	line three;
	line six;
	line nine;

	line firstArrow;
	line secondArrow;

	line leftLeg;
	line rightLeg;
};


void initClock();
void draw(HDC paper);
void drawCircle(HDC paper, ellipse circle);
void drawArc(HDC paper, arc arcline);
void drawLine(HDC paper, line arrow);
void moveClock(double mX, double mY);
void scale(point* coordArray, int len, double proportions, double X, double Y);
void scaleClock(double proportions, double X, double Y);
void rotate(point* coordArray, int len, double X, double Y, double A);
void rotateClock(double X, double Y, double A);
void reset();