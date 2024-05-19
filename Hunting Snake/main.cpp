#include "Game.h"


int main() {
    system("color F0");

    std::thread eatingSound(EatingSound);
    std::thread music;
    setVolume(0x7FFF);
    music = std::thread(PlayMusic);

    ofstream load("LOADGAME.txt");
    load.close();
    ofstream rank("RANK.txt");
    rank.close();

    StartGame();

    eatingSound.join();
    music.join();
    return 0;
}