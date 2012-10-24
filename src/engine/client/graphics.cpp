#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#include "graphics.h"

SDL_Surface *LoadImage(char* image)
{
	return IMG_Load(image);
}
void DrawIMG(SDL_Surface *img, int x, int y ,SDL_Surface *screen)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(img, NULL, screen, &dest);
}
void DrawIMGRect(SDL_Surface *img, SDL_Rect dest ,SDL_Surface *screen)
{

	SDL_BlitSurface(img, NULL, screen, &dest);

}


#endif
