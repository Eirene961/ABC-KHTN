#include "Menu.h"


bool cmp(Save a, Save b)
{
	if (a.score != b.score)
		return a.score > b.score;
	return a.name < b.name;
}


int Continue()
{
	system("cls");

	int x = 16, y = 0;
	TextColor(Red);
	GotoXY(x, y++);
	cout << " __                                   __        _________          ";
	GotoXY(x, y++);
	cout << "/ /|                                 / /|      \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \\        ";
	GotoXY(x, y++);
	cout << "\xDB\xDB |         ______     ______       \xDB\xDB |     \xDB\xDB  ____\xDB\xDB\xDB |   ______   ______________     ______";
	GotoXY(x, y++);
	cout << "\xDB\xDB |        /     /\\   /     /\\   ___\xDB\xDB |    \xDB\xDB  /     \xDB\xDB/   /     /\\ /             /\\   /     /\\       ";
	GotoXY(x, y++);
	cout << "\xDB\xDB |       /\xDB\xDB\xDB\xDB\xDB\xDB  \\  \xDB\xDB\xDB\xDB\xDB\xDB  | /   \xDB\xDB |   \xDB\xDB  |     ______ \xDB\xDB\xDB\xDB\xDB\xDB  |\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  \\ /\xDB\xDB\xDB\xDB\xDB\xDB  |";
	GotoXY(x, y++);
	cout << "\xDB\xDB |      /\xDB\xDB /  \xDB\xDB  \\ /    \xDB\xDB |/\xDB\xDB\xDB\xDB\xDB\xDB |   \xDB\xDB  |    /     /|/    \xDB\xDB |\xDB\xDB |  \xDB\xDB |   \xDB\xDB | \xDB\xDB    \xDB\xDB |";
	GotoXY(x, y++);
	cout << "\xDB\xDB |______\xDB\xDB |    \xDB\xDB |/\xDB\xDB\xDB\xDB\xDB\xDB\xDB |\xDB\xDB   \xDB\xDB |    \xDB\xDB  \\___\xDB\xDB\xDB\xDB\xDB\xDB//\xDB\xDB\xDB\xDB\xDB\xDB\xDB |\xDB\xDB |  \xDB\xDB |   \xDB\xDB |\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB_/";
	GotoXY(x, y++);
	cout << "\xDB\xDB/      /|\xDB\xDB \\  \xDB\xDB / \xDB\xDB    \xDB\xDB |\xDB\xDB   \xDB\xDB |     \xDB\xDB/      \xDB\xDB | \xDB\xDB    \xDB\xDB |\xDB\xDB |  \xDB\xDB |   \xDB\xDB | \xDB\xDB_______|";
	GotoXY(x, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB/  \xDB\xDB\xDB\xDB\xDB\xDB /   \xDB\xDB\xDB\xDB\xDB\xDB\xDB/  \xDB\xDB\xDB\xDB\xDB\xDB/       \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB /   \xDB\xDB\xDB\xDB\xDB\xDB\xDB /\xDB\xDB/   \xDB\xDB/    \xDB\xDB/   \xDB\xDB\xDB\xDB\xDB\xDB\xDB/";

	int width = 110;
	int height = 26;

	x = 10, y = 10;

	BackgroundColor(Yellow);
	TextColor(Grey);
	GotoXY(x, y);
	for (int i = 1; i <= width; i++) {
		if (i == 1 || i == width)
			cout << char(219);
		else
			cout << char(223);

	}
	for (int i = 1; i <= height; i++) {
		GotoXY(x, y + i);
		for (int j = 1; j <= width; j++) {
			if (j == 1 || j == width)
				cout << char(219);
			else
				cout << ' ';
		}
	}
	GotoXY(x + 1, y + height);
	for (int i = 1; i < width - 1; i++)
		cout << char(220);

	GotoXY(x + 1, y + 2);
	for (int i = 1; i < width - 1; i++) {
		cout << char(220);
	}

	GotoXY(x + 10, y + 1);
	cout << "NAME";
	GotoXY(x + 35, y + 1);
	cout << "LEVEL";
	GotoXY(x + 60, y + 1);
	cout << "SCORE";
	GotoXY(x + 90, y + 1);
	cout << "DATE";


	x += 2;
	y += 3;

	vector<Save> load;
	ifstream file("LOADGAME.txt");
	file.seekg(0, std::ios::beg);
	while (!file.eof()) {
		Save tmp;
		file >> tmp.name;
		file >> tmp.level;
		file >> tmp.score;
		file.ignore();
		getline(file, tmp.time);
		bool check = true;
		for (Save& save : load) {
			if (save.name == tmp.name) {
				save = tmp;
				check = false;
				break;
			}
		}
		if (check)
			load.push_back(tmp);
	}
	file.close();
	load.pop_back();

	bool quit = false;
	int cursorPos = 0;
	do {
		for (int i = 0; i < min(load.size(), 23); i++) {
			if (i == cursorPos)
				TextColor(Pink);
			else
				TextColor(Grey);
			GotoXY(x, y + i);
			cout << i + 1 << ". " << load[i].name;
			GotoXY(x + 35, y + i);
			cout << load[i].level;
			GotoXY(x + 59, y + i);
			cout << load[i].score;
			GotoXY(x + 77, y + i);
			cout << load[i].time;
		}
		TextColor(Grey);
		char input = tolower(_getch());
		switch (input) {
		case 'w':
			if (cursorPos > 0)
				cursorPos--;
			break;
		case 's':
			if (cursorPos < min(load.size(), 23) - 1)
				cursorPos++;
			break;
		case '\x1B':
			quit = true;
			break;
		case '\r':
			return cursorPos;
			break;
		}
	} while (!quit);
	return -1;
}

void Rank()
{
	system("cls");
	TextColor(Red);

	int width = 110;
	int height = 26;

	int x = 45, y = 0;


	GotoXY(x, y++);
	cout << " _______                        __ ";
	GotoXY(x, y++);
	cout << "/      / \\                     / /| ";
	GotoXY(x, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  \\  ______   _______  \xDB\xDB |   __    ";
	GotoXY(x, y++);
	cout << "\xDB\xDB \\__ \xDB\xDB | /     /\\ /      /\\ \xDB\xDB |  / /|";
	GotoXY(x, y++);
	cout << "\xDB\xDB    \xDB\xDB /  \xDB\xDB\xDB\xDB\xDB\xDB  |\xDB\xDB\xDB\xDB\xDB\xDB\xDB  |\xDB\xDB |_/\xDB\xDB/ ";
	GotoXY(x, y++);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB |   /    \xDB\xDB |\xDB\xDB |  \xDB\xDB |\xDB\xDB/  \xDB\xDB/  ";
	GotoXY(x, y++);
	cout << "\xDB\xDB \\__\xDB\xDB \\ /\xDB\xDB\xDB\xDB\xDB\xDB\xDB |\xDB\xDB |  \xDB\xDB |\xDB\xDB\xDB\xDB\xDB\xDB \\";
	GotoXY(x, y++);
	cout << "\xDB\xDB |   \xDB\xDB \\\xDB\xDB    \xDB\xDB |\xDB\xDB |  \xDB\xDB |\xDB\xDB | \xDB\xDB \\";
	GotoXY(x, y++);
	cout << "\xDB\xDB/     \xDB\xDB/ \xDB\xDB\xDB\xDB\xDB\xDB\xDB /\xDB\xDB/   \xDB\xDB/ \xDB\xDB/   \xDB\xDB/ ";


	x -= 35;
	y++;
	BackgroundColor(Yellow);
	TextColor(Grey);
	GotoXY(x, y);
	for (int i = 1; i <= width; i++) {
		if (i == 1 || i == width)
			cout << char(219);
		else
			cout << char(223);

	}
	for (int i = 1; i <= height; i++) {
		GotoXY(x, y + i);
		for (int j = 1; j <= width; j++) {
			if (j == 1 || j == width)
				cout << char(219);
			else
				cout << ' ';
		}
	}
	GotoXY(x + 1, y + height);
	for (int i = 1; i < width - 1; i++)
		cout << char(220);
	
	GotoXY(x + 1, y + 2);
	for (int i = 1; i < width - 1; i++) {
		cout << char(220);
	}

	GotoXY(x + 10, y + 1);
	cout << "NAME";
	GotoXY(x + 35, y + 1);
	cout << "LEVEL";
	GotoXY(x + 60, y + 1);
	cout << "SCORE";
	GotoXY(x + 90, y + 1);
	cout << "DATE";


	x += 2;
	y += 3;

	vector<Save> save;
	ifstream file("RANK.txt");
	file.seekg(0, std::ios::beg);
	while (!file.eof()) {
		Save tmp;
		file >> tmp.name;
		file >> tmp.level;
		file >> tmp.score;
		file.ignore();
		getline(file, tmp.time);
		bool check = true;
		for (Save& rank : save) {
			if (rank.name == tmp.name) {
				rank = tmp;
				check = false;
				break;
			}
		}
		if (check)
			save.push_back(tmp);
	}

	file.close();
	save.pop_back();
	sort(save.begin(), save.end(), cmp);
	for (int i = 0; i < min(save.size(), 23); i++) {
		GotoXY(x, y + i);
		cout << i + 1 << ". " << save[i].name;
		GotoXY(x + 35, y + i);
		cout << save[i].level;
		GotoXY(x + 59, y + i);
		cout << save[i].score;
		GotoXY(x + 77, y + i);
		cout << save[i].time;
	}
	while (true) {
		char input = tolower(_getch());
		if (input == '\x1B')
			break;
	}
}

void About()
{
	system("color F0");
	system("cls");
	HideCursor();

	int width = 110;
	int height = 34;

	int x = 10, y = 2;

	
	TextColor(Grey);
	BackgroundColor(Yellow);
	GotoXY(x, y);
	for (int i = 1; i <= width; i++) {
		if (i == 1 || i == width)
			cout << char(219);
		else
			cout << char(223);

	}
	for (int i = 1; i <= height; i++) {
		GotoXY(x, y + i);
		for (int j = 1; j <= width; j++) {
			if (j == 1 || j == width)
				cout << char(219);
			else
				cout << ' ';
		}
	}
	GotoXY(x + 1, y + height);
	for (int i = 1; i < width - 1; i++)
		cout << char(220);
	GotoXY(x + 1, y + 6);
	for (int i = 1; i < width - 1; i++) {
		cout << char(220);
	}

	x += 5;
	y++;
	GotoXY(x, y++);
	cout << " _    _  ___  __    __  __  __  __  ___    ____  __      __  _  _  ___      __   __   __  __  ___ ";
	GotoXY(x, y++);
	cout << "( \\/\\/ )(  _)(  )  / _)/  \\(  \\/  )(  _)  (_  _)/  \\    /  \\( )( )(  ,)    / _) (  ) (  \\/  )(  _)";
	GotoXY(x, y++);
	cout << " \\    /  ) _) )(__( (_( () ))    (  ) _)    )( ( () )  ( () ))()(  )  \\   ( (/\\ /__\\  )    (  ) _)";
	GotoXY(x, y++);
	cout << "  \\/\\/  (___)(____)\\__)\\__/(_/\\/\\_)(___)   (__) \\__/    \\__/ \\__/ (_)\\_)   \\__/(_)(_)(_/\\/\\_)(___)";
	
	y += 3;
	GotoXY(x, y++);
	cout << "+ OUR MEMBERS: "; 
	GotoXY(x, y++);
	cout << "- 1. NGO DA BAU            MSSV: 23120215 (LEADER).";
	GotoXY(x, y++);
	cout << "- 2. LAY KHANH AN          MSSV: 23120204.";
	GotoXY(x, y++);
	cout << "- 3. NGUYEN HOANG THE ANH  MSSV: 23120210.";
	GotoXY(x, y++);
	cout << "- 4. VO HOANG NHAT ANH     MSSV: 23120212.";
	GotoXY(x, y++);
	cout << "- 5. NGUYEN NGOC DAI       MSSV: 23120226. ";
	y++;
	GotoXY(x, y++);
	cout << "+ INSTRUCTION:";
	GotoXY(x, y++);
	cout << "- PRESS THE 'W' KEY TO MOVE UP.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'S' KEY TO MOVE DOWN.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'A' KEY TO MOVE LEFT.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'R' KEY TO MOVE RIGHT.";
	GotoXY(x, y++);
	cout << "- PRESS THE 'P' KEY TO PAUSE THE GAME.";
	GotoXY(x, y++);
	cout << "- NOTE: IF YOUR SNAKE IS IN A STUNNED STATE, THE DIRECTIONS WILL BE REVERSED!";
	GotoXY(x, y++);
	cout << "- HAVE FUN AND LUCK!";

	y += 2;
	GotoXY(x, y++);
	cout << " ___  ___   ___  ___  ___    ___  ___   __    ____  __       ";
	GotoXY(x, y++);
	cout << "(  ,\\(  ,) (  _)/ __)/ __)  (  _)/ __) / _)  (_  _)/  \\      ";
	GotoXY(x, y++);
	cout << " ) _/ )  \\  ) _)\\__ \\\\__ \\   ) _)\\__ \\( (_     )( ( () )     ";
	GotoXY(x, y++);
	cout << "(_)  (_)\\_)(___)(___/(___/  (___)(___/ \\__)   (__) \\__/      ";
	GotoXY(x, y++);
	cout << " ___   ___  ____  _  _  ___   _  _    ____  _  _  ___    __  __  ___  _  _  _  _ ";
	GotoXY(x, y++);
	cout << "(  ,) (  _)(_  _)( )( )(  ,) ( \\( )  (_  _)( )( )(  _)  (  \\/  )(  _)( \\( )( )( )";
	GotoXY(x, y++);
	cout << " )  \\  ) _)  )(   )()(  )  \\  )  (     )(   )__(  ) _)   )    (  ) _) )  (  )()( ";
	GotoXY(x, y++);
	cout << "(_)\\_)(___) (__)  \\__/ (_)\\_)(_)\\_)   (__) (_)(_)(___)  (_/\\/\\_)(___)(_)\\_) \\__/ ";


	while (true) {
		char input = tolower(_getch());
		if (input == '\x1B')
			break;
	}
}
void Setting()
{
	system("color F0");
	system("cls");
	HideCursor();

	int width = 90;
	int height = 24;
	int x = 20;
	int y = 6;
	BackgroundColor(Yellow);
	TextColor(Grey);
	GotoXY(x, y);
	for (int i = 1; i <= width; i++) {
		if (i == 1 || i == width)
			cout << char(219);
		else
			cout << char(223);

	}
	for (int i = 1; i <= height; i++) {
		GotoXY(x, y + i);
		for (int j = 1; j <= width; j++) {
			if (j == 1 || j == width)
				cout << char(219);
			else
				cout << ' ';
		}
	}
	GotoXY(x + 1, y + height);
	for (int i = 1; i < width - 1; i++)
		cout << char(220);
	GotoXY(x + 1, y + 6);
	for (int i = 1; i < width - 1; i++) {
		cout << char(220);
	}

	x += 14;
	y++;
	TextColor(Red);
	GotoXY(x, y++);
	cout << "       ___  __     __   _  _   __  __  _  _  ___  __   __  ___";
	GotoXY(x, y++);
	cout << "      (  ,\\(  )   (  ) ( \\/ ) (  \\/  )( )( )/ __)(  ) / _)(__ )";
	GotoXY(x, y++);
	cout << "       ) _/ )(__  /__\\  \\  /   )    (  )()( \\__ \\ )( ( (_  (_/ ";
	GotoXY(x, y++);
	cout << "      (_)  (____)(_)(_)(__/   (_/\\/\\_) \\__/ (___/(__) \\__) (_)";



	int cursor = 0;
	bool quit = false;
	while (!quit) {
		x = 53;
		y = 15;
		if (cursor == 0) {
			TextColor(Red);
			GotoXY(x, y++);
			cout << " _     _  _  ___  ___ ";
			GotoXY(x, y++);
			cout << "( \\   ( \\/ )(  _)/ __)";
			GotoXY(x, y++);
			cout << " ) )   \\  /  ) _)\\__ \\";
			GotoXY(x, y++);
			cout << "(_/   (__/  (___)(___/";

			y += 3;
			TextColor(Grey);
			GotoXY(x, y++);
			cout << "       _  _  __ ";
			GotoXY(x, y++);
			cout << "      ( \\( )/  \\ ";
			GotoXY(x, y++);
			cout << "       )  (( () )";
			GotoXY(x, y++);
			cout << "      (_)\\_)\\__/ ";
			GotoXY(x, y++);
		}
		else {
			TextColor(Grey);
			GotoXY(x, y++);
			cout << "       _  _  ___  ___ ";
			GotoXY(x, y++);
			cout << "      ( \\/ )(  _)/ __)";
			GotoXY(x, y++);
			cout << "       \\  /  ) _)\\__ \\";
			GotoXY(x, y++);
			cout << "      (__/  (___)(___/";

			y += 3;
			TextColor(Red);
			GotoXY(x, y++);
			cout << " _     _  _  __ ";
			GotoXY(x, y++);
			cout << "( \\   ( \\( )/  \\ ";
			GotoXY(x, y++);
			cout << " ) )   )  (( () )";
			GotoXY(x, y++);
			cout << "(_/   (_)\\_)\\__/ ";
		}
		
		char input = tolower(_getch());
		switch (input) {
		case 'w':
			if (cursor == 1)
				cursor--;
			break;
		case 's':
			if (cursor == 0)
				cursor++;
			break;
		case '\x1B':
			quit = true;
			break;
		case '\r':
			if (cursor == 0) {

			}
			else {

			}
			break;
		}
	}
}

int Menu(int cursorPos)
{
	system("color F0");
	system("cls");
	HideCursor();
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
	BackgroundColor(MainBackground);
	int x = 12, y = 1;
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
	x += 27;
	GotoXY(x, y++);
	cout << "  ______                       __                                      ____\xDB\xDB |";
	GotoXY(x, y++);
	cout << " /      \                      /  |                                    /    \xDB\xDB |";
	GotoXY(x, y++);
	cout << "/\xDB\xDB\xDB\xDB\xDB\xDB  | _______    ______  \xDB\xDB |   __   ______                      \xDB\xDB\xDB\xDB\xDB\xDB /";
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

	TextColor(MainColor);
	BackgroundColor(Yellow);
	int width = 19;
	int height = 12;
	x += 14;
	y += 3;
	GotoXY(x, y);
	for (int i = 1; i <= width; i++) {
		if (i == 1 || i == width)
			cout << char(219);
		else
			cout << char(223);

	}
	for (int i = 1; i <= height; i++) {
		GotoXY(x, y + i);
		for (int j = 1; j <= width; j++) {
			if (j == 1 || j == width)
				cout << char(219);
			else
				cout << ' ';
		}
	}
	GotoXY(x + 1, y + height);
	for (int i = 1; i < width - 1; i++)
		cout << char(220);

	GotoXY(x + 1, y + 2);
	for (int i = 1; i < width - 1; i++)
		cout << char(196);
	GotoXY(x + 1, y + 4);
	for (int i = 1; i < width - 1; i++)
		cout << char(196);
	GotoXY(x + 1, y + 6);
	for (int i = 1; i < width - 1; i++)
		cout << char(196);
	GotoXY(x + 1, y + 8);
	for (int i = 1; i < width - 1; i++)
		cout << char(196);
	GotoXY(x + 1, y + 10);
	for (int i = 1; i < width - 1; i++)
		cout << char(196);


	x += 5;
	y++;

	vector<string> selections = { "  START  ", "LOAD GAME", "  RANK   " , "  ABOUT  ", " SETTING ", "  EXIT   " };
	bool quit = false;
	do {
		TextColor(DefaultColor);
		for (int i = 0; i < selections.size(); i++) {
			GotoXY(x - 3, y + 2 * i);
			if (i == cursorPos) {
				TextColor(Pink);
				cout << "-> " << selections[i] << " <-";
			}
			else {
				TextColor(Grey);
				cout << "   " << selections[i] << "   ";
			}
		}
		TextColor(Grey);
		char input = tolower(_getch());
		int val;
		switch (input) {
		case 'w':
			if (cursorPos > 0)
				cursorPos--;
			break;
		case 's':
			if (cursorPos < selections.size() - 1)
				cursorPos++;
			break;
		case '\r':
			switch (cursorPos) {
			case 0:
				return -1;
				break;
			case 1:
				val = Continue();
				if (val == -1)
					return Menu(cursorPos);
				else
					return val;
				break;
			case 2:
				Rank();
				return Menu(cursorPos);
				break;
			case 3:
				About();
				return Menu(cursorPos);
				break;
			case 4:
				Setting();
				return Menu(cursorPos);
				break;
			case 5:
				quit = true;
				TextColor(White);
				break;
			}
		}
	} while (!quit);

	x = 38, y = 7;
	system("color F0");
	system("cls");
	HideCursor();
	
	int color = 0;
	int time = 0;

	while (time < 15) {
		y = 7;
		color %= 3;
		if (color == 0)
			TextColor(Red);
		else if (color == 1)
			TextColor(DarkGreen);
		else
			TextColor(DarkYellow);
		color++;
		time++;
		GotoXY(x, y++);
		cout << " ____  _  _   __   _  _  _ _      ___   __  ___          ";
		GotoXY(x, y++);
		cout << "(_  _)( )( ) (  ) ( \\( )( ) )    (  _) /  \\(   )         ";
		GotoXY(x, y++);
		cout << "  )(   )__(  /__\\  )  (  )  \\     ) _)( () ))  \\         ";
		GotoXY(x, y++);
		cout << " (__) (_)(_)(_)(_)(_)\\_)(_)\\_)   (_)   \\__/(_)\\_)        ";
		y++;
		GotoXY(x, y++);
		cout << " ___  __     __   _  _  __  _  _  __     ____  _  _  ___ ";
		GotoXY(x, y++);
		cout << "(  ,\\(  )   (  ) ( \\/ )(  )( \\( )/ _)   (_  _)( )( )(  _)";
		GotoXY(x, y++);
		cout << " ) _/ )(__  /__\\  \\  /  )(  )  (( (/\\     )(   )__(  ) _)";
		GotoXY(x, y++);
		cout << "(_)  (____)(_)(_)(__/  (__)(_)\\_)\\__/    (__) (_)(_)(___)";
		y++;
		GotoXY(x, y++);
		cout << "  __   __   __  __  ___                                 ";
		GotoXY(x, y++);
		cout << " / _) (  ) (  \\/  )(  _)                                ";
		GotoXY(x, y++);
		cout << "( (/\\ /__\\  )    (  ) _)                                ";
		GotoXY(x, y++);
		cout << " \\__/(_)(_)(_/\\/\\_)(___)                                ";
		Sleep(200);
	}

	TextColor(White);
	return -2;
}