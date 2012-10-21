#ifndef _SOUND_CPP_
#define _SOUND_CPP_

#include "sound.h"
//Sound::Sound(){}
int Sound::LoadSound(char *path)
{
	sound = Mix_LoadWAV ("1.wav");
	return 1;
}
int Sound::PlaySound ()
{
	//printf ("playing");
	if (!sound)
	{
		//printf ("Mix_LoadWAV: %s\n", Mix_GetError ());  
		return 0;
	}
	// играет в первом свободном канале
	// 3 параметр если 0 то 1 раз играет если 1 то 2 раза и т.д.
	if (Mix_PlayChannel (-1, sound, 0) == 0)
	{
		// printf ("Mix_PlayChannel: %s\n", Mix_GetError ());  
		return 0;
	}
	return 1;
}
int Sound::LoadMusic(char* file)
{
	music = Mix_LoadMUS (file);
	return 1;
}
int Sound::PlayMusic (int chanel)
{
	Done=0;
	if (!music)
	{
		//printf ("Mix_LoadMUS(\"*.*\"): %s\n", Mix_GetError ());  
		return 0;
	}
 
 
	if (Mix_PlayMusic (music, chanel) == chanel)
	{
		return 0;
		//printf ("Mix_PlayMusic: %s\n", Mix_GetError ());  
	}
	// Mix_HookMusicFinished(MusicDone);
	return 1;
}

/*void Sound::MusicDone(){
	Mix_HaltMusic();

	/* Unload the music from memory, since we don't need it
	   anymore *\/
	Mix_FreeMusic(music);
	Done=1;
	music = NULL;
	return;
}*/

#endif
