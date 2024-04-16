#ifndef _GAME_H_
#define _GAME_H_


#include <time.h>
#include "Console.h"
#include "Menu.h"
#include "Snake.h"


#define WIDTHCONSOLE 1280
#define HEIGHTCONSOLE 704
#define Target_lv1 30
#define Target_lv2 100

int Level_01(Snake*& snake);
bool DrawLevel_01(Snake*& snake);
int Level_02(Snake*& snake);
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
		posGate = { 0, 1 };
	}
	~Game() {
		delete snake;
		delete fruit;
	}
	void RandomGate();
	void InputLevel(int(*Level)(Snake*&));
	void Logic();
	void DrawMap();
	void DrawSnake();
	void DrawFruit();
	void DrawGate();
};
void StartGame();


#endif