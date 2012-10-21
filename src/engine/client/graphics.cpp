#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#include "graphics.h"

SDL_Surface *Graphics::LoadImage(const char* image)
{
	SDL_Surface* Temp = NULL;
	SDL_Surface* Result = NULL;
	if((Temp = SDL_LoadBMP(image)) == NULL) 
	{
		return NULL;
	}
	Result = SDL_DisplayFormat(Temp);
	SDL_FreeSurface(Temp);
	return Result;
}
void Graphics::DrawIMG(SDL_Surface *img, int x, int y ,SDL_Surface *screen)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format,0,0,0));
	SDL_BlitSurface(img, NULL, screen, &dest);
}

#endif
