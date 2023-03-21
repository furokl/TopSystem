#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include <algorithm>

#include "Console.h"

class Shape
{
	/*Point2D m_center;*/
protected:
	COORD pos;

public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	/*Shape(Point2D p)
		: m_center(p)
	{
	}*/
};

#endif

