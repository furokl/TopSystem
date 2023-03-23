#include "Point2D.h"
#include "Vector2D.h"

Point2D& Point2D::moveByVector(const Vector2D &v) {
	x += v.m_x;
	y += v.m_y;
	return *this;
}
