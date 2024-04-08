#ifndef _SNAKE_H_
#define _SNAKE_H_


#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


enum Direction { STOP, UP, DOWN, LEFT, RIGHT };
struct Point { float x, y; };
struct Snake
{
	Point pos;
	void Move() {

	}
};


#endif
