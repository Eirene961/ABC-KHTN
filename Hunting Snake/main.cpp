#include "Game.h"


int main() {
    system("color F0");

    ofstream file("Rank.txt", ios::out | ios::trunc);
    file.close();

    StartGame();

    return 0;
}