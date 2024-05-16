#include "Console.h"


void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void SetConsoleWindow(int width, int height)
{
	HWND consoleWindow = GetConsoleWindow();
	RECT rectWindow;
	GetWindowRect(consoleWindow, &rectWindow);
	MoveWindow(consoleWindow, rectWindow.left, rectWindow.top, width, height, TRUE);
}

void MoveWindow(int posX, int posY)
{
	HWND hWnd = GetConsoleWindow();
	RECT rectClient;
	GetClientRect(hWnd, &rectClient);
	MoveWindow(hWnd, posX, posY, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void MoveCenter()
{
	HWND hWnd = GetConsoleWindow();
	RECT rectClient, rectWindow;
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posX, posY;
	posX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2;
	posY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	MoveWindow(hWnd, posX, posY, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void HideCursor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void CloseConsole()
{
	HWND hWndConsole = GetConsoleWindow();
	if (hWndConsole != NULL) {
		SendMessage(hWndConsole, WM_CLOSE, 0, 0);
	}
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetCellSize(int x, int y)
{
	CONSOLE_FONT_INFOEX cf = { 0 };
	cf.cbSize = sizeof cf;
	cf.dwFontSize.X = x;
	cf.dwFontSize.Y = y;
	wcscpy_s(cf.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}

void TextColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	WORD wAttributes = (csbi.wAttributes & 0xFFF0) | (color & 0x000F);
	SetConsoleTextAttribute(hConsole, wAttributes);
}

void BackgroundColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	WORD wAttributes = (csbi.wAttributes & 0xFF0F) | ((color << 4) & 0x00F0);
	SetConsoleTextAttribute(hConsole, wAttributes);
}

