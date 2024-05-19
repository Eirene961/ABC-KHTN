#include "Sound.h"


void PlayEatingSound()
{
	PlaySound(TEXT("eatingSound.wav"), NULL, SND_FILENAME | SND_SYNC);
}

void PlayClick()
{
	PlaySound(TEXT("click.wav"), NULL, SND_FILENAME | SND_SYNC);
}

void PlayMusic()
{
	PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void StopMusic()
{
	PlaySound(NULL, 0, 0);
}

void setVolume(DWORD volume)
{
    waveOutSetVolume(0, volume | (volume << 16));
}