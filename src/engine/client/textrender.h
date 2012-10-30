#ifndef _TEXTRENDER_H_
#define _TEXTRENDER_H_

# ifdef __gnu_linux__  

#include <include/lin_x64/SDL.h>
#include <include/lin_x64/SDL_ttf.h>
#include <include/lin_x64/SDL_image.h>

# else
#include <include/win_32/SDL.h>
#include <include/win_32/SDL_ttf.h>
#include <include/win_32/SDL_image.h>
# endif
#include "graphics.h"

 
class TextRender
{ 
    public:
	int Init();
	void TextRender_Exit();
	void print_ttf(char* message, char* font, float size, SDL_Color color, float x,float y, bool righttoleft, bool downtoup);
	SDL_Surface* LoadFont(char* BitmapFont);
	void DrawText(SDL_Surface* sFont, int x, int y, char * str,SDL_Surface* screen);

};
#endif
