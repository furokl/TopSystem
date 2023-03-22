#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <cmath>

class Triangle: public Shape
{
private:
	std::array<Point2D, 3> p;

public:
	Triangle(const Point2D &p1, const Point2D &p2, const Point2D &p3)
		: p({ p1, p2, p3 })
	{
	}
	Triangle(std::array<Point2D, 3> &pArray)
		: p(pArray)
	{
	}

	bool isBelong(Point2D p0);
	virtual void show() override;
};

#endif TRIANGLE_H

