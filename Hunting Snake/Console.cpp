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