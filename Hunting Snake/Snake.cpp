#include "Snake.h"



// -------------- SNAKE --------------

void Snake::Move()
{
	if (_kbhit()) {
		if (stunned == false) {
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
		else {
			char current = tolower(_getch());
			switch (current) {
			case 'd':
				if (dir != RIGHT)
					dir = LEFT;
				break;
			case 'a':
				if (dir != LEFT)
					dir = RIGHT;
				break;
			case 's':
				if (dir != DOWN)
					dir = UP;
				break;
			case 'w':
				if (dir != UP)
					dir = DOWN;
				break;
			}
		}
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
}


void Snake::Update()
{
	Point prev = tail[0];
	tail[0] = pos;
	for (int i = 1; i < tail.size(); i++) {
		Point temp = tail[i];
		tail[i] = prev;
		prev = temp;
	}


	if (pos.x < 0 || pos.x >= WIDTHMAP || pos.y < 0 || pos.y >= HEIGHTMAP) {
		dead = true;
	}
	for (int i = 1; i < tail.size() - 1; i++) {
		if (tail[i] == pos && dir != STOP) {
			dead = true;
		}
	}
}


// -------------- FRUIT --------------

void Fruit::RandomFruit()
{
	int x = rand() % WIDTHMAP;
	int y = rand() % HEIGHTMAP;
	pos = { x, y };
}


// ------------- MONSTER -------------

void Monster::Clear()
{
	randomDirection = 0;
	pos.clear();
	trigger.clear();
	boundList.clear();
	erase.clear();
}


void Monster::Input(Point point)
{
	if (type == WALL) {
		// APPEARANCE
		for (int i = 0; i < 4; i++) {
			pos.push_back({ point.x, point.y + i });
		}

		// ERASE
		if (dir == UP)
			erase.push_back(pos.back());
		else if (dir == DOWN)
			erase.push_back(pos[0]);
	}
	else if (type == CRAB) {
		// APPEARANCE
		pos.push_back(point);
		pos.push_back(Point(point.x + 1, point.y));
		pos.push_back(Point(point.x + 4, point.y));
		for (int i = 2; i <= 3; i++)
			pos.push_back(Point(point.x + i, point.y + 1));
		for (int i = 1; i <= 4; i++)
			pos.push_back(Point(point.x + i, point.y + 2));
		for (int i = 1; i <= 4; i++)
			pos.push_back(Point(point.x + i, point.y + 3));
		for (int i = 2; i <= 3; i++)
			pos.push_back(Point(point.x + i, point.y + 4));
		pos.push_back(Point(point.x, point.y + 5));
		pos.push_back(Point(point.x + 1, point.y + 5));
		pos.push_back(Point(point.x + 4, point.y + 5));

		// ERASE
		if (dir == UP) {
			for (int i = 0; i <= 2; i++)
				erase.push_back(pos[i]);
			erase.push_back(pos[9]);
			erase.push_back(pos[12]);
			for (int i = 13; i <= 17; i++)
				erase.push_back(pos[i]);
		}
		else if (dir == DOWN) {
			for (int i = 15; i <= 17; i++)
				erase.push_back(pos[i]);
			erase.push_back(pos[5]);
			erase.push_back(pos[8]);
			for (int i = 0; i <= 4; i++)
				erase.push_back(pos[i]);
		}
		else if (dir == LEFT) {
			erase.push_back(pos[1]);
			erase.push_back(pos[2]);
			erase.push_back(pos[2]);
			erase.push_back(pos[4]);
			erase.push_back(pos[8]);
			erase.push_back(pos[12]);
			erase.push_back(pos[14]);
			erase.push_back(pos[17]);
			erase.push_back(pos[17]);
			erase.push_back(pos[16]);
		}
		else if (dir == RIGHT) {
			erase.push_back(pos[2]);
			erase.push_back(pos[2]);
			erase.push_back(pos[0]);
			erase.push_back(pos[3]);
			erase.push_back(pos[5]);
			erase.push_back(pos[9]);
			erase.push_back(pos[13]);
			erase.push_back(pos[15]);
			erase.push_back(pos[17]);
			erase.push_back(pos[17]);
		}
	}
}


void Monster::Erase()
{
	if (type == WALL) {
		switch (dir) {
		case UP:
			erase[0] = pos.back();
			break;
		case DOWN:
			erase[0] = pos[0];
			break;
		case LEFT:
			erase[0] = pos.back();
			break;
		case RIGHT:
			erase[0] = pos[0];
			break;
		}
	}
	else if (type == CRAB) {
		switch (dir) {
		case UP:
			for (int i = 0; i <= 2; i++)
				erase[i] = pos[i];
			erase[3] = pos[9];
			erase[4] = pos[12];
			for (int i = 13; i <= 17; i++)
				erase[i - 8] = pos[i];
			break;
		case DOWN:
			for (int i = 15; i <= 17; i++)
				erase[i - 15] = pos[i];
			erase[3] = pos[5];
			erase[4] = pos[8];
			for (int i = 0; i <= 4; i++)
				erase[i + 5] = pos[i];
			break;
		case LEFT:
			erase[0] = pos[1];
			erase[1] = erase[2] = pos[2];
			erase[3] = pos[4];
			erase[4] = pos[8];
			erase[5] = pos[12];
			erase[6] = pos[14];
			erase[7] = erase[8] = pos[17];
			erase[9] = pos[16];
			break;
		case RIGHT:
			erase[0] = erase[1] = pos[2];
			erase[2] = pos[0];
			erase[3] = pos[3];
			erase[4] = pos[5];
			erase[5] = pos[9];
			erase[6] = pos[13];
			erase[7] = pos[15];
			erase[8] = erase[9] = pos[17];
			break;
		}
	}
}


void Monster::RandomDirection()
{
	for (Point point : trigger) {
		if (pos[0] == point) {
			if (randomDirection == 0) {
				Direction direction;
				do {
					direction = (Direction)(rand() % 4 + 1);
				} while (dir + direction == 3 || dir + direction == 7);
				dir = direction;
				break;
			}
			else if (randomDirection == 1) {
				if (dir == UP)
					dir = RIGHT;
				else if (dir == DOWN)
					dir = LEFT;
				else if (dir == LEFT)
					dir = DOWN;
				else if (dir == RIGHT)
					dir = UP;
			}
		}
	}
}


void Monster::Move()
{
	for (pair<Point, Point>& bound : boundList) {
		if (pos[0] == bound.first) {
			if (dir == UP)
				dir = DOWN;
			else if (dir == LEFT)
				dir = RIGHT;
		}
		else if (pos.back() == bound.second) {
			if (dir == DOWN)
				dir = UP;
			else if (dir == RIGHT)
				dir = LEFT;
		}
	}

	RandomDirection();
	Erase();

	switch (dir) {
	case UP:
		for (Point& point : pos) {
			point.y--;
		}
		break;
	case DOWN:
		for (Point& point : pos) {
			point.y++;
		}
		break;
	case LEFT:
		for (Point& point : pos) {
			point.x--;
		}
		break;
	case RIGHT:
		for (Point& point : pos) {
			point.x++;
		}
		break;
	}
}


// -----------------------------------




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
				if (positionSnake[i] == Point(point.x - 1, point.y + j))
					return true;
				if (positionSnake[i] == Point(point.x, point.y + j))
					return true;
				if (positionSnake[i] == Point(point.x + 1, point.y + j))
					return true;
			}
		}
		return false;
	}
}