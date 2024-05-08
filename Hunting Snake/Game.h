#ifndef _GAME_H_
#define _GAME_H_


#include <time.h>
#include "Console.h"
#include "Menu.h"
#include "Snake.h"


#define WIDTHCONSOLE 1280
#define HEIGHTCONSOLE 704
#define Target_lv1 70
#define Target_lv2 100
void GameOver();
int Level_01(Snake*& snake);
int Level_02(Snake*& snake);
bool DrawLevel_01();
bool DrawLevel_02();
struct Game
{
	Snake* snake;
	Fruit* fruit;
	int score;
	int target;
	bool gate;
	Point posGate;

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
	void InputLevel(int(*Level)(Snake*&)) {
		target = Level(snake);
		score = 0;
		gate = false;
		snake->dir = RIGHT;
		do {
			fruit->RandomFruit();
		} while (CheckPoint(snake->tail, fruit->pos));
	}
	void RandomGate() {
		do {
			int x = rand() % WIDTHMAP + CornerX;
			int y = rand() % HEIGHTMAP + CornerY;
			posGate = { x, y };
		} while (CheckPoint(snake->tail, posGate));
	}
	void Logic() {
		if (snake->pos == fruit->pos && gate == false) {
			score += 10;
			snake->tail.push_back(snake->pos);
			do {
				fruit->RandomFruit();
			} while (CheckPoint(snake->tail, fruit->pos));
			if (score != target) {
				GotoXY(fruit->pos.x, fruit->pos.y);
				TextColor(rand() % 9 + 8);
				cout << char(4);
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
	}
	void DrawMap() {
		TextColor(Blue);
		system("cls");
		HideCursor();
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
		GotoXY(fruit->pos.x, fruit->pos.y);
		TextColor(rand() % 9 + 8);
		cout << char(4);
	}
	void DrawSnake() {
		TextColor(Blue);
		for (int i = 0; i < snake->tail.size() - 1; i++) {
			GotoXY(snake->tail[i].x, snake->tail[i].y);
			cout << (snake->cell[i] - '0') % snake->cell.size();
		}
		GotoXY(snake->tail.back().x, snake->tail.back().y);
		cout << " ";
		GotoXY(0, 0);
		cout << "Score: " << score;
	}
};
void StartGame();


#endif