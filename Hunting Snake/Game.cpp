#include "Game.h"


Game game;

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

int Level_01(Snake*& snake)
{
	game.level = 1;
	snake->pos = { 5, HEIGHTMAP / 2 };
	for (int i = 0; i <= 1; i++) {
		snake->tail.push_back({ snake->pos.x - i, snake->pos.y });
	}
	return Target_lv1;
}

int Level_02(Snake*& snake)
{
	game.level = 2;
	snake->pos = { 10, HEIGHTMAP / 2 };
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
	game.level = 3;
	snake->pos = { 20, 2 };
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
	game.level = 4;
	snake->pos = { 25, 20 };
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
	game.level = 5;
	snake->pos = { 35, 1 };
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

bool DrawLevel_01(bool playContinue)
{
	if (playContinue == false)
		game.InputLevel(Level_01);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.snake->Move();
		game.snake->Update();
		if (game.Logic())
			return true;
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(140);
	}
	game.GameOver();
	return true;
}

bool DrawLevel_02(bool playContinue)
{
	if (playContinue == false)
		game.InputLevel(Level_02);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.snake->Move();
		game.snake->Update();
		if (game.Logic())
			return true;
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(130);
	}
	game.GameOver();
	return true;
}

bool DrawLevel_03(bool playContinue)
{
	if (playContinue == false)
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
		if (game.Logic())
			return true;
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(120);
	}
	game.GameOver();
	return true;
}

bool DrawLevel_04(bool playContinue)
{
	if (playContinue == false)
		game.InputLevel(Level_04);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.DrawMonster();
		game.DrawTeleport();
		game.snake->Move();
		game.snake->Update();
		if (game.Logic())
			return true;
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(110);
	}
	game.GameOver();
	return true;
}

bool DrawLevel_05(bool playContinue)
{
	if (playContinue == false)
		game.InputLevel(Level_05);
	game.DrawMap();
	while (!game.snake->dead) {
		game.DrawSnake();
		game.DrawMonster();
		game.DrawTeleport();
		game.snake->Move();
		game.snake->Update();
		if (game.Logic())
			return true;
		if (game.gate == true && game.posGate[0] == game.snake->tail.back()) {
			Sleep(500);
			return false;
		}
		Sleep(100);
	}
	game.GameOver();
	return true;
}



void StartGame()
{
	srand(time(NULL));
	FixConsoleWindow();
	SetConsoleWindow(WIDTHCONSOLE, HEIGHTCONSOLE);
	MoveCenter();
	string fileContinue = "-1";
	while (Menu(0, fileContinue)) {
		game.Reset();
		game.score = 0;
		GotoXY(0, 0);
		cout << "Enter name: ";
		string name;
		do {
			cin >> name;
		} while (game.CheckNamePlayer(name));
		game.namePlayer.push_back(name);
		time_t currentTime = time(nullptr);
		ctime_s(game.currentTime, sizeof(string), &currentTime);
		
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

		ofstream file;
		file.open("RANK.txt", ios::app);
		file << game.namePlayer.back() << endl;
		file << game.level << endl;
		file << game.score << endl;
		file << game.currentTime << endl;
		file.close();
	}
	if (fileContinue != "-1") {
		PlayContinue(fileContinue);
	}
}


void PlayContinue(string fileContinue)
{
	GotoXY(0, 0);
	cout << fileContinue;
	game.Reset();
	fileContinue += ".txt";
	ifstream file(fileContinue);
	file >> game;
	file.close();
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
	}
	int levelGame = game.level;
	if (levelGame == 1) {
		if (DrawLevel_01(true)) {
			StartGame();
			return;
		}
	}
	if (levelGame == 2) {
		if (DrawLevel_02(true)) {
			StartGame();
			return;
		}
	}
	else if (levelGame < 2) {
		if (DrawLevel_02()) {
			StartGame();
			return;
		}
	}
	if (levelGame == 3) {
		if (DrawLevel_03(true)) {
			StartGame();
			return;
		}
	}
	else if (levelGame < 3) {
		if (DrawLevel_03()) {
			StartGame();
			return;
		}
	}
	if (levelGame == 4) {
		if (DrawLevel_04(true)) {
			StartGame();
			return;
		}
	}
	else if (levelGame < 4) {
		if (DrawLevel_04()) {
			StartGame();
			return;
		}
	}
	if (levelGame == 5) {
		if (DrawLevel_05(true)) {
			StartGame();
			return;
		}
	}
	else if (levelGame < 5) {
		if (DrawLevel_05()) {
			StartGame();
			return;
		}
	}
}











