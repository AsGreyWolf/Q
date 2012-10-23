#ifndef _AUDIO_H_
#define _AUDIO_H_
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_mixer.h>


class Audio
{
public:
	int Init();
	void Quit();
};

#endif
