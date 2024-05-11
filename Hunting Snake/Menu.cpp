#include "Menu.h"


vector<string> selections = { "Start", "Rank", "About", "Instruction", "Setting", "Exit" };

void Rank()
{

}

void About()
{

}

void Instruction()
{

}

void Setting()
{

}

bool Menu()
{
	system("color F0");
	system("cls");
	HideCursor();
	int cursorPos = 0;
	bool quit = false;
	/*________ ________               __                __     __                               __
		 /        |             / /|              /  |   / /|                             /  |
		 █████████/  ___     __ ██/   __          ██ |   ██ | __    __  _______   _______ ██/  _______     ______
		 ██ |       /  |    / /\/  | / /|         ██     ██ |/  |  / /|/       \ /      /|/ /|/       \   /      \
		 ██ |_____  ██ |    ██ /██ | ██ |         ██ |   ██ |██ |  ██ |███████  |███████/ ██ |███████  | /██████/ \
		 ████████/| ██ |   ██ / ██ | ██ |         █████████ |██ |  ██ |██ |  ██ |  ██ |   ██ |██ |  ██ | ██    ██ |
		 ██ |        ██ | ██ /  ██ | ██ |_____    ██ |   ██ |██ \__██ |██ |  ██ |  ██ |   ██ |██ |  ██ |██     ██ |
		 ██ |______  ██/ ██ /   ██ | ██       |   ██ |   ██ |██    ██ |██ |  ██ |  ██ |   ██ |██ |  ██ | ██    ██ |
		 █████████/   ███ /     ██ / ████████/    ██/    ██/  ██████ / ██/   ██/   ██/    ██ /██/   ██/   ███████ |
		   ______                        __                                                                ____██ |
		  /      \                      /  |                                                              /    ██ |
		  /██████  | _______    ______  ██ |   __   ______                                                ██████ /
		  ██ \__██/ /       \  /      \ ██ |  /  | /      \
		  ██      \ ███████  | ██████  |██ |_/██/ /██████  |
		   ██████  |██ |  ██ | /    ██ |██   ██/  ██    ██ |
		  /  \__██ |██ |  ██ |/███████ |██████   ████████/
		  ██    ██/ ██ |  ██ |██    ██ |██ | ██  |██_______ |
		   ██████ / ██ /  ██ / ███████ /██ /  ██ / ███████ /*/

	TextColor(MainColor);
	int x = 10, y = 1;
	GotoXY(x - 8, y++);
	cout << "         ________               __                __     __                               __";
	GotoXY(x, y++);
	cout << "/        |             / /|              /  |   / /|                             /  |";
	GotoXY(x, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB/  ___     __ \xDB\xDB/   __          \xDB\xDB |   \xDB\xDB | __    __  _______   _______ \xDB\xDB/  _______     ______";
	GotoXY(x, y++);
	cout << "\xDB\xDB |       /  |    / / \/  | / /|         \xDB\xDB     \xDB\xDB |/  |  / /|/       \  /      /|/ /|/       \    /      /\ ";
	GotoXY(x, y++);
	cout << "\xDB\xDB |_____  \xDB\xDB |    \xDB\xDB |\xDB\xDB | \xDB\xDB |         \xDB\xDB |   \xDB\xDB |\xDB\xDB |  \xDB\xDB |\xDB\xDB\xDB\xDB\xDB\xDB\xDB  |\xDB\xDB\xDB\xDB\xDB\xDB\xDB/ \xDB\xDB |\xDB\xDB\xDB\xDB\xDB\xDB\xDB  | /\xDB\xDB\xDB\xDB\xDB\xDB/ \ ";
	GotoXY(x, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB/| \xDB\xDB |   \xDB\xDB / \xDB\xDB | \xDB\xDB |         \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB |\xDB\xDB |  \xDB\xDB |\xDB\xDB |  \xDB\xDB |  \xDB\xDB |   \xDB\xDB |\xDB\xDB |  \xDB\xDB | \xDB\xDB    \xDB\xDB |";
	GotoXY(x, y++);
	cout << "\xDB\xDB |        \xDB\xDB | \xDB\xDB /  \xDB\xDB | \xDB\xDB |_____    \xDB\xDB |   \xDB\xDB |\xDB\xDB \__ \xDB\xDB |\xDB\xDB |  \xDB\xDB |  \xDB\xDB |   \xDB\xDB |\xDB\xDB |  \xDB\xDB |\xDB\xDB     \xDB\xDB |";
	GotoXY(x, y++);
	cout << "\xDB\xDB |______  \xDB\xDB/ \xDB\xDB /   \xDB\xDB | \xDB\xDB       |   \xDB\xDB |   \xDB\xDB |\xDB\xDB    \xDB\xDB |\xDB\xDB |  \xDB\xDB |  \xDB\xDB |   \xDB\xDB |\xDB\xDB |  \xDB\xDB | \xDB\xDB    \xDB\xDB |";
	GotoXY(x, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB/   \xDB\xDB\xDB /     \xDB\xDB / \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB/    \xDB\xDB/    \xDB\xDB/  \xDB\xDB\xDB\xDB\xDB\xDB / \xDB\xDB/   \xDB\xDB/   \xDB\xDB/    \xDB\xDB /\xDB\xDB/   \xDB\xDB/   \xDB\xDB\xDB\xDB\xDB\xDB\xDB |";
	GotoXY(x, y++);
	cout << "  ______                       __                                                                 ____\xDB\xDB |";
	GotoXY(x, y++);
	cout << " /      \                      /  |                                                               /    \xDB\xDB |";
	GotoXY(x, y++);
	cout << "/\xDB\xDB\xDB\xDB\xDB\xDB  | _______    ______  \xDB\xDB |   __   ______                                                 \xDB\xDB\xDB\xDB\xDB\xDB /";
	GotoXY(x, y++);
	cout << "\xDB\xDB \\__\xDB\xDB/ /       \\  /      \\ \xDB\xDB |  /  | /      \\";
	GotoXY(x, y++);
	cout << "\xDB\xDB      \\ \xDB\xDB\xDB\xDB\xDB\xDB\xDB  | \xDB\xDB\xDB\xDB\xDB\xDB  |\xDB\xDB |_/\xDB\xDB/ /\xDB\xDB\xDB\xDB\xDB\xDB  |";
	GotoXY(x + 1, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB  |\xDB\xDB |  \xDB\xDB | /    \xDB\xDB |\xDB\xDB   \xDB\xDB/  \xDB\xDB    \xDB\xDB |";
	GotoXY(x, y++);
	cout << "/  \\__\xDB\xDB |\xDB\xDB |  \xDB\xDB |/\xDB\xDB\xDB\xDB\xDB\xDB\xDB |\xDB\xDB\xDB\xDB\xDB\xDB  \ \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB/ ";
	GotoXY(x, y++);
	cout << "\xDB\xDB    \xDB\xDB/ \xDB\xDB |  \xDB\xDB |\xDB\xDB    \xDB\xDB |\xDB\xDB | \xDB\xDB  |\xDB\xDB_______ |";
	GotoXY(x + 1, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB / \xDB\xDB /  \xDB\xDB / \xDB\xDB\xDB\xDB\xDB\xDB\xDB /\xDB\xDB /  \xDB\xDB / \xDB\xDB\xDB\xDB\xDB\xDB\xDB /";

	do {
		TextColor(DefaultColor);
		for (int i = 0; i < 6; i++) {
			if (i == cursorPos)
				TextColor(Pink);
			else
				TextColor(Grey);
			GotoXY(x, y + i);
			cout << selections[i];
		}
		TextColor(0x07);
		char input = tolower(_getch());
		switch (input) {
		case 'w':
			if (cursorPos > 0)
				cursorPos--;
			break;
		case 's':
			if (cursorPos < 5)
				cursorPos++;
			break;
		case '\r':
			switch (cursorPos) {
			case 0:
				return true;
				break;
			case 1:
				Rank();
				break;
			case 2:
				About();
				break;
			case 3:
				Instruction();
				break;
			case 4:
				Setting();
				break;
			case 5:
				quit = true;
				TextColor(White);
				break;
			}
		}
	} while (!quit);
	return false;
}