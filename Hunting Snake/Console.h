#ifndef _CONSOLE_H_
#define _CONSOLE_H_


#include <Windows.h>


void FixConsoleWindow();
void SetConsoleWindow(int width, int height);
void MoveWindow(int posX, int poxY);
void MoveCenter();
void HideCursor();

#endif