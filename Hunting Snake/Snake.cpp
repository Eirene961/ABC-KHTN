#include "Snake.h"


bool CheckFruit(vector<Point> positionSnake, Point fruit)
{
	for (int i = 0; i < positionSnake.size(); i++) {
		if (positionSnake[i].x == fruit.x && positionSnake[i].y == fruit.y)
			return true;
	}
	return false;
}