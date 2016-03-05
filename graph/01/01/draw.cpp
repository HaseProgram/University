#include "stdafx.h"

double DX = 0, DY = 0;

double centerX = cX;
double centerY = cY;
double HEIGHT = 800;

extern struct clock cl;

point center = {0,0};

void initClock()
{
	//Head circle
	cl.headCircle.el[0].x = -20;
	cl.headCircle.el[0].y = 170;

	cl.headCircle.el[1].x = -20;
	cl.headCircle.el[1].y = 182;

	cl.headCircle.el[2].x = -12;
	cl.headCircle.el[2].y = 190;

	cl.headCircle.el[3].x = 0;
	cl.headCircle.el[3].y = 190;

	cl.headCircle.el[4].x = 12;
	cl.headCircle.el[4].y = 190;

	cl.headCircle.el[5].x = 20;
	cl.headCircle.el[5].y = 182;

	cl.headCircle.el[6].x = 20;
	cl.headCircle.el[6].y = 170;

	cl.headCircle.el[7].x = 20;
	cl.headCircle.el[7].y = 158;
	cl.headCircle.el[8].x = 12;
	cl.headCircle.el[8].y = 150;
	cl.headCircle.el[9].x = 0;
	cl.headCircle.el[9].y = 150;
	cl.headCircle.el[10].x = -12;
	cl.headCircle.el[10].y = 150;
	cl.headCircle.el[11].x = -20;
	cl.headCircle.el[11].y = 158;
	//Head circle

	//Top+bottom arc
	
	cl.topHead.ar[0].x = -80;
	cl.topHead.ar[0].y = 120;
	cl.topHead.ar[1].x = -80;
	cl.topHead.ar[1].y = 160;
	cl.topHead.ar[2].x = 80;
	cl.topHead.ar[2].y = 160;
	cl.topHead.ar[3].x = 80;
	cl.topHead.ar[3].y = 120;

	cl.bottomHead.ar[0].x = -80;
	cl.bottomHead.ar[0].y = 90;
	cl.bottomHead.ar[1].x = -80;
	cl.bottomHead.ar[1].y = 130;
	cl.bottomHead.ar[2].x = 80;
	cl.bottomHead.ar[2].y = 130;
	cl.bottomHead.ar[3].x = 80;
	cl.bottomHead.ar[3].y = 90;

	//Top+bottom arc

	//Left+right head
	cl.leftHead.li[0].x = -80;
	cl.leftHead.li[0].y = 122;
	cl.leftHead.li[1].x = -80;
	cl.leftHead.li[1].y = 93;

	cl.rightHead.li[0].x = 80;
	cl.rightHead.li[0].y = 122;
	cl.rightHead.li[1].x = 80;
	cl.rightHead.li[1].y = 93;
	//Left+right head

	//Central circle
	cl.mainCircle.el[0].x = -100;
	cl.mainCircle.el[0].y = 0;
	cl.mainCircle.el[1].x = -100;
	cl.mainCircle.el[1].y = 60;
	cl.mainCircle.el[2].x = -60;
	cl.mainCircle.el[2].y = 100;
	cl.mainCircle.el[3].x = 0;
	cl.mainCircle.el[3].y = 100;
	cl.mainCircle.el[4].x = 60;
	cl.mainCircle.el[4].y = 100;
	cl.mainCircle.el[5].x = 100;
	cl.mainCircle.el[5].y = 60;
	cl.mainCircle.el[6].x = 100;
	cl.mainCircle.el[6].y = 0;
	cl.mainCircle.el[7].x = 100;
	cl.mainCircle.el[7].y = -60;
	cl.mainCircle.el[8].x = 60;
	cl.mainCircle.el[8].y = -100;
	cl.mainCircle.el[9].x = 0;
	cl.mainCircle.el[9].y = -100;
	cl.mainCircle.el[10].x = -60;
	cl.mainCircle.el[10].y = -100;
	cl.mainCircle.el[11].x = -100;
	cl.mainCircle.el[11].y = -60;
	//Central circle

	//Clock lines
	cl.twelve.li[0].x = 0;
	cl.twelve.li[0].y = 100;
	cl.twelve.li[1].x = 0;
	cl.twelve.li[1].y = 85;

	cl.three.li[0].x = 85;
	cl.three.li[0].y = 0;
	cl.three.li[1].x = 100;
	cl.three.li[1].y = 0;

	cl.six.li[0].x = 0;
	cl.six.li[0].y = -85;
	cl.six.li[1].x = 0;
	cl.six.li[1].y = -100;

	cl.nine.li[0].x = -100;
	cl.nine.li[0].y = 0;
	cl.nine.li[1].x = -85;
	cl.nine.li[1].y = 0;
	//Clock lines

	//Arrows
	cl.firstArrow.li[0].x = 0;
	cl.firstArrow.li[0].y = 0;
	cl.firstArrow.li[1].x = 0;
	cl.firstArrow.li[1].y = 75;

	cl.secondArrow.li[0].x = 0;
	cl.secondArrow.li[0].y = 0;
	cl.secondArrow.li[1].x = 55;
	cl.secondArrow.li[1].y = 0;
	//Arrows

	//Legs
	cl.leftLeg.li[0].x = -60;
	cl.leftLeg.li[0].y = -120;
	cl.leftLeg.li[1].x = -40;
	cl.leftLeg.li[1].y = -92;

	cl.rightLeg.li[0].x = 60;
	cl.rightLeg.li[0].y = -120;
	cl.rightLeg.li[1].x = 40;
	cl.rightLeg.li[1].y = -92;
	//Legs
}

