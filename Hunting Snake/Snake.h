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
struct Point { int x, y; };
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
		dir = STOP;
		tail.push_back(pos);
		tail.push_back({ 0, 0 });
		dead = false;
	}
	void Move();
	void Update();
};
struct Fruit
{
	Point pos;
	Fruit() {
		pos = { 0, 0 };
	}
	void RandomFruit();
};
bool CheckPoint(vector<Point> positionSnake, Point point);


#endif
