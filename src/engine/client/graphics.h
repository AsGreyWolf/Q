#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
  
#include <SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>



	GLuint LoadImage(char* image, int mode);
	void DrawIMG(GLuint img, float x, float y, float w, float h);
	GLuint GetTex( SDL_Surface* image, int mode);
#endif
