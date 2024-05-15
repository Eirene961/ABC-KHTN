#include "Snake.h"


bool CheckPoint(vector<Point> positionSnake, Point point, bool gate)
{
	if (gate == false) {
		for (int i = 0; i < positionSnake.size(); i++) {
			if (positionSnake[i] == point)
				return true;
		}
		return false;
	}
	else {
		for (int i = 0; i < positionSnake.size(); i++) {
			for (int j = -1; j <= 1; j++) {
				if (positionSnake[i] == Point(point.x, point.y + j))
					return true;
				if (positionSnake[i] == Point(point.x + 1, point.y + j))
					return true;
			}
		}
		return false;
	}
}