// ------------- STRUCT -------------
void Game::Reset()
{
	gate = false;
	time = 0;
	color = 0;
	snake->tail.clear();
	snake->dir = RIGHT;
	snake->dead = false;
	snake->stunned = false;
	posGate.clear();
	for (int i = 0; i < WIDTHMAP; i++) {
		if (wall[i].empty() == false)
			wall[i].clear();
	}
	monsterList.clear();
	teleport.clear();
	poison.clear();
}


void Game::InputLevel(int(*Level)(Snake*&))
{
	Reset();
	target = Level(snake);
	do {
		fruit->RandomFruit();
	} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos));
}


bool Game::CheckWall(Point position, bool tele)
{
	int x = position.x;
	int y = position.y;
	if (tele == true) {
		for (pair<Point, Point>& point : teleport) {
			if (position == point.first || position == point.second)
				return true;
		}
	}
	if (BinarySearch(wall[x], 0, wall[x].size() - 1, y))
		return true;
	return false;
}


void Game::RandomGate()
{
	int random = rand() % 2;
	int x, y;
	if (random == 0) {
		x = WIDTHMAP - 7;
		y = 8;
		if (CheckPoint(snake->tail, Point(x, y), true)) {
			x = 6;
			y = HEIGHTMAP - 9;
		}
	}
	else {
		x = 6;
		y = HEIGHTMAP - 9;
		if (CheckPoint(snake->tail, Point(x, y), true)) {
			x = WIDTHMAP - 7;
			y = 8;
		}
	}
	posGate.push_back({ x, y });
	posGate.push_back({ x + 1, y });
	for (int i = -1; i <= 1; i++) {
		posGate.push_back({ x + i, y - 1 });
		posGate.push_back({ x + i, y + 1 });
	}
}


void Game::Teleport()
{
	int y = snake->pos.y;
	for (pair<Point, Point>& point : teleport) {
		if (snake->pos == point.first)
			snake->pos = point.second;
		else if (snake->pos == point.second)
			snake->pos = point.first;
	}
}


bool Game::SnakeMeetMonster() {
	bool check = false;
	for (Monster& monster : monsterList) {
		for (Point point : monster.pos) {
			for (int i = 0; i < snake->tail.size() - 1; i++) {
				if (point == snake->tail[i]) {
					if (i != 0)
						snake->tail.erase(snake->tail.begin() + i);
					check = true;
				}
			}
		}
	}
	return check;
}


bool Game::FruitMeetMonster() {
	for (Monster& monster : monsterList) {
		for (Point point : monster.pos) {
			if (point == fruit->pos) {
				if (monster.type != WALL) {
					score -= 20;
					snake->stunned = true;
					if (snake->tail.size() <= 2)
						snake->dead = true;
					else {
						poison.push_back(snake->tail.back());
						snake->tail.pop_back();
						poison.push_back(snake->tail.back());
						snake->tail.pop_back();
					}
				}
				return true;
			}
		}
	}
	return false;
}


bool Game::CheckNamePlayer(string name) {
	for (string sign : namePlayer) {
		if (name == sign) {
			cout << "Please give another name, this one existed!";
			return true;
		}
	}
	return false;
}


bool Game::CheckNameSave(string name)
{
	for (string sign : nameSave) {
		if (name == sign) {
			cout << "Please give another name, this one existed!";
			return true;
		}
	}
	return false;
}


void Game::LoadGame(string name)
{
	nameSave.push_back(name);
	ofstream load("LOADGAME.txt", ios::app);
	load << name << endl;
	load << level << endl;
	load << score << endl;
	load << currentTime << endl;
	load.close();

	name += ".txt";
	ofstream file(name, ios::out);
	file << game;
	file.close();
}


