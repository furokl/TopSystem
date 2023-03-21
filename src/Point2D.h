#ifndef POINT2D_H
#define POINT2D_H

#include "Constants.h"

struct Point2D
{
	short x, y;
	Point2D(short x, short y)
    {
		this->x = x * cnst::aspect * cnst::pixelAspect;
		this->y = y;
    }
};

#endif