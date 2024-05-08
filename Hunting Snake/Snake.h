#ifndef _SNAKE_H_
#define _SNAKE_H_


#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
using namespace std;


#define WIDTHMAP 101
#define HEIGHTMAP 26
#define CornerX 6
#define CornerY 10

enum Direction { STOP, UP, DOWN, LEFT, RIGHT };
struct Point 
{
	int x, y;
	bool operator == (Point other) {
		return x == other.x && y == other.y;
	}
};
struct Snake
{
	Point pos;
	string cell;
	Direction dir;
	vector<Point> tail;
	bool dead;

	Snake() {
		pos = { 0, 0 };
		cell = "2312021523120204231202102312021223120226";
		dir = RIGHT;
		tail.push_back(pos);
		tail.push_back({ 0, 0 });
		dead = false;
	}
	void Move() {
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
	void Update() {
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

		if (pos.x < CornerX || pos.x >= CornerX + WIDTHMAP || pos.y < CornerY || pos.y >= CornerY + HEIGHTMAP)
			dead = true;
		for (int i = 1; i < tail.size() - 1; i++) {
			if (tail[i] == pos && dir != STOP)
				dead = true;
		}
	}
};
struct Fruit
{
	Point pos;
	Fruit() {
		pos = { 0, 0 };
	}
	void RandomFruit() {
		int x = rand() % WIDTHMAP + CornerX;
		int y = rand() % HEIGHTMAP + CornerY;
		pos = { x, y };
	}
};
bool CheckPoint(vector<Point> positionSnake, Point point);


#endif