bool Game::Pause()
{
	int width = 30;
	int height = 10;
	int x = CornerX + WIDTHMAP / 3;
	int y = CornerY + HEIGHTMAP / 4;

	TextColor(MainColor);
	BackgroundColor(Yellow);
	GotoXY(x, y);
	for (int i = 1; i <= width; i++) {
		if (i == 1 || i == width)
			cout << char(219);
		else
			cout << char(223);

	}
	for (int i = 1; i <= height; i++) {
		GotoXY(x, y + i);
		for (int j = 1; j <= width; j++) {
			if (j == 1 || j == width)
				cout << char(219);
			else
				cout << ' ';
		}
	}
	GotoXY(x + 1, y + height);
	for (int i = 1; i < width - 1; i++)
		cout << char(220);

	vector<string> selections = { "CONTINUE", "SAVE GAME", "MUSIC", "EXIT" };
	bool quit = false;
	int cursorPos = 0;
	do {
		for (int i = 0; i < selections.size(); i++) {
			if (i == cursorPos)
				TextColor(Pink);
			else
				TextColor(Grey);
			GotoXY(x + 3, y + i + 1);
			cout << selections[i];
		}
		TextColor(Grey);
		char input = tolower(_getch());
		switch (input) {
		case 'w':
			if (cursorPos > 0)
				cursorPos--;
			break;
		case 's':
			if (cursorPos < selections.size() - 1)
				cursorPos++;
			break;
		case '\r':
			string name;
			switch (cursorPos) {
			case 0:
				return true;
				break;
			case 1:
				GotoXY(0, 0);
				cout << "Enter name: ";
				do {
					cin >> name;
				} while (CheckNameSave(name));
				LoadGame(name);
				break;
			case 2:
				break;
			case 3:
				quit = true;
				break;
			}
		}
	} while (!quit);
	return false;
}


bool Game::Logic() {
	if (GetAsyncKeyState('p') || GetAsyncKeyState('P')) {
		if (Pause())
			DrawMap();
		else
			return true;
	}


	if (snake->pos == fruit->pos && gate == false) {
		score += 10;
		GotoXY(CornerX + WIDTHMAP + 12, CornerY + 3);
		TextColor(MainColor);
		BackgroundColor(Yellow);
		cout << score << "   ";
		BackgroundColor(MainBackground);
		snake->tail.push_back(snake->pos);
		snake->stunned = false;
		if (score != target) {
			do {
				fruit->RandomFruit();
			} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos, true));
			GotoXY(fruit->pos.x + CornerX, fruit->pos.y + CornerY);
			TextColor(Red);
			cout << char(1);
		}
		else {
			gate = true;
			RandomGate();
			TextColor(Pink);
			GotoXY(posGate[0].x + CornerX, posGate[0].y + CornerY);
			cout << char(179);
			for (int i = 1; i <= 7; i++) {
				GotoXY(posGate[i].x + CornerX, posGate[i].y + CornerY);
				cout << char(219);
			}
		}
	}
	if (gate == true) {
		color %= 3;
		if (color == 0)
			TextColor(Red);
		else if (color == 1)
			TextColor(DarkGreen);
		else
			TextColor(DarkYellow);
		color++;
		GotoXY(posGate[0].x + CornerX, posGate[0].y + CornerY);
		cout << char(179);
		if (snake->pos == posGate[0])
			snake->dir = STOP;
		for (int i = 1; i < posGate.size(); i++) {
			if (snake->pos == posGate[i])
				snake->dead = true;
		}
	}
	if (FruitMeetMonster()) {
		do {
			fruit->RandomFruit();
		} while (CheckPoint(snake->tail, fruit->pos) || CheckWall(fruit->pos));
		GotoXY(fruit->pos.x + CornerX, fruit->pos.y + CornerY);
		TextColor(Red);
		cout << char(1);
	}
	if (CheckWall(snake->pos) || SnakeMeetMonster())
		snake->dead = true;
	for (Point point : poison) {
		if (snake->pos == point) {
			score += 10;
			snake->tail.push_back(point);
			snake->stunned = true;
		}
	}
	Teleport();
	return false;
}


