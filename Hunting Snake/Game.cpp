#include "Game.h"


int Level_01(Snake*& snake)
{
	snake->tail.clear();
	snake->pos = { CornerX + 4, (CornerY + HEIGHTMAP) / 2 + 2 };
	for (int i = 0; i <= 2; i++)
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	snake->dir = STOP;
	return Target_lv1;
}

int Level_02(Snake*& snake)
{
	return Target_lv2;
}

bool DrawLevel_01(Snake*& snake)
{
	while (snake->dead == false) {

	}
	return true;
}

// Struct
void Game::RandomGate()
{
	do {
		int x = rand() % WIDTHMAP + CornerX;
		int y = rand() % HEIGHTMAP + CornerY;
		posGate = { x, y };
	} while (CheckPoint(snake->tail, posGate));
}

void Game::InputLevel(int(*Level)(Snake*&))
{
	target = Level(snake);
	do {
		fruit->RandomFruit();
	} while (CheckPoint(snake->tail, fruit->pos) && gate == false);
}

void Game::Logic()
{
	if (snake->pos.x == fruit->pos.x && snake->pos.y == fruit->pos.y) {
		score += 10;
		GotoXY(7, 0);
		TextColor(Blue);
		cout << score;
		snake->tail.push_back(snake->pos);
		do {
			fruit->RandomFruit();
		} while (CheckPoint(snake->tail, fruit->pos));
	}
	if (score == target) {
		gate = true;
		RandomGate();
		target = 0;
	}
}

void Game::DrawMap()
{
	TextColor(Blue);
	system("cls");
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
	GotoXY(0, 0);
	cout << "Score: " << score;
	
}

void Game::DrawSnake()
{
	TextColor(Blue);
	for (int i = 0; i < snake->tail.size() - 1; i++) {
		GotoXY(snake->tail[i].x, snake->tail[i].y);
		cout << (snake->cell[i] - '0') % snake->cell.size();
	}
	GotoXY(snake->tail.back().x, snake->tail.back().y);
	cout << " ";
}

void Game::DrawFruit()
{
	if (gate == false) {
		GotoXY(fruit->pos.x, fruit->pos.y);
		TextColor(rand() % 9 + 8);
		cout << char(4);
	}
}

void Game::DrawGate()
{
	GotoXY(posGate.x, posGate.y);
	cout << char(219);
}
//

void StartGame()
{
	srand(time(NULL));
	FixConsoleWindow();
	SetConsoleWindow(1280, 704);
	MoveCenter();
	HideCursor();
	Menu();
	Game game;
	game.DrawMap();
	game.InputLevel(Level_01);
	while (!game.snake->dead) {
		game.Logic();
		game.DrawSnake();
		if (game.gate == false)
			game.DrawFruit();
		else
			game.DrawGate();
		if (game.snake->pos.x == game.posGate.x && game.snake->pos.y == game.posGate.y) {
			game.snake->dir = STOP;
			game.snake->Update();
		}
		game.snake->Move();
		if(game.snake->dir != STOP)
			game.snake->Update();
		Sleep(1000);
	}
}