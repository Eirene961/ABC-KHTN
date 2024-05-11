#ifndef _MENU_H_
#define _MENU_H_


#include "Console.h"
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;


#define Back				0
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

#define MainColor Blue
#define DefaultColor		7
#define BACKGROUNDCOLOR		124
#define TEXTCOLOR			121

void Rank();
void About();
void Instruction();
void Setting();
bool Menu();



#endif