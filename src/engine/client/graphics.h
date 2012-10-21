#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
  
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>


class Graphics
{
    public:
	SDL_Surface *LoadImage(const char* image);
	void DrawIMG(SDL_Surface *img, int x, int y ,SDL_Surface *screen);
};
#endif
