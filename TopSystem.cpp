#include "Constants.h"
#include "Graphics.h"
#include "Controller.h"

int main()
{
	//Graphics eng;

	/*Point2D a (0, 0);
	Point2D b (0, 30);
	Point2D c (120, 30);
	Point2D x0(5, 3);
	Triangle tria (a, b, c);
	tria.draw();*/
	Circle circle(5.f);
	circle.set_pos(Point2D(10, 0));
	circle.show();
	Triangle tria(Point2D(0, 0), Point2D(30, 0), Point2D(30, 15));
	tria.set_pos(Point2D(30, 0));

	Controller player (&circle);
	while (true)
	{
		circle.show();
		tria.show();
	}
	getchar();
	system("pause");
	return 0;
}