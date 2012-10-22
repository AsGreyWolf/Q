#ifndef _MUSIC_H_
#define _MUSIC_H_
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_mixer.h>

class Music
{
public:
Mix_Music *music;
int Play (int chanel, int volume);
int Load(char* file);
int Pause();
int Resume();
int UnLoad();
int IsPlaying();
int Done;
};

#endif
