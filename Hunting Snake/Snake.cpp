#include "Snake.h"


bool CheckPoint(vector<Point> positionSnake, Point point)
{
	for (int i = 0; i < positionSnake.size(); i++) {
		if (positionSnake[i] == point)
			return true;
	}
	return false;
}