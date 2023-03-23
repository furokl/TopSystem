#include "Graphics.h"
#include "Controller.h"

int main()
{
	// Init Circle and Triangle
	Circle circle(5.f);
	circle.set_pos(Point2D(10, 0));
	Triangle tria(Point2D(0, 0), Point2D(10, 0), Point2D(5, 10));
	tria.set_pos(Point2D(30, 0));

	// Move controller from Triangle to Circle
	Controller playera(&tria);
	{
		Controller playerb(&circle);
		playera = std::move(playerb);
	}

	// Render
	while (GetAsyncKeyState(VK_ESCAPE) == 0) // exit on press key "ESC"
	{
		system("cls");
		circle.show();
		tria.show();
		Sleep(200);
	}
	return 0;
}