void Game::DrawMap()
{
	system("cls");
	system("color F0");
	TextColor(MainColor);
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

	// Fruit / Gate
	if (gate == false) {
		GotoXY(fruit->pos.x + CornerX, fruit->pos.y + CornerY);
		TextColor(Red);
		cout << char(1);
	}
	else {
		GotoXY(posGate[0].x + CornerX, posGate[0].y + CornerY);
		cout << char(179);
		for (int i = 1; i <= 7; i++) {
			GotoXY(posGate[i].x + CornerX, posGate[i].y + CornerY);
			cout << char(219);
		}
	}

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




	// INSTRUCTION
	TextColor(MainColor);
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
	cout << "PLAYER NAME: " << namePlayer.back();
	GotoXY(x, CornerY + 2);
	cout << "LEVEL: " << game.level;
	GotoXY(x, CornerY + 3);
	cout << "SCORE: " << game.score;
	GotoXY(x, CornerY + 4);
	cout << "TARGET: " << game.target;

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


void Game::DrawTeleport() {
	color %= 3;
	if (color == 0)
		TextColor(Red);
	else if (color == 1)
		TextColor(DarkGreen);
	else
		TextColor(DarkYellow);
	color++;
	for (pair<Point, Point>& point : teleport) {
		GotoXY(CornerX + point.first.x, CornerY + point.first.y);
		cout << char(179);
		GotoXY(CornerX + point.second.x, CornerY + point.second.y);
		cout << char(179);
	}
}


void Game::DrawSnake() {
	TextColor(MainColor);
	BackgroundColor(White);
	for (int i = 0; i < snake->tail.size() - 1; i++) {
		int num = i % snake->cell.size();
		if (num < 8)
			TextColor(Red);
		else if (num < 16)
			TextColor(DarkCyan);
		else if (num < 24)
			TextColor(DarkGreen);
		else if (num < 32)
			TextColor(DarkYellow);
		else
			TextColor(Pink);
		GotoXY(snake->tail[i].x + CornerX, snake->tail[i].y + CornerY);
		cout << snake->cell[num] - '0';
	}
	GotoXY(snake->tail.back().x + CornerX, snake->tail.back().y + CornerY);
	BackgroundColor(MainBackground);
	cout << " ";
}


void Game::DrawMonster() {
	TextColor(MainColor);
	BackgroundColor(MainBackground);
	for (Monster& monster : monsterList) {
		monster.Move();
		if (monster.type == WALL) {
			for (int i = 0; i < monster.pos.size(); i++) {
				GotoXY(monster.pos[i].x + CornerX, monster.pos[i].y + CornerY);
				cout << char(178);
			}
			GotoXY(monster.erase[0].x + CornerX, monster.erase[0].y + CornerY);
			cout << ' ';
		}
		else if (monster.type == CRAB) {
			for (int i = 0; i <= 17; i++) {
				GotoXY(monster.pos[i].x + CornerX, monster.pos[i].y + CornerY);
				if (i == 0 || i == 5 || i == 9 || i == 15)
					cout << 'o';
				else if (i == 1 || i == 2 || i == 16 || i == 17)
					cout << 'O';
				else
					cout << char(219);
			}
			for (Point point : monster.erase) {
				GotoXY(point.x + CornerX, point.y + CornerY);
				cout << ' ';
			}
		}
	}
}


void Game::GameOver() {
	int cnt = 15;
	while (cnt != 0) {
		for (int i = 1; i < snake->tail.size(); i++) {
			if (cnt % 2 == 0) {
				int num = (i - 1) % snake->cell.size();
				if (num < 8)
					TextColor(Red);
				else if (num < 16)
					TextColor(DarkCyan);
				else if (num < 24)
					TextColor(DarkGreen);
				else if (num < 32)
					TextColor(DarkYellow);
				else
					TextColor(Pink);
				GotoXY(snake->tail[i].x + CornerX, snake->tail[i].y + CornerY);
				cout << (snake->cell[i - 1] - '0') % snake->cell.size();
			}
			else {
				GotoXY(snake->tail[i].x + CornerX, snake->tail[i].y + CornerY);
				cout << ' ';
			}
		}
		Sleep(150);
		cnt--;
	}
	Sleep(1000);
	ofstream file;
	file.open("RANK.txt", ios::app);
	file << namePlayer.back() << endl;
	file << level << endl;
	file << score << endl;
	file << currentTime << endl;
	file.close();

}