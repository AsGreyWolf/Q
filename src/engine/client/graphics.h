#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

# ifdef __gnu_linux__  

#include <include/lin_x64/SDL.h>
#include <include/lin_x64/SDL_image.h>

# else
#include <include/win_32/SDL.h>
#include <include/win_32/SDL_image.h>
# endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>



	GLuint LoadImage(char* image, int mode);
	void DrawIMG(GLuint img, float x, float y, float w, float h);
	GLuint GetTex( SDL_Surface* image, int mode);
#endif
