#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include <algorithm>
#include <Windows.h>

#include "Point2D.h"

extern DWORD cWritten;
extern HANDLE hConsole;
extern CONSOLE_SCREEN_BUFFER_INFO screenInfo;

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
	void set_pos(Point2D position) { m_position = position; };

	virtual void show() = 0;
	//virtual void rotate() = 0;
	virtual ~Shape() {}
};

#endif // !SHAPE_H

