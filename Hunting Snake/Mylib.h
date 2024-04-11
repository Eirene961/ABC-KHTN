#pragma once  //tránh ??ng ?? th? vi?n khi g?i ch?ng file
#include<stdio.h>;/
#include<conio.h>;
#include<ctime>; //th? vi?n h? tr? v? th?i gian th?c
#include<windows.h>

//L?y t?a ?? x c?a con tr? hi?n t?i
#define KEY_NONE
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

//L?y t?a ?? Y c?a con tr? hi?n t?i
int WhereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

//??nh con tr? hi?n t?i ??n ?i?m có t?a ?? (x,y)
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Ch?nh màu cho ch?
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


//Làm ?n tr? chu?t
void ShowCur(bool CursorVisitbillity)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1,CursorVisitbillity };
	SetConsoleCursorInfo(handle, &cursor);
}

//Tr? v? mã phím ng??i dùng b?m
int intputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}
		return key;
	}
}