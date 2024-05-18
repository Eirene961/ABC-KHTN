#include "Game.h"


int main() {
    system("color F0");

    ofstream load("LOADGAME.txt");
    load.close();
    ofstream rank("RANK.txt");
    rank.close();

    StartGame();
    return 0;
}