#include "Game.h"


int main() {
    system("color F0");

    std::thread eatingSound(EatingSound);
    std::thread music;
    music = std::thread(PlayMusic);
    setVolume(0x7FFF);

    ofstream load("LOADGAME.txt");
    load.close();
    ofstream rank("RANK.txt");
    rank.close();

    StartGame(music);

    eatingSound.join();
    music.join();
    return 0;
}