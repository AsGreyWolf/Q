#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
void CMain::Init()
{
	m_Posx = 0;
	m_Posy = 0;
} 
int CMain::main(int argc, char *argv[])
{
	Init();
	Uint8* keys;
 
	if ( SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0 ){ 
	  printf("Unable to init SDL: %s\n", SDL_GetError()); 
	  exit(1); 
	} 
	 
	atexit(SDL_Quit); 

	SDL_WM_SetCaption("OLOLO game","xz 4e sdes");
	SDL_Color colors[256];

	for(int i=0;i<256;i++){
	  colors[i].r=i;
	  colors[i].g=i;
	  colors[i].b=i;
	}

 	 
	screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
	if ( screen == NULL ){ 
	  printf("Unable to set 640x480 video: %s\n", SDL_GetError()); 
	  exit(1); 
	}
	SDL_SetColors(screen, colors, 0, 256);

	int done=0; 
	while(done == 0){ 
	  
	  SDL_Event event; 
	  
	  while ( SDL_PollEvent(&event) )
	  { 
	    if ( event.type == SDL_QUIT ){ done = 1; } 
	    if ( event.type == SDL_KEYDOWN )
	    {
	      if ( event.key.keysym.sym == SDLK_ESCAPE ){ done = 1; } 
	    } 
	  }
   
	   keys = SDL_GetKeyState(NULL);
	   if(keys[SDLK_UP]){ m_Posy -= 1; }
	   if(keys[SDLK_DOWN]){ m_Posy += 1; }
	   if(keys[SDLK_LEFT]){ m_Posx -= 1; }
	   if(keys[SDLK_RIGHT]){ m_Posx += 1; }
	   
	   	 }
	return 0;
}

