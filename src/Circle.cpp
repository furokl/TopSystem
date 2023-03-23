#include "Circle.h"

// ----------------------------------------------------------
// Display by formula
// (x-x0)^2 + (y-y0)^2 = r^2
// ----------------------------------------------------------
void Circle::show() {
	float x0 = m_center.x / cnst::pixelAspect / cnst::aspect + get_pos().x;
	const float &y0 = m_center.y + get_pos().y;
	const float &r = m_radius;

	for (float y{y0 - r}; y < y0 + r; ++y) {
		float temp = sqrt((r + y - y0) * (r - y + y0));
		std::pair x = std::make_pair(-temp + x0, temp + x0);
		x.first *= cnst::aspect * cnst::pixelAspect;
		x.second *= cnst::aspect * cnst::pixelAspect;
		COORD pos = { SHORT(x.first), SHORT(y)};

		(x.second - x.first == 0.f)
			? FillConsoleOutputCharacter(hConsole, '@', 1, pos, &cWritten)
			: FillConsoleOutputCharacter(hConsole, '@', (x.second - x.first), pos, &cWritten);
	}
}