#ifndef _GAME_H_
#define _GAME_H_


#include <time.h>
#include "Console.h"
#include "Menu.h"
#include "Snake.h"
#include <fstream>
#include <string.h>

#define WIDTHCONSOLE 1100
#define HEIGHTCONSOLE 700
#define Target_lv1 70
#define Target_lv2 150
#define Target_lv3 230
#define Target_lv4 310
#define Target_lv5 390
bool CheckNamePlayer(string name);
bool BinarySearch(vector<int> v, int l, int r, int x);
void Insert(vector<int>& v, int x);
void GameOver();
int Level_01(Snake*& snake);
int Level_02(Snake*& snake);
int Level_03(Snake*& snake);
int Level_04(Snake*& snake);
int Level_05(Snake*& snake);
bool DrawLevel_01();
bool DrawLevel_02();
bool DrawLevel_03();
bool DrawLevel_04();
bool DrawLevel_05();
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
	}
	~Game() {
		delete snake;
		delete fruit;
	}

	friend ofstream& operator << (ofstream& file, Game& game) {
		file << *game.snake;
		file << *game.fruit;
		file << game.level << endl;
		file << game.score << endl;
		file << game.target << endl;
		file << game.currentTime;
		file << game.gate << endl;
		int sizeGate = game.posGate.size();
		file << sizeGate << endl;
		for (int i = 0; i < sizeGate; i++)
			file << game.posGate[i];
		for (int i = 0; i < WIDTHMAP; i++) {
			for (int j = 0; j < game.wall[i].size(); j++) {
				file << game.wall[i][j];
				if (j != game.wall[i].size() - 1)
					file << ' ';
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
	bool CheckNameSave(string name);
	void LoadGame(string name);
	bool Pause();
	bool Logic();
	void DrawMap();
	void DrawTeleport();
	void DrawSnake();
	void DrawMonster();
};
void StartGame();


#endif