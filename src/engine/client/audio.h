#ifndef _AUDIO_H_
#define _AUDIO_H_
# ifdef __gnu_linux__  

#include <include/lin_x64/SDL.h>
#include <include/lin_x64/SDL_mixer.h>
#include <include/lin_x64/SDL_audio.h>

# else
#include <include/win_32/SDL.h>
#include <include/win_32/SDL_mixer.h>
#include <include/win_32/SDL_audio.h>
# endif


class Audio
{
public:
	int Init();
	void Quit();
};

#endif
