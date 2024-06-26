#ifndef _MENU_H_
#define _MENU_H_


#include "Console.h"
#include "Sound.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <mmsystem.h>
using namespace std;


#define Black				0
#define DarkBlue			1
#define DarkGreen			2
#define DarkCyan			3
#define DarkRed				4
#define DarkPink			5
#define DarkYellow			6
#define DarkWhite			7
#define Grey				8
#define Blue				9
#define Green				10
#define Cyan				11
#define Red					12
#define Pink				13
#define Yellow				14
#define White				15

#define MainColor DarkGreen
#define MainBackground White
#define DefaultColor		7
#define BACKGROUNDCOLOR		124
#define TEXTCOLOR			121

struct Save {
	string name;
	int level;
	int score;
	string time;
};

bool cmp(Save a, Save b);

int Continue();
void Rank();
void About();
void Setting();
int Menu(int cursorPos);



#endif