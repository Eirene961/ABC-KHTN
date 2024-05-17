#include "Game.h"


vector<string> nameGame;

bool CheckName(string name) {
	for (string sign : nameGame) {
		if (name == sign) {
			cout << "Please give another name, this one existed!";
			return true;
		}
	}
	return false;
}

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
			TextColor(rand() % 4 + 10);
			GotoXY(game.snake->tail[i].x + CornerX, game.snake->tail[i].y + CornerY);
			cout << (game.snake->cell[i - 1] - '0') % game.snake->cell.size();
		}
		Sleep(200);
		cnt--;
	}
	Sleep(1000);

	TextColor(MainColor);
	GotoXY(0, 1);
	cout << "Do you want to save the game?\n"
		<< "YES: Y\n"
		<< "NO: N\n";
	bool check = false;
	while (true) {
		bool out = false;
		if (_kbhit()) {
			char cur = toupper(_getch());
			switch (cur) {
			case 'Y':
				out = true;
				check = true;
				break;
			case 'N':
				out = true;
				check = false;
				break;
			}
		}
		if (out == true)
			break;
	}
	if (check) {
		cout << "Enter name: ";
		string name;
		do {
			cin >> name;
		} while (CheckName(name));
		ofstream file;
		file.open("Rank.txt", ios::app);
		file << name << endl;
		file << game.score << endl;
		file.close();
	}
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
		game.teleport.push_back(make_pair(Point(0, y + i), Point(WIDTHMAP - 1, y + i)));
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
	// Left
	y = HEIGHTMAP / 2 - 2;
	monster.dir = UP;
	monster.Input(Point(11, y));
	monster.boundList.push_back(make_pair(Point(11, 5), Point(11, HEIGHTMAP - 6)));
	game.monsterList.push_back(monster);
	monster.Clear();

	// Right
	monster.dir = DOWN;
	monster.Input(Point(WIDTHMAP - 11, y));
	monster.boundList.push_back(make_pair(Point(WIDTHMAP - 11, 5), Point(WIDTHMAP - 11, HEIGHTMAP - 6)));
	game.monsterList.push_back(monster);
	monster.Clear();

	// Up
	x = WIDTHMAP / 2;
	monster.dir = DOWN;
	monster.Input(Point(x, 0));
	monster.boundList.push_back(make_pair(Point(x, 0), Point(x, HEIGHTMAP / 2 - 1)));
	game.monsterList.push_back(monster);
	monster.Clear();

	// Down
	monster.dir = UP;
	monster.Input(Point(x, HEIGHTMAP - 4));
	monster.boundList.push_back(make_pair(Point(x, HEIGHTMAP / 2), Point(x, HEIGHTMAP - 1)));
	game.monsterList.push_back(monster);
	monster.Clear();

	return Target_lv3;
}

int Level_04(Snake*& snake)
{
	snake->pos = { 25, 20 };
	snake->tail.clear();
	for (int i = 0; i <= 24; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}

	// MONSTER
	Monster monster;
	monster.type = CRAB;
	monster.dir = UP;
	int x = WIDTHMAP / 4 - 2;
	int y = HEIGHTMAP / 2 - 3;
	monster.Input(Point(3 * x + 5, HEIGHTMAP - 6));
	monster.trigger.push_back(Point(x, y));
	monster.trigger.push_back(Point(3 * x + 5, y));
	monster.boundList.push_back(make_pair(Point(x, 0), Point(x + 4, HEIGHTMAP - 1)));
	monster.boundList.push_back(make_pair(Point(3 * x + 5, 0), Point(3 * x + 9, HEIGHTMAP - 1)));
	monster.boundList.push_back(make_pair(Point(0, y), Point(WIDTHMAP - 1, y + 5)));
	game.monsterList.push_back(monster);
	monster.Clear();


	return Target_lv4;
}

