#ifndef _TEXTRENDER_H_
#define _TEXTRENDER_H_

#include <SDL.h>
#include <SDL_ttf.h>

 
class TextRender
{ 
    public:
	int Init();
	void TextRender_Exit();
	void print_ttf(SDL_Surface *sDest, char* message, char* font, int size, SDL_Color color, SDL_Rect dest);
};
#endif
