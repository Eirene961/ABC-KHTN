#ifndef _SNAKE_H_
#define _SNAKE_H_


#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
using namespace std;


#define WIDTHMAP 86
#define HEIGHTMAP 26
#define CornerX 6
#define CornerY 10

enum Direction { STOP, UP, DOWN, LEFT, RIGHT };
enum Type { WALL, SPIDER };
struct Point 
{
	int x, y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
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
	void Update() {
		Point prev = tail[0];
		tail[0] = pos;
		for (int i = 1; i < tail.size(); i++) {
			Point temp = tail[i];
			tail[i] = prev;
			prev = temp;
		}

		if (pos.x < 0 || pos.x >= WIDTHMAP || pos.y < 0 || pos.y >= HEIGHTMAP)
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
		int x = rand() % WIDTHMAP;
		int y = rand() % HEIGHTMAP;
		pos = { x, y };
	}
};
struct Monster {
	Type type;
	vector<Point> pos;
	Direction dir;
	pair<Point, Point> bound;
	vector<Point> erase;
	
	void Clear() {
		pos.clear();
		erase.clear();
	}
	void Move() {
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

		switch (dir) {
		case UP:
			if (type == WALL)
				erase[0] = pos.back();
			for (Point& point : pos) {
				point.y--;
			}
			break;
		case DOWN:
			if (type == WALL)
				erase[0] = pos[0];
			for (Point& point : pos) {
				point.y++;
			}
			break;
		case LEFT:
			if (type == WALL)
				erase[0] = pos.back();
			for (Point& point : pos) {
				point.x--;
			}
			break;
		case RIGHT:
			if (type == WALL)
				erase[0] = pos[0];
			for (Point& point : pos) {
				point.x++;
			}
			break;
		}
	}
};
bool CheckPoint(vector<Point> positionSnake, Point point, bool gate = false);


#endif
