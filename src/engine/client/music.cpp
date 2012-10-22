#ifndef _MUSIC_CPP_
#define _MUSIC_CPP_

#include "music.h"

int Music::Load(char* file){
music = Mix_LoadMUS (file);
return 1;
}
int Music::Play (int chanel, int volume)
{
Done=0;
 if (!music)
 {
 printf ("Mix_LoadMUS(\"*.*\"): %s\n", Mix_GetError ());  
 return 0;
 }
 
 
 if (Mix_PlayMusic (music, chanel) == chanel)
 {
 return 0;
 //printf ("Mix_PlayMusic: %s\n", Mix_GetError ());  
 }
// Mix_HookMusicFinished(MusicDone);
Mix_VolumeMusic(volume);
 return 1;
}
int Music::UnLoad(){
Mix_HaltMusic();
Mix_FreeMusic(music);
music=NULL;
return 1;
}
int Music::Pause(){
Mix_PauseMusic();
}
int Music::Resume(){
if(Mix_PausedMusic())
Mix_ResumeMusic();
}

int Music::IsPlaying(){
return Mix_PlayingMusic();
}

#endif
