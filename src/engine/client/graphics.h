#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
  
#include <SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>



	SDL_Surface *LoadImage(char* image);
	void DrawIMG(SDL_Surface *img, int x, int y ,SDL_Surface *screen);
	void DrawIMGRect(SDL_Surface *img, SDL_Rect dest ,SDL_Surface *screen);

#endif
