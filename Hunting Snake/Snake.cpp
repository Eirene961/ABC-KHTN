#include "Snake.h"


// Snake
void Snake::Move()
{
	if (_kbhit()) {
		char current = tolower(_getch());
		switch (current) {
		case 'a':
			if (dir != RIGHT)
				dir = LEFT;
			break;
		case 'd':
			if (dir != LEFT)
				dir = RIGHT;
			break;
		case 'w':
			if (dir != DOWN)
				dir = UP;
			break;
		case 's':
			if (dir != UP)
				dir = DOWN;
			break;
		}
	}
}

void Snake::Update()
{
	if (pos.x < CornerX || pos.x >= CornerX + WIDTHMAP || pos.y < CornerY || pos.y >= CornerY + HEIGHTMAP)
		dead = true;
	for (int i = 1; i < tail.size() - 1; i++) {
		if (pos.x == tail[i].x && pos.y == tail[i].y && dir != STOP)
			dead = true;
	}

	switch (dir) {
	case LEFT:
		pos.x--;
		break;
	case RIGHT:
		pos.x++;
		break;
	case UP:
		pos.y--;
		break;
	case DOWN:
		pos.y++;
		break;
	}

	Point prev = tail[0];
	tail[0] = pos;
	for (int i = 1; i < tail.size(); i++) {
		Point temp = tail[i];
		tail[i] = prev;
		prev = temp;
	}
}
//

// Fruit
void Fruit::RandomFruit()
{
	int x = rand() % WIDTHMAP + CornerX;
	int y = rand() % HEIGHTMAP + CornerY;
	pos = { x, y };
}
//

bool CheckPoint(vector<Point> positionSnake, Point point)
{
	for (int i = 0; i < positionSnake.size(); i++) {
		if (positionSnake[i].x == point.x && positionSnake[i].y == point.y)
			return true;
	}
	return false;
}