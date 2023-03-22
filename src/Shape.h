#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include <algorithm>

#include "Console.h"
#include "Point2D.h"

class Shape
{
	Point2D m_position;

public:
	Shape()
		: m_position(Point2D())
	{
	}

	Shape(Point2D &position)
		: m_position(position)
	{
	}

	Point2D get_pos() const { return m_position; };
	void set_pos(Point2D &position) { m_position = position; };
	void set_pos(Point2D &&position) { set_pos(position); };

	virtual void show() = 0;
	virtual ~Shape() {}

	/*Shape(Point2D p)
		: m_center(p)
	{
	}*/
};

#endif

