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

void TextRender::print_ttf(char* message, char* font, float size, SDL_Color color, float x,float y, bool righttoleft, bool downtoup)
{
	TTF_Font *fnt = TTF_OpenFont(font, topoints(size));
	SDL_Surface *sText = TTF_RenderText_Blended( fnt, message, color);
	int ww,hh;
	float w,h;
	TTF_SizeText(fnt,message,&ww,&hh);
	w=pixtogl(ww,false);
	h=pixtogl(hh,true);
	if(righttoleft)
	x=x-w;
	else
	x=x;
	if(downtoup)
	y=y-h;
	else
	y=y;
	//printf("rendered x=%f, y=%f, w=%f, h=%f\n",x,-y,w,h);
	DrawIMG(GetTex(sText,1), x, y, w, h);
	
	SDL_FreeSurface( sText );
	TTF_CloseFont( fnt );

}
void TextRender::TextRender_Exit()
{
	atexit(TTF_Quit);
}

#endif
