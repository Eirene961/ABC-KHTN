#include <iostream>
#include<conio.h>
#include "console.h"
#include<ctime>
#define BACKGROUNDCOLOR 124
#define TEXTCOLOR 121
using namespace std;
typedef char str[31];
str nut[5] = { "Start new game", "Instruction", "Introduction", "Continue", "Exit" };

enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, BACK };

TRANGTHAI key(int z) {
	if (z == 224) {
		char c;
		c = _getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return RIGHT;
		if (c == 75)
			return LEFT;
	}
	else if (z == 13)
		return ENTER;

	return BACK; // default return value when z is neither 224 nor 13
}



int menu(str nut[5], int n) {
	int tt = 0;
	int* mau = new int[n];
	for (int i = 0; i > n; i++) {
		mau[i] = TEXTCOLOR;
		mau[0] = BACKGROUNDCOLOR;
	}
	while (1) {
		clrscr();
		int x_new = 35;
		int x_chu = 0;
		int x = 68;
		int y = 10, y_dif = 0;

		/*________ ________               __                __     __                               __
		 /        |             / /|              /  |   / /|                             /  |
		 $$$$$$$$$/  ___     __ $$/   __          $$ |   $$ | __    __  _______   _______ $$/  _______     ______
		 $$ |       /  |    / /\/  | / /|         $$     $$ |/  |  / /|/       \ /      /|/ /|/       \   /      \
		 $$ |_____  $$ |    $$ /$$ | $$ |         $$ |   $$ |$$ |  $$ |$$$$$$$  |$$$$$$$/ $$ |$$$$$$$  | /$$$$$$/ \
		 $$$$$$$$/| $$ |   $$ / $$ | $$ |         $$$$$$$$$ |$$ |  $$ |$$ |  $$ |  $$ |   $$ |$$ |  $$ | $$    $$ |
		 $$ |        $$ | $$ /  $$ | $$ |_____    $$ |   $$ |$$ \__$$ |$$ |  $$ |  $$ |   $$ |$$ |  $$ |$$     $$ |
		 $$ |______  $$/ $$ /   $$ | $$       |   $$ |   $$ |$$    $$ |$$ |  $$ |  $$ |   $$ |$$ |  $$ | $$    $$ |
		 $$$$$$$$$/   $$$ /     $$ / $$$$$$$$/    $$/    $$/  $$$$$$ / $$/   $$/   $$/    $$ /$$/   $$/   $$$$$$$ |
		   ______                        __                                                                ____$$ |
		  /      \                      /  |                                                              /    $$ |
		  /$$$$$$  | _______    ______  $$ |   __   ______                                                $$$$$$ /
		  $$ \__$$/ /       \  /      \ $$ |  /  | /      \
		  $$      \ $$$$$$$  | $$$$$$  |$$ |_/$$/ /$$$$$$  |
		   $$$$$$  |$$ |  $$ | /    $$ |$$   $$/  $$    $$ |
		  /  \__$$ |$$ |  $$ |/$$$$$$$ |$$$$$$   $$$$$$$$/
		  $$    $$/ $$ |  $$ |$$    $$ |$$ | $$  |$$_______ |
		   $$$$$$ / $$ /  $$ / $$$$$$$ /$$ /  $$ / $$$$$$$ /*/

		y = 1;
		int x_tua_game = 10;
		gotoXY(x_tua_game - 8, y++);
		cout << "         ________               __                __     __                               __";
		gotoXY(x_tua_game, y++);
		cout << "/        |             / /|              /  |   / /|                             /  |";
		gotoXY(x_tua_game, y++);
		cout << "$$$$$$$$$/  ___     __ $$/   __          $$ |   $$ | __    __  _______   _______ $$/  _______     ______";
		gotoXY(x_tua_game, y++);
		cout << "$$ |       /  |    / / \/  | / /|         $$     $$ |/  |  / /|/       \  /      /|/ /|/       \    /      /\ ";
		gotoXY(x_tua_game, y++);
		cout << "$$ |_____  $$ |    $$ |$$ | $$ |         $$ |   $$ |$$ |  $$ |$$$$$$$  |$$$$$$$/ $$ |$$$$$$$  | /$$$$$$/ \ ";
		gotoXY(x_tua_game, y++);
		cout << "$$$$$$$$/| $$ |   $$ / $$ | $$ |         $$$$$$$$$ |$$ |  $$ |$$ |  $$ |  $$ |   $$ |$$ |  $$ | $$    $$ |";
		gotoXY(x_tua_game, y++);
		cout << "$$ |        $$ | $$ /  $$ | $$ |_____    $$ |   $$ |$$ \__ $$ |$$ |  $$ |  $$ |   $$ |$$ |  $$ |$$     $$ |";
		gotoXY(x_tua_game, y++);
		cout << "$$ |______  $$/ $$ /   $$ | $$       |   $$ |   $$ |$$    $$ |$$ |  $$ |  $$ |   $$ |$$ |  $$ | $$    $$ |";
		gotoXY(x_tua_game, y++);
		cout << "$$$$$$$$$/   $$$ /     $$ / $$$$$$$$/    $$/    $$/  $$$$$$ / $$/   $$/   $$/    $$ /$$/   $$/   $$$$$$$ |";
		gotoXY(x_tua_game, y++);
		cout << "  ______                       __                                                                 ____$$ |";
		gotoXY(x_tua_game, y++);
		cout << " /      \                      /  |                                                               /    $$ |";
		gotoXY(x_tua_game, y++);
		cout << "/$$$$$$  | _______    ______  $$ |   __   ______                                                 $$$$$$ /";
		gotoXY(x_tua_game, y++);
		cout << "$$ \\__$$/ /       \\  /      \\ $$ |  /  | /      \\";
		gotoXY(x_tua_game, y++);
		cout << "$$      \\ $$$$$$$  | $$$$$$  |$$ |_/$$/ /$$$$$$  |";
		gotoXY(x_tua_game + 1, y++);
		cout << "$$$$$$  |$$ |  $$ | /    $$ |$$   $$/  $$    $$ |";
		gotoXY(x_tua_game, y++);
		cout << "/  \\__$$ |$$ |  $$ |/$$$$$$$ |$$$$$$  \ $$$$$$$$/ ";
		gotoXY(x_tua_game, y++);
		cout << "$$    $$/ $$ |  $$ |$$    $$ |$$ | $$  |$$_______ |";
		gotoXY(x_tua_game + 1, y++);
		cout << "$$$$$$ / $$ /  $$ / $$$$$$$ /$$ /  $$ / $$$$$$$ /";
		gotoXY(x_tua_game + 10, y++);
		cout << "by FiveMember";
		for (int i = 0; i < n; i++) {
			TextColor(mau[i]);
			gotoXY(55, 20 + 2 * i);
			cout << "   |   " << nut[i] << endl;
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
			if (tt == 0) {
				tt = n - 1;
			}
			else tt--;
			break;

		case DOWN:
			if (tt == n - 1) {
				tt = 0;
			}
			else tt++;
			break;

		case ENTER:
			return tt;

		default:
			for (int i = 0; i < n; i++) {
				mau[i] = TEXTCOLOR;
				mau[tt] = BACKGROUNDCOLOR;
			}
			break;
		}

	}
}



int main() {
	srand(time(NULL));
	system("color 70");
	menu(nut, 5);
	system("pause");
	return 0;
}