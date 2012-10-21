#ifndef _AUDIO_CPP_
#define _AUDIO_CPP_

#include "audio.h"

Audio::Audio() 
{
	
}
void Audio::Quit(){
Mix_CloseAudio();
return;
}
int Audio::Init(){
 if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
 {
 //printf ("Mix_OpenAudio: %s\n", Mix_GetError ());
 return 0; //Если ошибка то прога закрывается  
 }
 //Mix_QuerySpec((int*)44100, MIX_DEFAULT_FORMAT, 2);
 return 1;
}
#endif
