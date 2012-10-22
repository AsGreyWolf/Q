#ifndef _SOUND_CPP_
#define _SOUND_CPP_

#include "sound.h"
//Sound::Sound(){}
int Sound::Load(char *path){
sound = Mix_LoadWAV ("1.wav");
return 1;
}
int Sound::Play (int chanell, int volume)
{
chanel=chanell;
//printf ("playing");
 if (!sound)
 {
 //printf ("Mix_LoadWAV: %s\n", Mix_GetError ());  
 return 0;
 }
 
 
// играет в первом свободном канале
// 3 параметр если 0 то 1 раз играет если 1 то 2 раза и т.д.
Mix_VolumeChunk(sound, volume);
 if (Mix_PlayChannel (chanel, sound, 0) == 0)
 {
// printf ("Mix_PlayChannel: %s\n", Mix_GetError ());  
	return 0;
 }
 return 1;
}
int Sound::Pause(){
Mix_Pause(chanel);
return 1;
}
int Sound::Resume(){
Mix_Resume(chanel);
return 1;
}
int Sound::UnLoad(){
Mix_HaltChannel(chanel);
Mix_FreeChunk(sound);
sound=NULL;
return 1;
}
int Sound::IsPlaying(){
return Mix_Playing(chanel);
}
#endif
