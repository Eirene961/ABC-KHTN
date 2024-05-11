#ifndef _CONSOLE_H_
#define _CONSOLE_H_

//screen: goto [x,y]
void gotoXY(int column, int line);

#include <Windows.h>

//screen: get [y]
int whereY();

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