void draw(HDC paper)
{
	drawCircle(paper, cl.headCircle);

	drawArc(paper, cl.topHead);
	drawLine(paper, cl.leftHead);
	drawLine(paper, cl.rightHead);
	drawArc(paper, cl.bottomHead);

	drawCircle(paper, cl.mainCircle);
	drawLine(paper, cl.twelve);
	drawLine(paper, cl.three);
	drawLine(paper, cl.six);
	drawLine(paper, cl.nine);
	drawLine(paper, cl.firstArrow);
	drawLine(paper, cl.secondArrow);

	drawLine(paper, cl.leftLeg);
	drawLine(paper, cl.rightLeg);
}

void drawCircle(HDC paper, ellipse circle)
{
	POINT drCircle[13];
	remap(circle.el,drCircle,centerX,centerY, HEIGHT, 12);
	drCircle[12] = drCircle[0];
	PolyBezier(paper,drCircle,13);
}

void drawArc(HDC paper, arc arcline)
{
	POINT drArc[4];
	remap(arcline.ar, drArc, centerX, centerY, HEIGHT, 4);
	PolyBezier(paper, drArc,4);
}

void drawLine(HDC paper, line arrow)
{
	POINT drArrow[2];
	remap(arrow.li, drArrow, centerX, centerY, HEIGHT, 2);
	MoveToEx(paper, drArrow[0].x, drArrow[0].y, NULL);
	LineTo(paper, drArrow[1].x, drArrow[1].y);
}

void moveClock(double mX, double mY)
{
	centerX += mX;
	centerY += mY;
}

void scaleClock(double proportions, double X, double Y)
{
	scale(cl.headCircle.el,12, proportions, X, Y);

	scale(cl.topHead.ar,4, proportions, X, Y);
	scale(cl.bottomHead.ar,4, proportions, X, Y);
	scale(cl.leftHead.li,2, proportions, X, Y);
	scale(cl.rightHead.li,2, proportions, X, Y);

	scale(cl.mainCircle.el,12, proportions, X, Y);

	scale(cl.twelve.li,2, proportions, X, Y);
	scale(cl.three.li,2, proportions, X, Y);
	scale(cl.six.li,2, proportions, X, Y);
	scale(cl.nine.li,2, proportions, X, Y);

	scale(cl.firstArrow.li,2, proportions, X, Y);
	scale(cl.secondArrow.li,2, proportions, X, Y);

	scale(cl.leftLeg.li,2, proportions, X, Y);
	scale(cl.rightLeg.li,2, proportions, X, Y);
}


void scale(point* coordArray, int len, double proportions, double X, double Y)
{
	for (int i = 0; i < len; i++)
	{
		coordArray[i].x = floor(X*(1 - proportions) + proportions*coordArray[i].x);
		coordArray[i].y = floor(Y*(1 - proportions) + proportions*coordArray[i].y);
	}
}

void rotateClock(double X, double Y, double A)
{
	rotate(cl.headCircle.el, 12, X, Y, A);

	rotate(cl.topHead.ar, 4, X, Y, A);
	rotate(cl.bottomHead.ar, 4, X, Y, A);
	rotate(cl.leftHead.li, 2, X, Y, A);
	rotate(cl.rightHead.li, 2, X, Y, A);

	rotate(cl.mainCircle.el, 12, X, Y, A);

	rotate(cl.twelve.li, 2, X, Y, A);
	rotate(cl.three.li, 2, X, Y, A);
	rotate(cl.six.li, 2, X, Y, A);
	rotate(cl.nine.li, 2, X, Y, A);

	rotate(cl.firstArrow.li, 2, X, Y, A);
	rotate(cl.secondArrow.li, 2, X, Y, A);

	rotate(cl.leftLeg.li, 2, X, Y, A);
	rotate(cl.rightLeg.li, 2, X, Y, A);
}

void rotate(point* coordArray, int len, double X, double Y, double A)
{
	double tempX, tempY;
	for (int i = 0; i < len; i++)
	{
		tempX = coordArray[i].x;
		tempY = coordArray[i].y;
		coordArray[i].x = X + ((tempX - X)*cos(A) + (tempY - Y)*sin(A));
		coordArray[i].y = Y + ((tempY - Y)*cos(A) - (tempX - X)*sin(A));
	}
}

void reset()
{
	initClock();
	centerX = cX;
	centerY = cY;
}