#include "Game.h"


Game game;

void GameOver() {
	int cnt = 10;
	while (cnt != 0) {
		for (int i = 1; i < game.snake->tail.size(); i++) {
			TextColor(rand() % 9 + 8);
			GotoXY(game.snake->tail[i].x, game.snake->tail[i].y);
			cout << (game.snake->cell[i - 1] - '0') % game.snake->cell.size();
		}
		Sleep(200);
		cnt--;
	}
	Sleep(1000);
}

int Level_01(Snake*& snake)
{
	snake->pos = { CornerX + 3, (CornerY + HEIGHTMAP) / 2 + 6 };
	snake->tail.clear();
	for (int i = 0; i <= 1; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}
	return Target_lv1;
}

int Level_02(Snake*& snake)
{
	snake->pos = { CornerX + 3, (CornerY + HEIGHTMAP) / 2 + 4 };
	snake->tail.clear();
	for (int i = 0; i <= 3; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}
	return Target_lv2;
}

bool DrawLevel_01()
{
	game.InputLevel(Level_01);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.Logic();
		game.snake->Move();
		game.snake->Update();
		Sleep(150);
		if (game.gate == true && game.posGate == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
	}
	GameOver();
	return true;
}

bool DrawLevel_02()
{
	game.InputLevel(Level_02);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.Logic();
		game.snake->Move();
		game.snake->Update();
		Sleep(135);
		if (game.gate == true && game.posGate == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
	}
	GameOver();
	return true;
}

void StartGame()
{
	srand(time(NULL));
	FixConsoleWindow();
	SetConsoleWindow(1280, 704);
	MoveCenter();
	if (!Menu())
		return;
	if (DrawLevel_01())
		return;
	if (DrawLevel_02())
		return;
}