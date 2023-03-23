#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape
{
private:
	float m_radius;
	Point2D m_center;

public:
    Circle(float radius)
		: m_radius(radius),
		  m_center(Point2D(m_radius + get_pos().x, m_radius + get_pos().y))
	{
	}
	~Circle()
	{
	}

	virtual void show() override;
};

#endif // !CIRCLE_H

