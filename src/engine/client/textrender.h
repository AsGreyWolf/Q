#ifndef _TEXTRENDER_H_
#define _TEXTRENDER_H_

#include <SDL.h>
#include <SDL_ttf.h>

 
class TextRender
{ 
    public:
	int Init();
	void TextRender_Exit();
	void print_ttf( char* message, char* font, int size, SDL_Color color, SDL_Rect dest);
SDL_Surface* LoadFont(char* BitmapFont);
void DrawText(SDL_Surface* sFont, int x, int y, char * str,SDL_Surface* screen);
void SDL_GL_RenderText(char *text, 
                      TTF_Font *font,
                      SDL_Color color,
                      SDL_Rect *location);
void glEnable2D();
void glDisable2D();
int round(double x);
int nextpoweroftwo(int x);
};
#endif
