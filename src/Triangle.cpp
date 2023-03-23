#include "Triangle.h"


// ----------------------------------------------------------
// Check point belongs to Triangle
// ----------------------------------------------------------
bool Triangle::isBelong(Point2D p0) {
	float	a = (p[0].x - p0.x)	* (p[1].y - p[0].y) -
				(p[1].x - p[0].x) * (p[0].y - p0.y),
			b = (p[1].x - p0.x)	* (p[2].y - p[1].y) -
				(p[2].x - p[1].x) * (p[1].y - p0.y),
			c = (p[2].x - p0.x)	* (p[0].y - p[2].y) -
				(p[0].x - p[2].x) * (p[2].y - p0.y);

	return ((a >= 0.f && b >= 0.f && c >= 0.f) || (a <= 0.f && b <= 0.f && c <= 0.f));
}

// ----------------------------------------------------------
// Display by formula (result must be one sign)
// (x1-x0) * (y2-y1) - (x2-x1) * (y1-y0) 
// (x2-x0) * (y3-y2) - (x3-x2) * (y2-y0) 
// (x3-x0) * (y1-y3) - (x1-x3) * (y3-y0) 
// ----------------------------------------------------------
void Triangle::show() {
	auto range_x = std::minmax_element(p.begin(), p.end(),
		[](Point2D const &a, Point2D const &b) {
		return a.x < b.x;
	});
	auto range_y = std::minmax_element(p.begin(), p.end(),
		[](Point2D const &a, Point2D const &b) {
		return a.y < b.y;
	});

	for (float y{ range_y.first->y - 0.5f }; y < range_y.second->y + 0.5f; ++y) {
		for (float x{ range_x.first->x - 0.5f }; x < range_x.second->x + 0.5f; ++x) {
			if (!isBelong(Point2D(x, y))) continue;

			COORD pos = { (SHORT)x + get_pos().x, (SHORT)y + get_pos().y};
			FillConsoleOutputCharacter(hConsole, '@', 1, pos, &cWritten);
		}
	}
}