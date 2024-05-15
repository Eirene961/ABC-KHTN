#ifndef _GAME_H_
#define _GAME_H_


#include <time.h>
#include "Console.h"
#include "Menu.h"
#include "Snake.h"


#define WIDTHCONSOLE 1100
#define HEIGHTCONSOLE 700
#define Target_lv1 70
#define Target_lv2 80
#define Target_lv3 80
#define Target_lv4 80
#define Target_lv5 80
bool BinarySearch(vector<int> v, int l, int r, int x);
void Insert(vector<int>& v, int x);
void GameOver();
int Level_01(Snake*& snake);
int Level_02(Snake*& snake);
int Level_03(Snake*& snake);
int Level_04(Snake*& snake);
int Level_05(Snake*& snake);
bool DrawLevel_01();
bool DrawLevel_02();
bool DrawLevel_03();
bool DrawLevel_04();
bool DrawLevel_05();
struct Game
{
	Snake* snake;
	Fruit* fruit;
	int score;
	int target;
	bool gate;
	vector<Point> posGate;
	vector<int> wall[WIDTHMAP];
	int time;
	vector<Monster> monsterList;
	int color;
	vector<pair<Point,Point>> teleport;
	vector<Point> poison;

	Game() {
		snake = new Snake;
		fruit = new Fruit;
		score = 0;
		target = 0;
		gate = false;
		time = 0;
		color = 0;
	}
	~Game() {
		delete snake;
		delete fruit;
	}
	void Reset() {
		score = 0;
		gate = false;
		time = 0;
		color = 0;
		snake->dir = RIGHT;
		snake->dead = false;
		snake->stunned = false;
		do {
			fruit->RandomFruit();
		} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos));
		posGate.clear();
		for (int i = 0; i < WIDTHMAP; i++) {
			if (wall[i].empty() == false)
				wall[i].clear();
		}
		monsterList.clear();
		teleport.clear();
		poison.clear();
	}
	void InputLevel(int(*Level)(Snake*&)) {
		Reset();
		target = Level(snake);
	}
	bool CheckWall(Point position, bool gate = false, bool tele = false) {
		int x = position.x;
		int y = position.y;
		if (tele == true) {
			for (pair<Point, Point> point : teleport) {
				if (position == point.first || position == point.second)
					return true;
			}
		}
		if (gate == false) {
			if (BinarySearch(wall[x], 0, wall[x].size() - 1, y))
				return true;
			return false;
		}
		else {
			for (int i = 0; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (BinarySearch(wall[x + i], 0, wall[x + i].size() - 1, y + j))
						return true;
				}
			}
			return false;
		}
	}
	void RandomGate() {
		int x, y;
		do {
			x = rand() % (WIDTHMAP - 2) + 1;
			y = rand() % (HEIGHTMAP - 2) + 1;
		} while (CheckPoint(snake->tail, Point(x, y), true) || CheckWall(Point(x, y), true));
		posGate.push_back({ x, y });
		posGate.push_back({ x + 1, y });
		for (int i = 0; i <= 1; i++) {
			posGate.push_back({ x + i, y - 1 });
			posGate.push_back({ x + i, y + 1 });
		}
	}
	void Teleport() {
		int y = snake->pos.y;
		for (pair<Point, Point> point : teleport) {
			if (snake->pos == point.first)
				snake->pos = point.second;
			else if (snake->pos == point.second)
				snake->pos = point.first;
		}
	}
	bool SnakeMeetMonster() {
		bool check = false;
		for (Monster& monster : monsterList) {
			for (Point point : monster.pos) {
				for (int i = 0; i < snake->tail.size() - 1; i++) {
					if (point == snake->tail[i]) {
						if (i != 0)
							snake->tail.erase(snake->tail.begin() + i);
						check = true;
					}
				}
			}
		}
		return check;
	}
	bool FruitMeetMonster() {
		for (Monster& monster : monsterList) {
			for (Point point : monster.pos) {
				if (point == fruit->pos) {
					if (monster.type != WALL) {
						score -= 30;
						snake->stunned = true;
						if (snake->tail.size() <= 3)
							snake->dead = true;
						else {
							poison.push_back(snake->tail.back());
							snake->tail.pop_back();
							poison.push_back(snake->tail.back());
							snake->tail.pop_back();
							poison.push_back(snake->tail.back());
							snake->tail.pop_back();
						}
					}
					return true;
				}
			}
		}
		return false;
	}
	void Logic() {
		if (snake->pos == fruit->pos && gate == false) {
			score += 10;
			snake->tail.push_back(snake->pos);
			snake->stunned = false;
			do {
				fruit->RandomFruit();
			} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos, false, true));
			if (score != target) {
				GotoXY(fruit->pos.x + CornerX, fruit->pos.y + CornerY);
				TextColor(Red);
				cout << char(1);
			}
			else {
				gate = true;
				RandomGate();
				GotoXY(posGate[1].x + CornerX, posGate[1].y + CornerY);
				cout << char(179);
				GotoXY(posGate[2].x + CornerX, posGate[2].y + CornerY);
				cout << char(196) << char(191);
				GotoXY(posGate[3].x + CornerX, posGate[3].y + CornerY);
				cout << char(196) << char(217);
			}
		}
		if (gate == true) {
			if (snake->pos == posGate[0]) {
				snake->dir = STOP;
				GotoXY(posGate[0].x + CornerX, posGate[0].y + CornerY);
				cout << ' ';
			}
			for (int i = 1; i < posGate.size(); i++) {
				if (snake->pos == posGate[i])
					snake->dead = true;
			}
		}
		if (FruitMeetMonster()) {
			do {
				fruit->RandomFruit();
			} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos));
			GotoXY(fruit->pos.x + CornerX, fruit->pos.y + CornerY);
			TextColor(Red);
			cout << char(1);
		}
		if (CheckWall(snake->pos) || SnakeMeetMonster())
			snake->dead = true;
		for (Point point : poison) {
			if (snake->pos == point)
				snake->stunned = true;
		}
		Teleport();
	}
	void DrawMap() {
		TextColor(MainColor);
		system("cls");
		HideCursor();

		// MAP
		GotoXY(CornerX - 1, CornerY - 1);
		for (int i = 0; i < WIDTHMAP + 2; i++)
			cout << char(220);
		for (int i = 0; i < HEIGHTMAP; i++) {
			GotoXY(CornerX - 1, CornerY + i);
			cout << char(219);
			GotoXY(CornerX + WIDTHMAP, CornerY + i);
			cout << char(219);
		}
		GotoXY(CornerX - 1, CornerY + HEIGHTMAP);
		for (int i = 0; i < WIDTHMAP + 2; i++)
			cout << char(223);

		// Fruit
		GotoXY(fruit->pos.x + CornerX, fruit->pos.y + CornerY);
		TextColor(Red);
		cout << char(1);

		// WALL
		TextColor(MainColor);
		for (int i = 0; i < WIDTHMAP; i++) {
			for (int y : wall[i]) {
				GotoXY(i + CornerX, y + CornerY);
				cout << char(178);
			}
		}
		
		// TELEPORT
		DrawTeleport();


	}
	void DrawTeleport() {
		color %= 3;
		if (color == 0)
			TextColor(Red);
		else if (color == 1)
			TextColor(DarkGreen);
		else
			TextColor(DarkYellow);
		color++;
		for (pair<Point, Point>& point : teleport) {
			GotoXY(CornerX + point.first.x, CornerY + point.first.y);
			cout << char(179);
			GotoXY(CornerX + point.second.x, CornerY + point.second.y);
			cout << char(179);
		}
	}
	void DrawSnake() {
		TextColor(MainColor);
		GotoXY(0, 0);
		cout << "Score: " << score;
		BackgroundColor(DarkWhite);
		for (int i = 0; i < snake->tail.size() - 1; i++) {
			int num = i % snake->cell.size();
			if (num < 8)
				TextColor(Red);
			else if (num < 16)
				TextColor(DarkCyan);
			else if (num < 24)
				TextColor(DarkGreen);
			else if (num < 32)
				TextColor(DarkYellow);
			else
				TextColor(Pink);
			GotoXY(snake->tail[i].x + CornerX, snake->tail[i].y + CornerY);
			cout << snake->cell[num] - '0';
		}
		GotoXY(snake->tail.back().x + CornerX, snake->tail.back().y + CornerY);
		BackgroundColor(White);
		cout << " ";
	}
	void DrawMonster() {
		TextColor(MainColor);
		for (Monster& monster : monsterList) {
			monster.Move();
			if (monster.type == WALL) {
				for (int i = 0; i < monster.pos.size(); i++) {
					GotoXY(monster.pos[i].x + CornerX, monster.pos[i].y + CornerY);
					cout << char(178);
				}
				GotoXY(monster.erase[0].x + CornerX, monster.erase[0].y + CornerY);
				cout << ' ';
			}
			else if (monster.type == CRAB) {
				for (int i = 0; i <= 17; i++) {
					GotoXY(monster.pos[i].x + CornerX, monster.pos[i].y + CornerY);
					if (i == 0 || i == 5 || i == 9 || i == 15)
						cout << 'o';
					else if (i == 1 || i == 2 || i == 16 || i == 17)
						cout << 'O';
					else
						cout << char(219);
				}
				for (Point point : monster.erase) {
					GotoXY(point.x + CornerX, point.y + CornerY);
					cout << ' ';
				}
			}
		}
	}
};
void StartGame();


#endif