int Level_05(Snake*& snake)
{
	snake->pos = { 35, 1 };
	snake->tail.clear();
	for (int i = 0; i <= 32; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}

	// TELEPORT
	game.teleport.push_back(make_pair(Point(0, 3), Point(WIDTHMAP - 1, HEIGHTMAP - 4)));
	game.teleport.push_back(make_pair(Point(0, 4), Point(WIDTHMAP - 1, HEIGHTMAP - 5)));

	// WALL
	game.wall[0].push_back(2);
	game.wall[0].push_back(5);
	game.wall[WIDTHMAP - 1].push_back(HEIGHTMAP - 6);
	game.wall[WIDTHMAP - 1].push_back(HEIGHTMAP - 3);

	// MONSTER
	Monster monster;
	int x = WIDTHMAP / 2 - 4;
	int y = 10;

	// Wall Left
	monster.type = WALL;
	for (int i = 0; i < 10; i++) {
		monster.pos.push_back(Point(i, y));
	}
	monster.erase.push_back(monster.pos[0]);
	monster.dir = RIGHT;
	monster.boundList.push_back(make_pair(Point(0, y), Point(x, y)));
	game.monsterList.push_back(monster);
	monster.Clear();

	// Wall Right
	for (int i = 0; i < 10; i++) {
		monster.pos.push_back(Point(WIDTHMAP - 10 + i, HEIGHTMAP - 1 - y));
	}
	monster.erase.push_back(monster.pos.back());
	monster.dir = LEFT;
	monster.boundList.push_back(make_pair(Point(WIDTHMAP - 1 - x, HEIGHTMAP - 1 - y), Point(WIDTHMAP - 1, HEIGHTMAP - 1 - y)));
	game.monsterList.push_back(monster);
	monster.Clear();

	// Crab
	monster.type = CRAB;
	monster.dir = RIGHT;
	monster.Input(Point(0, HEIGHTMAP - 6));
	monster.boundList.push_back(make_pair(Point(0, HEIGHTMAP - 6), Point(WIDTHMAP - 1, 5)));
	monster.trigger.push_back(Point(x + 1, HEIGHTMAP - 6));
	monster.trigger.push_back(Point(x + 1, 0));
	monster.randomDirection = 1;
	game.monsterList.push_back(monster);
	monster.Clear();

	return Target_lv5;
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
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(140);
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
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(130);
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
		game.time %= 2;
		if (game.time == 0)
			game.DrawMonster();
		game.time++;
		game.DrawTeleport();
		game.snake->Move();
		game.snake->Update();
		game.Logic();
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(120);
	}
	GameOver();
	return true;
}

bool DrawLevel_04()
{
	game.InputLevel(Level_04);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.DrawMonster();
		game.DrawTeleport();
		game.snake->Move();
		game.snake->Update();
		game.Logic();
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(110);
	}
	GameOver();
	return true;
}

bool DrawLevel_05()
{
	game.InputLevel(Level_05);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.DrawMonster();
		game.DrawTeleport();
		game.snake->Move();
		game.snake->Update();
		game.Logic();
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
	while (Menu(0)) {
		game.Reset();
		/*if (DrawLevel_01())
			continue;
		if (DrawLevel_02())
			continue;
		if (DrawLevel_03())
			continue;
		if (DrawLevel_04())
			continue;*/
		if (DrawLevel_05())
			continue;
	}
}

// ------------- STRUCT -------------
void Game::DrawMap()
{
	TextColor(MainColor);
	system("cls");
	HideCursor();

	// MAP
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

	// Fruit
	GotoXY(fruit->pos.x + CornerX, fruit->pos.y + CornerY);
	TextColor(Red);
	cout << char(1);

	// WALL
	TextColor(MainColor);
	for (int i = 0; i < WIDTHMAP; i++) {
		for (int y : wall[i]) {
			GotoXY(i + CornerX, y + CornerY);
			cout << char(178);
		}
	}

	// TELEPORT
	DrawTeleport();




	// NAVIGATION
	TextColor(DarkGreen);
	int x = CornerX + WIDTHMAP + 3;
	GotoXY(x, 1);
	for (int j = 0; j <= 32; j++)
		cout << char(220);
	for (int i = 2; i < CornerY + HEIGHTMAP; i++) {
		GotoXY(x, i);
		BackgroundColor(Yellow);
		cout << char(219);
		for (int j = 1; j <= 31; j++) {
			if (i == CornerY - 1)
				cout << char(220);
			else
				cout << ' ';
		}
		cout << char(219);
	}
	GotoXY(x, CornerY + HEIGHTMAP);
	BackgroundColor(MainBackground);
	for (int j = 0; j <= 32; j++)
		cout << char(223);

	BackgroundColor(Yellow);
	x += 2;
	GotoXY(x, CornerY + 1);
	cout << "PLAYER NAME: ";

	GotoXY(100, 14);
	cout << "----LEVER: ???" << "----";
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
}