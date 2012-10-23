#ifndef _SOUND_H_
#define _SOUND_H_
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_mixer.h>

class Sound
{
public:
	Mix_Chunk *sound;
	int Load(char *path);
	int Play (int chanell, int volume);
	int Pause();
	int Resume();
	int UnLoad();
	int IsPlaying();
	//void MusicDone();
	int chanel;
	int Done;
};

#endif
