#include "Game.h"


int main() {
    system("color F0");

    std::thread music(PlayMusic);

    ofstream load("LOADGAME.txt");
    load.close();
    ofstream rank("RANK.txt");
    rank.close();

    StartGame();

    StopMusic();
    music.join();
    return 0;
}