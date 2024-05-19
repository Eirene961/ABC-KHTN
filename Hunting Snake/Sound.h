#ifndef _SOUND_H_
#define _SOUND_H_


#include <iostream>
#include <thread>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void PlayEatingSound();
void PlayClick();
void PlayMusic();
void StopMusic();
void setVolume(DWORD volume);


#endif