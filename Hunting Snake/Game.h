#ifndef _GAME_H_
#define _GAME_H_


#include <time.h>
#include "Console.h"
#include "Menu.h"
#include "Snake.h"
#include "Sound.h"
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

#define WIDTHCONSOLE 1100
#define HEIGHTCONSOLE 700
#define Target_lv1 70
#define Target_lv2 150
#define Target_lv3 230
#define Target_lv4 310
#define Target_lv5 390
bool BinarySearch(vector<int> v, int l, int r, int x);
void Insert(vector<int>& v, int x);
void EatingSound();
int Level_01(Snake*& snake);
int Level_02(Snake*& snake);
int Level_03(Snake*& snake);
int Level_04(Snake*& snake);
int Level_05(Snake*& snake);
bool DrawLevel_01(bool playContinue = false);
bool DrawLevel_02(bool playContinue = false);
bool DrawLevel_03(bool playContinue = false);
bool DrawLevel_04(bool playContinue = false);
bool DrawLevel_05(bool playContinue = false);
struct Game
{
	Snake* snake;
	Fruit* fruit;
	int level;
	int score;
	int target;
	char* currentTime;
	bool gate;
	vector<Point> posGate;
	vector<int> wall[WIDTHMAP];
	int time;
	vector<Monster> monsterList;
	int color;
	vector<pair<Point,Point>> teleport;
	vector<Point> poison;

	string nameGame;
	vector<string> namePlayer;
	vector<string> nameSave;

	bool music;

	Game() {
		snake = new Snake;
		fruit = new Fruit;
		level = 0;
		score = 0;
		currentTime = new char[26];
		target = 0;
		gate = false;
		time = 0;
		color = 0;
		music = true;
	}
	~Game() {
		delete snake;
		delete fruit;
	}

	friend ifstream& operator >> (ifstream& file, Game& game) {
		file >> *game.snake;
		file >> *game.fruit;
		file >> game.level;
		file >> game.score;
		file >> game.target;
		file.ignore();
		file.getline(game.currentTime, 26);
		file >> game.gate;
		if (game.gate) {
			for (int i = 0; i <= 7; i++) {
				Point point;
				file >> point;
				game.posGate.push_back(point);
			}
		}
		file.ignore();
		for (int i = 0; i < WIDTHMAP; i++) {
			string s;
			getline(file, s);
			stringstream ss(s);
			string token;
			while (ss >> token) {
				game.wall[i].push_back(stoi(token));
			}
		}
		file >> game.time;
		int sizeMonster;
		file >> sizeMonster;
		for (int i = 0; i < sizeMonster; i++) {
			Monster monster;
			file >> monster;
			game.monsterList.push_back(monster);
		}
		file >> game.color;
		int sizeTele;
		file >> sizeTele;
		for (int i = 0; i < sizeTele; i++) {
			pair<Point, Point> tele;
			file >> tele.first;
			file >> tele.second;
			game.teleport.push_back((tele));
		}
		int sizePoison;
		file >> sizePoison;
		for (int i = 0; i < sizePoison; i++) {
			Point point;
			file >> point;
			game.poison.push_back(point);
		}

		return file;
	}

	friend ofstream& operator << (ofstream& file, Game& game) {
		file << *game.snake;
		file << *game.fruit;
		file << game.level << endl;
		file << game.score << endl;
		file << game.target << endl;
		file << game.currentTime << endl;
		file << game.gate << endl;
		if (game.gate) {
			for (int i = 0; i <= 7; i++)
				file << game.posGate[i];
		}
		for (int i = 0; i < WIDTHMAP; i++) {
			for (int j = 0; j < game.wall[i].size(); j++) {
				file << game.wall[i][j] << ' ';
			}
			file << endl;
		}
		file << game.time << endl;
		int sizeMonster = game.monsterList.size();
		file << sizeMonster << endl;
		for (int i = 0; i < sizeMonster; i++) {
			file << game.monsterList[i];
		}
		file << game.color << endl;
		int sizeTele = game.teleport.size();
		file << sizeTele << endl;
		for (int i = 0; i < sizeTele; i++) {
			file << game.teleport[i].first;
			file << game.teleport[i].second;
		}
		int sizePoison = game.poison.size();
		file << sizePoison << endl;
		for (int i = 0; i < sizePoison; i++) {
			file << game.poison[i];
		}
		
		return file;
	}

	void Reset();
	void InputLevel(int(*Level)(Snake*&));
	bool CheckWall(Point position, bool tele = false);
	void RandomGate();
	void Teleport();
	bool SnakeMeetMonster();
	bool FruitMeetMonster();
	bool CheckNamePlayer(string name);
	void LoadGame(string name);
	bool Pause();
	bool Logic();
	void DrawMap();
	void DrawInstruction();
	void DrawTeleport();
	void DrawSnake();
	void DrawMonster();
	void GameOver();
};
void StartGame();


#endif