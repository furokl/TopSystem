#include "Constants.h"
#include "Graphics.h"

int main()
{
	Graphics eng;

	Point2D a (0, 0);
	Point2D b (0, 30);
	Point2D c (120, 30);
	Point2D x0(5, 3);
	Triangle tria (a, b, c);
	tria.draw();


	getchar();
	system("pause");
	return 0;
}