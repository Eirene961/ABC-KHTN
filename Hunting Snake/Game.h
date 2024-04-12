#ifndef _GAME_H_
#define _GAME_H_


#include <time.h>
#include "Console.h"
#include "Snake.h"


#define WIDTHCONSOLE 1280
#define HEIGHTCONSOLE 704

void Level_01(Snake*& snake);
struct Game
{
	Snake* snake;
	Fruit* fruit;
	int score;

	Game() {
		snake = new Snake;
		fruit = new Fruit;
		score = 0;
	}
	void InputLevel(void(*Level)(Snake*&)) {
		Level(snake);
		fruit->RandomFruit();
	}
	void Logic() {
		if (snake->pos.x == fruit->pos.x && snake->pos.y == fruit->pos.y) {
			score += 10;
			snake->tail.push_back(snake->pos);
			do {
				fruit->RandomFruit();
			} while (CheckFruit(snake->tail, fruit->pos));
		}
	}
	void DrawMap() {
		system("cls");
		HideCursor();
		for (int i = 0; i < CornerY - 2; i++)
			cout << endl;
		for (int i = 0; i < WIDTHMAP + 7; i++) {
			if (i < 4)
				cout << " ";
			else
				cout << char(220);
		}
		cout << endl;
		for (int i = 0; i < HEIGHTMAP; i++) {
			for (int j = 0; j < WIDTHMAP + 7; j++) {
				if (j == 4 || j == WIDTHMAP + 6)
					cout << char(219);
				else
					cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < WIDTHMAP + 7; i++) {
			if (i < 4)
				cout << " ";
			else
				cout << char(223);
		}
	}
	void DrawSnakeAndFruit() {
		GotoXY(fruit->pos.x, fruit->pos.y);
		cout << "F";
		for (int i = 0; i < snake->tail.size() - 1; i++) {
			GotoXY(snake->tail[i].x, snake->tail[i].y);
			cout << snake->cell[i];
		}
		GotoXY(snake->tail.back().x, snake->tail.back().y);
		cout << " ";
	}
};
void StartGame();


#endif