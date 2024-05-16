#include "Game.h"


Game game;

void GameOver() {
	int cnt = 10;
	BackgroundColor(DarkWhite);
	while (cnt != 0) {
		for (int i = 1; i < game.snake->tail.size(); i++) {
			TextColor(rand() % 9 + 8);
			GotoXY(game.snake->tail[i].x, game.snake->tail[i].y);
			cout << (game.snake->cell[i - 1] - '0') % game.snake->cell.size();
		}
		Sleep(200);
		cnt--;
	}
	ofstream SCORE;
	SCORE.open("rank.txt", ios::app);

	SCORE << game.score << endl;

	SCORE.close();
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
	snake->pos = { CornerX + 7, (CornerY + HEIGHTMAP) / 2 + 4 };
	snake->tail.clear();
	for (int i = 0; i <= 3; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 15; j++) {
			int x, y;
			x = CornerX + 15 + j;
			y = CornerY + 6 + i;
			game.wall.push_back({ x, y });
			x += 42;
			game.wall.push_back({ x, y });
			x -= 21;
			y += 6;
			game.wall.push_back({ x, y });
			x -= 21;
			y += 6;
			game.wall.push_back({ x, y });
			x += 42;
			game.wall.push_back({ x, y });
		}
	}
	return Target_lv2;
}

int Level_03(Snake*& snake)
{
	snake->pos = { CornerX + 7, (CornerY + HEIGHTMAP) / 2 + 4 };
	snake->tail.clear();
	for (int i = 0; i <= 5; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}
	for (int i = 0; i < 50; i++) {
		int x = rand() % WIDTHMAP + CornerX;
		int y = rand() % HEIGHTMAP + CornerY;
		game.wall.push_back({ x, y });
	}
	return Target_lv3;
}

bool DrawLevel_01()
{
	game.InputLevel(Level_01);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.snake->Move();
		game.snake->Update();
		game.Logic();
		Sleep(100);
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
		game.snake->Move();
		game.snake->Update();
		game.Logic();
		Sleep(135);
		if (game.gate == true && game.posGate == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
	}
	GameOver();
	return true;
}

bool DrawLevel_03()
{
	game.InputLevel(Level_03);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.snake->Move();
		game.snake->Update();
		game.Logic();
		Sleep(100);
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
	SetConsoleWindow(WIDTHCONSOLE, HEIGHTCONSOLE);
	MoveCenter();
	while (Menu()) {
		game.Reset();
		if (DrawLevel_01())
			continue;
		if (DrawLevel_02())
			continue;
		if (DrawLevel_03())
			continue;
	}
}