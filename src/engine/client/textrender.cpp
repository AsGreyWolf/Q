#ifndef _TEXTRENDER_CPP_
#define _TEXTRENDER_CPP_
#include "textrender.h"
#include "SDL_image.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "coords.h"
#include <GL/gl.h>
#include <GL/glu.h>

int TextRender::Init()
{
	TTF_Init();
	atexit(TTF_Quit);
	return 1;
}

void TextRender::print_ttf(SDL_Surface *sDest, char* message, char* font, float size, SDL_Color color, SDL_Rect dest, bool righttoleft,bool downtoup)
{
	TTF_Font *fnt = TTF_OpenFont(font, topoints(size));
	SDL_Rect dest2;
	SDL_Surface *sText = TTF_RenderText_Blended( fnt, message, color);
	int w,h;
	TTF_SizeText(fnt,message,&w,&h);
	if(righttoleft)
	dest2.x=dest.x-w;
	else
	dest2.x=dest.x;
	if(downtoup)
	dest2.y=dest.y-h;
	else
	dest2.y=dest.y;
	SDL_BlitSurface( sText,NULL, sDest,&dest2 );
	SDL_FreeSurface( sText );
	TTF_CloseFont( fnt );

}
void TextRender::TextRender_Exit()
{
	atexit(TTF_Quit);
}

#endif
