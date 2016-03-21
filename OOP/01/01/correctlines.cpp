#include "stdafx.h"
#include "correctlines.h"
#include "model.h"
#include "draw.h"


void reverse_y(struct line* lines, int height)
{
	lines->y1 = height - lines->y1;
	lines->y2 = height - lines->y2;
}
