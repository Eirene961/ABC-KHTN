#include "Game.h"


bool BinarySearch(vector<int> v, int l, int r, int x)
{
	while (l <= r) {
		int m = (l + r) / 2;
		if (v[m] == x)
			return true;
		else if (v[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return false;
}

void Insert(vector<int>& v, int x) {
	int l = 0, r = v.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (v[m] <= x)
			l = m + 1;
		else
			r = m - 1;
	}
	v.insert(v.begin() + l, x);
}

Game game;

void GameOver() {
	int cnt = 10;
	BackgroundColor(DarkWhite);
	while (cnt != 0) {
		for (int i = 1; i < game.snake->tail.size(); i++) {
			TextColor(rand() % 9 + 8);
			GotoXY(game.snake->tail[i].x + CornerX, game.snake->tail[i].y + CornerY);
			cout << (game.snake->cell[i - 1] - '0') % game.snake->cell.size();
		}
		Sleep(200);
		cnt--;
	}
	Sleep(1000);
}

int Level_01(Snake*& snake)
{
	snake->pos = { 5, HEIGHTMAP / 2 };
	snake->tail.clear();
	for (int i = 0; i <= 1; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}
	return Target_lv1;
}

int Level_02(Snake*& snake)
{
	snake->pos = { 10, HEIGHTMAP / 2 };
	snake->tail.clear();
	for (int i = 0; i <= 8; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}

	int centerX = WIDTHMAP / 2;
	int centerY = HEIGHTMAP / 2;
	for (int i = -1; i <= 1; i++) {
		for (int j = -7; j <= 7; j++) {
			Insert(game.wall[centerX + j - 1], centerY + i);
			int x = centerX / 2;
			int y = centerY / 2;
			Insert(game.wall[x + j], y + i + 1);
			x *= 3;
			Insert(game.wall[x + j], y + i + 1);
			x /= 3;
			y *= 3;
			Insert(game.wall[x + j], y + i + 1);
			x *= 3;
			Insert(game.wall[x + j], y + i + 1);
		}
	}

	return Target_lv2;
}

int Level_03(Snake*& snake)
{
	snake->pos = { 20, 2 };
	snake->tail.clear();
	for (int i = 0; i <= 16; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}

	// TELEPORT
	int y = HEIGHTMAP / 2;
	for (int i = -3; i <= 2; i++) {
		game.teleport[y + i].push_back({ 0, WIDTHMAP - 1 });
	}

	// WALL
	game.wall[0].push_back(y - 4);
	game.wall[0].push_back(y + 3);
	game.wall[WIDTHMAP - 1].push_back(y - 4);
	game.wall[WIDTHMAP - 1].push_back(y + 3);
	int x;
	for (x = 10; x < WIDTHMAP / 2 - 5; x++) {
		Insert(game.wall[x], 4);
		Insert(game.wall[x], HEIGHTMAP - 5);
		Insert(game.wall[WIDTHMAP - x], 4);
		Insert(game.wall[WIDTHMAP - x], HEIGHTMAP - 5);
	}
	x--;
	for (int y = 6; y <= 10; y++) {
		Insert(game.wall[x], y - 1);
		Insert(game.wall[x - 1], y - 1);
		Insert(game.wall[x], HEIGHTMAP - y);
		Insert(game.wall[x - 1], HEIGHTMAP - y);
		Insert(game.wall[x + 12], y - 1);
		Insert(game.wall[x + 13], y - 1);
		Insert(game.wall[x + 12], HEIGHTMAP - y);
		Insert(game.wall[x + 13], HEIGHTMAP - y);
	}

	// MONSTER
	Monster monster;
	monster.type = WALL;
	// LEFT
	y = HEIGHTMAP / 2 - 2;
	for (int i = 0; i < 4; i++) {
		monster.pos.push_back(Point(11, y + i));
	}
	monster.erase.push_back(Point(11, y + 3));
	monster.bound = make_pair(Point(11, 5), Point(11, HEIGHTMAP - 6));
	monster.dir = UP;
	game.monsterList.push_back(monster);
	monster.Clear();

	// RIGHT
	for (int i = 0; i < 4; i++) {
		monster.pos.push_back(Point(WIDTHMAP - 11, y + i));
	}
	monster.erase.push_back(Point(WIDTHMAP - 11, y));
	monster.bound = make_pair(Point(WIDTHMAP - 11, 5), Point(WIDTHMAP - 11, HEIGHTMAP - 6));
	monster.dir = DOWN;
	game.monsterList.push_back(monster);
	monster.Clear();

	// UP
	x = WIDTHMAP / 2;
	for (int i = 0; i < 4; i++) {
		monster.pos.push_back(Point(x, i));
	}
	monster.erase.push_back(Point(x, 0));
	monster.bound = make_pair(Point(x, 0), Point(x, HEIGHTMAP / 2 - 1));
	monster.dir = DOWN;
	game.monsterList.push_back(monster);
	monster.Clear();

	// DOWN
	for (int i = 0; i < 4; i++) {
		monster.pos.push_back(Point(x, HEIGHTMAP - 4 + i));
	}
	monster.erase.push_back(Point(x, HEIGHTMAP - 1));
	monster.bound = make_pair(Point(x, HEIGHTMAP / 2), Point(x, HEIGHTMAP - 1));
	monster.dir = UP;
	game.monsterList.push_back(monster);
	monster.Clear();

	return Target_lv3;
}

bool DrawLevel_01()
{
	game.InputLevel(Level_01);
	game.DrawMap();
	while (!game.snake->dead) {
		game.Run();
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(100);
	}
	GameOver();
	return true;
}

bool DrawLevel_02()
{
	game.InputLevel(Level_02);
	game.DrawMap();
	while (!game.snake->dead) {
		game.Run();
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(135);
	}
	GameOver();
	return true;
}

bool DrawLevel_03()
{
	game.InputLevel(Level_03);
	game.DrawMap();
	while (!game.snake->dead) {
		game.Run();
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(100);
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
		/*if (DrawLevel_01())
			continue;
		if (DrawLevel_02())
			continue;*/
		if (DrawLevel_03())
			continue;
	}
}