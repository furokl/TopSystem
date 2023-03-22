#include "Triangle.h"

// (x1-x0) * (y2-y1) - (x2-x1) * (y1-y0) > 0 &&
// (x2-x0) * (y3-y2) - (x3-x2) * (y2-y0) > 0 &&
// (x3-x0) * (y1-y3) - (x1-x3) * (y3-y0) > 0
bool Triangle::isBelong(Point2D p0) {
	float	a = (p[0].x - p0.x)	* (p[1].y - p[0].y) -
				(p[1].x - p[0].x) * (p[0].y - p0.y),
			b = (p[1].x - p0.x)	* (p[2].y - p[1].y) -
				(p[2].x - p[1].x) * (p[1].y - p0.y),
			c = (p[2].x - p0.x)	* (p[0].y - p[2].y) -
				(p[0].x - p[2].x) * (p[2].y - p0.y);

	return ((a >= 0.f && b >= 0.f && c >= 0.f) || (a <= 0.f && b <= 0.f && c <= 0.f));
}

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

			COORD pos = { x + get_pos().x, y};
			FillConsoleOutputCharacter(hConsole, '@', 1, pos, &cWritten);
		}
	}
}