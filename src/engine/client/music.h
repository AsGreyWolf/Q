#ifndef _MUSIC_H_
#define _MUSIC_H_
# ifdef __gnu_linux__  

#include <include/lin_x64/SDL.h>
#include <include/lin_x64/SDL_mixer.h>
#include <include/lin_x64/SDL_audio.h>

# else
#include <include/win_32/SDL.h>
#include <include/win_32/SDL_mixer.h>
#include <include/win_32/SDL_audio.h>
# endif

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
