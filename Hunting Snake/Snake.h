#ifndef _SNAKE_H_
#define _SNAKE_H_


#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <vector>
using namespace std;


#define WIDTHMAP 86
#define HEIGHTMAP 26
#define CornerX 6
#define CornerY 10

enum Direction { STOP, UP, DOWN, LEFT, RIGHT };
enum Type { WALL, CRAB };
struct Point 
{
	int x, y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}

	bool operator == (Point other) {
		return x == other.x && y == other.y;
	}

	friend ifstream& operator >> (ifstream& file, Point& point) {
		file >> point.x;
		file >> point.y;
		return file;
	}

	friend ofstream& operator << (ofstream& file, Point& point) {
		file << point.x << ' ' << point.y << endl;
		return file;
	}
};
struct Snake
{
	Point pos;
	string cell;
	Direction dir;
	vector<Point> tail;
	bool dead;
	bool stunned;
	bool eatingSound;

	void Move();
	void Update();

	Snake() {
		pos = { 0, 0 };
		cell = "2312021523120204231202102312021223120226";
		dir = RIGHT;
		tail.push_back(pos);
		tail.push_back({ 0, 0 });
		dead = false;
		stunned = false;
		eatingSound = false;
	}

	friend ifstream& operator >> (ifstream& file, Snake& snake) {
		int n;
		file >> n;
		for (int i = 0; i < n; i++) {
			Point point;
			file >> point;
			snake.tail.push_back(point);
		}
		snake.pos = snake.tail[0];
		int dir;
		file >> dir;
		snake.dir = (Direction)dir;
		file >> snake.stunned;
		return file;
	}

	friend ofstream& operator << (ofstream& file, Snake& snake) {
		int n = snake.tail.size();
		file << n << endl;
		for (int i = 0; i < n; i++) {
			file << snake.tail[i];
		}
		file << snake.dir << endl;
		file << snake.stunned << endl;
		return file;
	}
};
struct Fruit
{
	Point pos;

	Fruit() {
		pos = { 0, 0 };
	}

	friend ifstream& operator >> (ifstream& file, Fruit& fruit) {
		file >> fruit.pos;
		return file;
	}

	friend ofstream& operator << (ofstream& file, Fruit& fruit) {
		file << fruit.pos;
		return file;
	}

	void RandomFruit();
};
struct Monster {
	Type type;
	vector<Point> pos;
	int randomDirection;
	Direction dir;
	vector<Point> trigger;
	vector<pair<Point, Point>> boundList;
	vector<Point> erase;

	Monster() {
		type = WALL;
		dir = STOP;
		randomDirection = 0;
	}

	friend ifstream& operator >> (ifstream& file, Monster& monster) {
		int type;
		file >> type;
		monster.type = (Type)type;
		int sizePos;
		file >> sizePos;
		for (int i = 0; i < sizePos; i++) {
			Point point;
			file >> point;
			monster.pos.push_back(point);
		}
		file >> monster.randomDirection;
		int dir;
		file >> dir;
		monster.dir = (Direction)dir;
		int sizeTrigger;
		file >> sizeTrigger;
		for (int i = 0; i < sizeTrigger; i++) {
			Point point;
			file >> point;
			monster.trigger.push_back(point);
		}
		int sizeBound;
		file >> sizeBound;
		for (int i = 0; i < sizeBound; i++) {
			pair<Point, Point> bound;
			file >> bound.first;
			file >> bound.second;
			monster.boundList.push_back(bound);
		}
		int sizeErase;
		file >> sizeErase;
		for (int i = 0; i < sizeErase; i++) {
			Point point;
			file >> point;
			monster.erase.push_back(point);
		}

		return file;
	}

	friend ofstream& operator << (ofstream& file, Monster& monster) {
		file << monster.type << endl;
		int sizePos = monster.pos.size();
		file << sizePos << endl;
		for (int i = 0; i < sizePos; i++) {
			file << monster.pos[i];
		}
		file << monster.randomDirection << endl;
		file << monster.dir << endl;
		int sizeTrigger = monster.trigger.size();
		file << sizeTrigger << endl;
		for (int i = 0; i < sizeTrigger; i++) {
			file << monster.trigger[i];
		}
		int sizeBound = monster.boundList.size();
		file << sizeBound << endl;
		for (int i = 0; i < sizeBound; i++) {
			file << monster.boundList[i].first;
			file << monster.boundList[i].second;
		}
		int sizeErase = monster.erase.size();
		file << sizeErase << endl;
		for (int i = 0; i < sizeErase; i++) {
			file << monster.erase[i];
		}

		return file;
	}

	void Clear();
	void Input(Point point);
	void Erase();
	void RandomDirection();
	void Move();
};
bool CheckPoint(vector<Point> positionSnake, Point point, bool gate = false);


#endif
