#ifndef _TEXTRENDER_CPP_
#define _TEXTRENDER_CPP_
#include "textrender.h"
#include "SDL_image.h"
int TextRender::Init()
{
	TTF_Init();
	atexit(TTF_Quit);
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
SDL_Surface* TextRender::LoadFont(char* BitmapFont){

  SDL_Surface* temp;
  
  temp = IMG_Load(BitmapFont);
  if(temp == NULL){
  	printf("Can't load image %s\n",BitmapFont);
	return NULL;
  }
  
  SDL_SetColorKey(temp,SDL_SRCCOLORKEY,SDL_MapRGB(temp->format,255,255,255));
  
  return temp;

}

/* ------------------------------------------------------ */
void TextRender::DrawText(SDL_Surface* sFont, int x, int y, char * str,SDL_Surface* screen){

  int i;
  SDL_Rect src, dest;
  
  for (i = 0; i < strlen(str); i++)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  src.x = (str[i] - 'A') * 32;
	  src.y = 0;
	  src.w = 32;
	  src.h = 32;
	  
	  dest.x = x + (i * 32);
	  dest.y = y;
	  dest.w = 32;
	  dest.h = 32;
	  
	  SDL_BlitSurface(sFont, &src,
			  screen, &dest);
	}
    }
  SDL_Flip(screen);
  
}
#endif
