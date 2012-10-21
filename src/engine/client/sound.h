#ifndef _SOUND_H_
#define _SOUND_H_
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_mixer.h>

class Sound
{
public:
int Init();
Mix_Music *music;
Mix_Chunk *sound;
int LoadSound(char *path);
int PlaySound ();
int PlayMusic (int chanel);
int LoadMusic(char* file);
void Quit();
//void MusicDone();
int Done;
};

#endif
