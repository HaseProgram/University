#include "stdafx.h"

triangle tr;

BOOL searchTriangle(point *coordinatesArray, triangle *tr, int dotsCount)
{
	point firstDot;
	point secondDot;
	point thirdDot;

	double triangleArea;
	double circleArea;
	double areaDifference = -1;

	bool found = FALSE;

	for (int firstDotI = 0; firstDotI < dotsCount - 2; firstDotI++)
	{
		firstDot = coordinatesArray[firstDotI];
		for (int secondDotI = firstDotI + 1; secondDotI < dotsCount - 1; secondDotI++)
		{
			secondDot = coordinatesArray[secondDotI];
			for (int thirdDotI = secondDotI + 1; thirdDotI < dotsCount; thirdDotI++)
			{
				thirdDot = coordinatesArray[thirdDotI];
				triangleArea = calcTrArea(firstDot, secondDot, thirdDot);
				circleArea = calcCrArea(firstDot, secondDot, thirdDot);
				if (areaDifference < 0 || abs(triangleArea - circleArea) < areaDifference)
				{
					if (!dotsOneLine(firstDot, secondDot, thirdDot))
					{
						areaDifference = abs(triangleArea - circleArea);
						tr->dot[0] = firstDot;
						tr->dot[1] = secondDot;
						tr->dot[2] = thirdDot;
						found = TRUE;
					}
				}
			}
		}
	}
	return found;
}

circle getCircle(triangle myTr)
{
	double x1 = myTr.dot[0].x;
	double y1 = myTr.dot[0].y;
	double x2 = myTr.dot[1].x;
	double y2 = myTr.dot[1].y;
	double x3 = myTr.dot[2].x;
	double y3 = myTr.dot[2].y;
	double a = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	double b = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
	double c = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
	double p = (a + b + c) / 2;
	double S = 0.5 * abs(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)));
	double r = S / p;
	double x0 = (b*x1 + c*x2 + a*x3) / (a + b + c);
	double y0 = (b*y1 + c*y2 + a*y3) / (a + b + c);
	circle myCir;
	myCir.center.x = x0;
	myCir.center.y = y0;
	myCir.r = r;
	return myCir;
}

double calcTrArea(point dot1, point dot2, point dot3)
{
	double side1 = getSide(dot1, dot2);
	double side2 = getSide(dot2, dot3);
	double side3 = getSide(dot3, dot1);

	double halfP = (side1 + side2 + side3) / 2;
	return sqrt(
		halfP*(halfP - side1) * (halfP - side2) * (halfP - side3)
	);
}

double calcCrArea(point dot1, point dot2, point dot3)
{
	double side1 = getSide(dot1, dot2);
	double side2 = getSide(dot2, dot3);
	double side3 = getSide(dot3, dot1);

	double halfP = (side1 + side2 + side3) / 2;
	return 3.14 * (halfP - side1) * (halfP - side2) * (halfP - side3) / halfP;
}

double getSide(point dot1, point dot2)
{
	return sqrt(
		pow((dot2.x - dot1.x) ,2) + pow((dot2.y - dot1.y) ,2)
	);
}

bool dotsOneLine(point dot1, point dot2, point dot3)
{
	return ((dot1.x - dot3.x) * (dot2.y - dot3.y) - (dot2.x - dot3.x) *	(dot1.y - dot3.y)) == 0;
}