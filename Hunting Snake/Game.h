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