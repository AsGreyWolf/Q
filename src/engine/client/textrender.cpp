#ifndef _TEXTRENDER_CPP_
#define _TEXTRENDER_CPP_
#include "textrender.h"
#include "SDL_image.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
int TextRender::round(double x)
{
	return (int)(x + 0.5);
}

int TextRender::nextpoweroftwo(int x)
{
	double logbase2 = log(x) / log(2);
	return round(pow(2,ceil(logbase2)));
}
int TextRender::Init()
{
	TTF_Init();
	atexit(TTF_Quit);
	return 1;
}
void TextRender::SDL_GL_RenderText(char *text, 
                      TTF_Font *font,
                      SDL_Color color,
                      SDL_Rect *location)
{
	SDL_Surface *initial;
	SDL_Surface *intermediary;
	SDL_Rect rect;
	int w,h;
	GLuint texture;
	
	/* Use SDL_TTF to render our text */
	initial = TTF_RenderText_Solid(font, text, color);
	
	/* Convert the rendered text to a known format */
	
	w = nextpoweroftwo(initial->w);
	h = nextpoweroftwo(initial->h);
	
	intermediary = SDL_CreateRGBSurface(0, w, h, 32, 
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	SDL_BlitSurface(initial, 0, intermediary, 0);
	
	/* Tell GL about our new texture */
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, w, h, 0, GL_BGRA, 
			GL_UNSIGNED_BYTE, intermediary->pixels );
	
	/* GL_NEAREST looks horrible, if scaled... */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	

	/* prepare to render our texture */
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	/* Draw a quad at location */
	glBegin(GL_QUADS);
		/* Recall that the origin is in the lower-left corner
		   That is why the TexCoords specify different corners
		   than the Vertex coors seem to. */
		glTexCoord2f(0.0f, 1.0f); 
			glVertex2f(location->x    , location->y);
		glTexCoord2f(1.0f, 1.0f); 
			glVertex2f(location->x + w, location->y);
		glTexCoord2f(1.0f, 0.0f); 
			glVertex2f(location->x + w, location->y + h);
		glTexCoord2f(0.0f, 0.0f); 
			glVertex2f(location->x    , location->y + h);
	glEnd();
	
	/* Bad things happen if we delete the texture before it finishes */
	glFinish();
	
	/* return the deltas in the unused w,h part of the rect */
	location->w = initial->w;
	location->h = initial->h;
	
	/* Clean up */
	SDL_FreeSurface(initial);
	SDL_FreeSurface(intermediary);
	glDeleteTextures(1, &texture);
}

void TextRender::glEnable2D()
{
	int vPort[4];
  
	glGetIntegerv(GL_VIEWPORT, vPort);
  
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
  
	glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void TextRender::glDisable2D()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();   
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();	
}
void TextRender::print_ttf( char* message, char* font, int size, SDL_Color color, SDL_Rect dest)
{
		glLoadIdentity();
	TTF_Font *fnt = TTF_OpenFont(font, size);
	/*SDL_Surface *sText = TTF_RenderText_Blended( fnt, message, color);
	SDL_BlitSurface( sText,NULL, sDest,&dest );
	SDL_FreeSurface( sText );*/
		glEnable2D();
		glDisable(GL_DEPTH_TEST);
		
		/* Draw some text */
		
		/** A quick note about position.
		 * Enable2D puts the origin in the lower-left corner of the
		 * screen, which is different from the normal coordinate
		 * space of most 2D api's. position, therefore,
		 * gives the X,Y coordinates of the lower-left corner of the
		 * rectangle **/
		SDL_GL_RenderText(message, fnt, color, &dest);

		/* Come out of HUD mode */
		glEnable(GL_DEPTH_TEST);
		glDisable2D();
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
