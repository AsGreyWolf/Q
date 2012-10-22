#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#include "graphics.h"

SDL_Surface *Graphics::LoadImage(char* image)
{
	return IMG_Load(image);
}
void Graphics::DrawIMG(SDL_Surface *img, int x, int y ,SDL_Surface *screen)
{

 SDL_Rect dest;
 dest.x = x;
 dest.y = y;

 SDL_BlitSurface(img, NULL, screen, &dest);

}

#endif
