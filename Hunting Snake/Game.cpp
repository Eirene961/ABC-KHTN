#include "Game.h"


void Level_01(Snake*& snake)
{
	snake->pos = { CornerX + 3, (CornerY + HEIGHTMAP) / 2 + 2 };
	snake->tail.clear();
	snake->tail.push_back(snake->pos);
	snake->tail.push_back({ 0, 0 });
}

void StartGame()
{
	srand(time(NULL));
	FixConsoleWindow();
	SetConsoleWindow(1280, 704);
	MoveCenter();
	if (!Menu())
		return;
	Game game;
	game.DrawMap();
	game.InputLevel(Level_01);
	while (!game.snake->dead) {
		game.Logic();
		game.DrawSnakeAndFruit();
		game.snake->Move();
		game.snake->Update();
		Sleep(100);
	}
}