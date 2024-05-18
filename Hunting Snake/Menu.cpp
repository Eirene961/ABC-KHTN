#include "Menu.h"
#include <thread>
#include <iostream>
using namespace std;


vector<string> selections = { "Start", "Continue", "Rank" , "About", "Setting", "Exit"};

void Continue()
{

}

void Rank()
{

}

void About()
{
	/*PlaySound(TEXT("C:\\Users\\AnPC\\Downloads\\nhacnen.wav"), NULL, SND_FILENAME);*/
	system("color F0");
	system("cls");
	HideCursor();
	int x = 10, y = 1;
	GotoXY(x, y++);
	cout << " _    _  ___  __    __  __  __  __  ___    ____  __      __  _  _  ___      __   __   __  __  ___ ";
	GotoXY(x, y++);
	cout << "( \\/\\/ )(  _)(  )  / _)/  \\(  \\/  )(  _)  (_  _)/  \\    /  \\( )( )(  ,)    / _) (  ) (  \\/  )(  _)";
	GotoXY(x, y++);
	cout << " \\    /  ) _) )(__( (_( () ))    (  ) _)    )( ( () )  ( () ))()(  )  \\   ( (/\\ /__\\  )    (  ) _)";
	GotoXY(x, y++);
	cout << "  \\/\\/  (___)(____)\\__)\\__/(_/\\/\\_)(___)   (__) \\__/    \\__/ \\__/ (_)\\_)   \\__/(_)(_)(_/\\/\\_)(___)";
	GotoXY(x, y++);
	cout << " ___  _  _  __    ___ ";
	GotoXY(x, y++);
	cout << "(  ,)( )( )(  )  (  _)";
	GotoXY(x, y++);
	cout << " )  \\ )()(  )(__  ) _)";
	GotoXY(x, y++);
	cout << "+ OUR MEMBERS: ";
	GotoXY(x, y++);
	cout << "- 1. LAY KHANH AN          MSSV: 23120204.";
	GotoXY(x, y++);
	cout << "- 2. NGO DA BAU            MSSV: .";
	GotoXY(x, y++);
	cout << "- 3. NGUYEN HOANG THE ANH  MSSV: .";
	GotoXY(x, y++);
	cout << "- 4. VO HOANG NHAT ANH     MSSV: .";
	GotoXY(x, y++);
	cout << "- 5. DAI                   MSSV: . ";
	GotoXY(x, y++);
	cout << "- PRESS THE 'A', 'W', 'S', 'D' KEYS OR 'ARROW_LEFT', 'ARROW_UP', 'ARROW_DOWN', 'ARROW_RIGHT' KEYS";
	GotoXY(x, y++);
	cout << "  TO MOVE THE SNAKE LEFT, UP, DOWN AND RIGHT.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'T' TO LOAD THE FILE.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'T' TO LOAD THE FILE.";
	GotoXY(x, y++);
	cout << " ___  ___   ___  ___  ___     __   _  _  _  _    _ _   ___  _  _    ____  __       ";
	GotoXY(x, y++);
	cout << "(  ,\\(  ,) (  _)/ __)/ __)   (  ) ( \\( )( \\/ )  ( ) ) (  _)( \\/ )  (_  _)/  \\      ";
	GotoXY(x, y++);
	cout << " ) _/ )  \\  ) _)\\__ \\\\__ \\   /__\\  )  (  \\  /    )  \\  ) _) \\  /     )( ( () )     ";
	GotoXY(x, y++);
	cout << "(_)  (_)\\_)(___)(___/(___/  (_)(_)(_)\\_)(__/    (_)\\_)(___)(__/     (__) \\__/      ";
	GotoXY(x, y++);
	cout << " ___   ___  ____  _  _  ___   _  _    ____  _  _  ___    __  __  ___  __  __  _  _ ";
	GotoXY(x, y++);
	cout << "(  ,) (  _)(_  _)( )( )(  ,) ( \\( )  (_  _)( )( )(  _)  (  \\/  )(  _)(  \\/  )( )( )";
	GotoXY(x, y++);
	cout << " )  \\  ) _)  )(   )()(  )  \\  )  (     )(   )__(  ) _)   )    (  ) _) )    (  )()( ";
	GotoXY(x, y++);
	cout << "(_)\\_)(___) (__)  \\__/ (_)\\_)(_)\\_)   (__) (_)(_)(___)  (_/\\/\\_)(___)(_/\\/\\_) \\__/ ";
	char key = _getch();

	if (key)
	{
		system("cls");
		Menu();
		return;
	}
}
void Setting()
{
	system("color F0");
	system("cls");
	HideCursor();
	int x = 10, y = 1;
	GotoXY(x, y++);
	cout << "  __  __  _  _  ____  __  _  _  _  _  ___    ____  _  _  ___     __   __   __  __  ___  ___ ";
	GotoXY(x, y++);
	cout << " / _)/  \\( \\( )(_  _)(  )( \\( )( )( )(  _)  (_  _)( )( )(  _)   / _) (  ) (  \\/  )(  _)(__ )";
	GotoXY(x, y++);
	cout << "( (_( () ))  (   )(   )(  )  (  )()(  ) _)    )(   )__(  ) _)  ( (/\\ /__\\  )    (  ) _) (_/ ";
	GotoXY(x, y++);
	cout << " \\__)\\__/(_)\\_) (__) (__)(_)\\_) \\__/ (___)   (__) (_)(_)(___)   \\__/(_)(_)(_/\\/\\_)(___) (_) ";
	GotoXY(x, y++);
	cout << "--------------------------------------------------------------------------------------------\n";
	GotoXY(x, y++);
	cout << " _    _  ___  __    __  __  __  __  ___    ____  __      __  _  _  ___      __   __   __  __  ___ ";
	GotoXY(x, y++);
	cout << "( \\/\\/ )(  _)(  )  / _)/  \\(  \\/  )(  _)  (_  _)/  \\    /  \\( )( )(  ,)    / _) (  ) (  \\/  )(  _)";
	GotoXY(x, y++);
	cout << " \\    /  ) _) )(__( (_( () ))    (  ) _)    )( ( () )  ( () ))()(  )  \\   ( (/\\ /__\\  )    (  ) _)";
	GotoXY(x, y++);
	cout << "  \\/\\/  (___)(____)\\__)\\__/(_/\\/\\_)(___)   (__) \\__/    \\__/ \\__/ (_)\\_)   \\__/(_)(_)(_/\\/\\_)(___)";
	GotoXY(x, y++);
	cout << " ___  _  _  __    ___ ";
	GotoXY(x, y++);
	cout << "(  ,)( )( )(  )  (  _)";
	GotoXY(x, y++);
	cout << " )  \\ )()(  )(__  ) _)";
	GotoXY(x, y++);
	cout << "(_)\\_)\\__/ (____)(___)";
	GotoXY(x, y++);
	cout << "- YOU HAVE TO PASS 3 LEVELS TO COMPLETE THE GAME.";
	GotoXY(x, y++);
	cout << "- SNAKE RUNS FASTER FOR EACH LEVEL PASSED.";
	GotoXY(x, y++);
	cout << "- TO PASS THE LEVEL, SNAKE NEED TO EAT 8, 16, 24 FOOD.";
	GotoXY(x, y++);
	cout << "- THE SNAKE REMAINS THE LENGTH OF 6 WHEN PASSED THE LEVEL.";
	GotoXY(x, y++);
	cout << " _  _  __  _    _    ____  __     ___  __     __   _  _  ___ ";
	GotoXY(x, y++);
	cout << "( )( )/  \\( \\/\\/ )  (_  _)/  \\   (  ,\\(  )   (  ) ( \\/ )(__ )";
	GotoXY(x, y++);
	cout << " )__(( () )\\    /     )( ( () )   ) _/ )(__  /__\\  \\  /  (_/ ";
	GotoXY(x, y++);
	cout << "(_)(_)\\__/  \\/\\/     (__) \\__/   (_)  (____)(_)(_)(__/   (_) ";
	GotoXY(x, y++);
	cout << "- PRESS THE 'A', 'W', 'S', 'D' KEYS OR 'ARROW_LEFT', 'ARROW_UP', 'ARROW_DOWN', 'ARROW_RIGHT' KEYS";
	GotoXY(x, y++);
	cout << "  TO MOVE THE SNAKE LEFT, UP, DOWN AND RIGHT.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'T' TO LOAD THE FILE.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'T' TO LOAD THE FILE.";
	GotoXY(x, y++);
	cout << " ___  ___   ___  ___  ___     __   _  _  _  _    _ _   ___  _  _    ____  __       ";
	GotoXY(x, y++);
	cout << "(  ,\\(  ,) (  _)/ __)/ __)   (  ) ( \\( )( \\/ )  ( ) ) (  _)( \\/ )  (_  _)/  \\      ";
	GotoXY(x, y++);
	cout << " ) _/ )  \\  ) _)\\__ \\\\__ \\   /__\\  )  (  \\  /    )  \\  ) _) \\  /     )( ( () )     ";
	GotoXY(x, y++);
	cout << "(_)  (_)\\_)(___)(___/(___/  (_)(_)(_)\\_)(__/    (_)\\_)(___)(__/     (__) \\__/      ";
	GotoXY(x, y++);
	cout << " ___   ___  ____  _  _  ___   _  _    ____  _  _  ___    __  __  ___  __  __  _  _ ";
	GotoXY(x, y++);
	cout << "(  ,) (  _)(_  _)( )( )(  ,) ( \\( )  (_  _)( )( )(  _)  (  \\/  )(  _)(  \\/  )( )( )";
	GotoXY(x, y++);
	cout << " )  \\  ) _)  )(   )()(  )  \\  )  (     )(   )__(  ) _)   )    (  ) _) )    (  )()( ";
	GotoXY(x, y++);
	cout << "(_)\\_)(___) (__)  \\__/ (_)\\_)(_)\\_)   (__) (_)(_)(___)  (_/\\/\\_)(___)(_/\\/\\_) \\__/ ";
	char key = _getch();

	if (key)
	{
		system("cls");
		Menu();
		return;
	}
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
		for (int i = 0; i < selections.size(); i++) {
			if (i == cursorPos)
				TextColor(Pink);
			else
				TextColor(Grey);
			GotoXY(x+45, y + 10 + i);
			cout << selections[i];
		}
		TextColor(0x07);
		char input = tolower(_getch());
		if (input) { PlaySound(TEXT("C:\\Users\\AnPC\\Downloads\\tang.wav"), NULL, SND_FILENAME); }
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
				Continue();
				break;
			case 2:
				Rank();
				break;
			case 3:
				About();
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