#ifndef POINT2D_H
#define POINT2D_H

#include <utility>

#include "Constants.h"

class Vector2D;
class Point2D
{
public:
	float x, y; // dangerous

	Point2D()
		: x(0.f), y(0.f)
    {
    }
	explicit Point2D(float& x_, float& y_)
		: x(std::move(x_) * cnst::aspect * cnst::pixelAspect),
		  y(std::move(y_))
    {
    }
	explicit Point2D(float&& x_, float&& y_)
		: x(x_ * cnst::aspect * cnst::pixelAspect),
		  y(y_)
    {
    }
	~Point2D()
	{
	}

	Point2D& moveByVector(const Vector2D &v);
};

#endif // !POINT2D_H