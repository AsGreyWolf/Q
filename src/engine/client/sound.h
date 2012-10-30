#ifndef _SOUND_H_
#define _SOUND_H_
# ifdef __gnu_linux__  

#include <include/lin_x64/SDL.h>
#include <include/lin_x64/SDL_mixer.h>
#include <include/lin_x64/SDL_audio.h>

# else
#include <include/win_32/SDL.h>
#include <include/win_32/SDL_mixer.h>
#include <include/win_32/SDL_audio.h>
# endif

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
