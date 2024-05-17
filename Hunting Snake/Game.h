#ifndef _GAME_H_
#define _GAME_H_


#include <time.h>
#include "Console.h"
#include "Menu.h"
#include "Snake.h"


#define WIDTHCONSOLE 1100
#define HEIGHTCONSOLE 700
#define Target_lv1 10
#define Target_lv2 10
#define Target_lv3 70
void GameOver();
int Level_01(Snake*& snake);
int Level_02(Snake*& snake);
int Level_03(Snake*& snake);
bool DrawLevel_01();
bool DrawLevel_02();
bool DrawLevel_03();
struct Game
{
	Snake* snake;
	Fruit* fruit;
	int score;
	int target;
	bool gate;
	Point posGate;
	vector<Point> wall;

	Game() {
		snake = new Snake;
		fruit = new Fruit;
		score = 0;
		target = 0;
		gate = false;
		posGate = { 0, 0 };
	}
	~Game() {
		delete snake;
		delete fruit;
	}
	void Reset() {
		score = 0;
		gate = false;
		snake->dir = RIGHT;
		snake->dead = false;
		do {
			fruit->RandomFruit();
		} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos));
	}
	void InputLevel(int(*Level)(Snake*&)) {
		Reset();
		wall.clear();
		target = Level(snake);
	}
	bool CheckWall(Point position) {
		for (Point point : wall) {
			if (position == point)
				return true;
		}
		return false;
	}
	void RandomGate() {
		do {
			int x = rand() % WIDTHMAP + CornerX;
			int y = rand() % HEIGHTMAP + CornerY;
			posGate = { x, y };
		} while (CheckPoint(snake->tail, posGate) || CheckWall(posGate));
	}
	void Logic() {
		if (snake->pos == fruit->pos && gate == false) {
			score += 10;
			snake->tail.push_back(snake->pos);
			do {
				fruit->RandomFruit();
			} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos));
			if (score != target) {
				GotoXY(fruit->pos.x, fruit->pos.y);
				TextColor(Red);
				cout << char(1);
			}
			else {
				gate = true;
				RandomGate();
				GotoXY(posGate.x, posGate.y);
				cout << char(219);
			}
		}
		if (gate == true && snake->pos == posGate) {
			snake->dir = STOP;
			GotoXY(posGate.x, posGate.y);
			cout << char(219);
		}
		for (Point point : wall) {
			if (snake->pos == point)
				snake->dead = true;
		}
	}
	void DrawMap() {
		TextColor(MainColor);
		system("cls");
		HideCursor();

		GotoXY(CornerX - 1, CornerY - 1);
		for (int i = 0; i < WIDTHMAP + 35; i++)
			cout << char(220);
		for (int i = 0; i < HEIGHTMAP; i++) {
			GotoXY(CornerX - 1, CornerY + i);
			cout << char(219);
			GotoXY(CornerX + WIDTHMAP, CornerY + i);
			cout << char(219);
			GotoXY(CornerX + WIDTHMAP+33, CornerY + i);
			cout << char(219);
		}
		GotoXY(CornerX - 1, CornerY + HEIGHTMAP);
		for (int i = 0; i < WIDTHMAP + 35; i++)
			cout << char(223);
		GotoXY(fruit->pos.x, fruit->pos.y);
		TextColor(Red);
		cout << char(1);

		TextColor(MainColor);
		for (Point point : wall) {
			GotoXY(point.x, point.y);
			cout << char(178);
		}
	}
	void DrawSnake() {
		TextColor(MainColor);
		//------------------------------
		GotoXY(100, 14);
		cout << "----LEVER: ???"<<"----";
		GotoXY(104, 16);
		cout << "SCORE: " << score;
		GotoXY(104, 17);
		cout << "TARGET: " << target;
		GotoXY(104, 18);
		cout << "Speed: ";

		GotoXY(104, 22);
		cout << "W: Move Up";
		GotoXY(104, 23);
		cout << "S: Move Down";
		GotoXY(104, 24);
		cout << "A: Move Left";
		GotoXY(104, 25);
		cout << "D: Move Right";
		GotoXY(104, 26);
		cout << "P: Pause Game";
		GotoXY(104, 27);
		cout << " : Save Game";
		GotoXY(104, 28);
		cout << " : Load Right";
		//-------------------------------
		BackgroundColor(DarkWhite);
		for (int i = 0; i < snake->tail.size() - 1; i++) {
			int num = i % snake->cell.size();
			if (num < 8)
				TextColor(Red);
			else if (num < 16)
				TextColor(DarkCyan);
			else if (num < 24)
				TextColor(Green);
			else if (num < 32)
				TextColor(DarkYellow);
			else
				TextColor(Black);
			GotoXY(snake->tail[i].x, snake->tail[i].y);
			cout << snake->cell[num] - '0';
		}
		GotoXY(snake->tail.back().x, snake->tail.back().y);
		BackgroundColor(White);
		cout << " ";
	}
};
void StartGame();


#endif