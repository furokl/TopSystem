#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape
{
private:
	std::array<Point2D, 2> p;

public:
    /*Rectangle(const Point2D &p1, const Point2D &p2)
		: p({ p1, p2 })
	{
	}
	Rectangle(std::array<Point2D, 4> &pArray)
		: p(pArray)
	{
	}*/
};

#endif RECTANGLE_H

