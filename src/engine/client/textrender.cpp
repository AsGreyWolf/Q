#ifndef _TEXTRENDER_CPP_
#define _TEXTRENDER_CPP_
#include "textrender.h"
int TextRender::Init()
{
	TTF_Init();
	return 1;
}
void TextRender::print_ttf(SDL_Surface *sDest, char* message, char* font, int size, SDL_Color color, SDL_Rect dest)
{
	TTF_Font *fnt = TTF_OpenFont(font, size);
	SDL_Surface *sText = TTF_RenderText_Blended( fnt, message, color);
	SDL_BlitSurface( sText,NULL, sDest,&dest );
	SDL_FreeSurface( sText );
	TTF_CloseFont( fnt );
}
void TextRender::TextRender_Exit()
{
	atexit(TTF_Quit);
}
#endif
