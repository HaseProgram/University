#pragma once

typedef struct
{
	double x;
	double y;
} point;


typedef struct
{
	point dot[50];
} coordinates;

typedef struct
{
	point dot[3];

} triangle;

typedef struct
{
	point center;
	double r;
} circle;