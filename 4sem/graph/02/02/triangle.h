#pragma once

BOOL searchTriangle(point *coordinatesArray, triangle *tr, int dotsCount);
double calcTrArea(point dot1, point dot2, point dot3);
double calcCrArea(point dot1, point dot2, point dot3);
double getSide(point dot1, point dot2);

bool dotsOneLine(point dot1, point dot2, point dot3);

circle getCircle(triangle myTr);