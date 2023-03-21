#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape
{
protected:
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

    // (x1-x0) * (y2-y1) - (x2-x1) * (y1-y0) > 0 &&
    // (x2-x0) * (y3-y2) - (x3-x2) * (y2-y0) > 0 &&
    // (x3-x0) * (y1-y3) - (x1-x3) * (y3-y0) > 0
	bool isBelong(Point2D p0) {
		short a = (p[0].x - p0.x) * (p[1].y - p[0].y) -
				  (p[1].x - p[0].x) * (p[0].y - p0.y),
			  b = (p[1].x - p0.x) * (p[2].y - p[1].y) -
				  (p[2].x - p[1].x) * (p[1].y - p0.y),
			  c = (p[2].x - p0.x) * (p[0].y - p[2].y) -
				  (p[0].x - p[2].x) * (p[2].y - p0.y);

		return ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0));
	}

	virtual void draw() override {
		auto range_x = std::minmax_element(p.begin(), p.end(),
			[](Point2D const &a, Point2D const &b) {
			return a.x < b.x;
		});
		auto range_y = std::minmax_element(p.begin(), p.end(),
			[](Point2D const &a, Point2D const &b) {
			return a.y < b.y;
		});

		for (short y{ range_y.first->y }; y < range_y.second->y; ++y) {
			for (short x{ range_x.first->x }; x < range_x.second->x; ++x) {
				if (!isBelong(Point2D(x, y))) continue;

				pos = { x, y };
				FillConsoleOutputCharacter(hConsole, '@', 1, pos, &cWritten);
			}
		}
	}
};

#endif TRIANGLE_H

