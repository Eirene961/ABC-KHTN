#ifndef _CONSOLE_H_
#define _CONSOLE_H_


#include <Windows.h>


void FixConsoleWindow();
void SetConsoleWindow(int width, int height);
void MoveWindow(int posX, int poxY);
void MoveCenter();
void HideCursor();
void CloseConsole();
void GotoXY(int x, int y);
void SetCellSize(int x, int y);
void TextColor(int color);
void BackgroundColor(int color);


#endif