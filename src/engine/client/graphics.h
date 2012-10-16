#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
  
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Graphics
{
    public:
GLuint* image1;
       int loadimage(char* filename,GLuint* image);
int Init( );
int drawGLScene( ); 
       Graphics();
};
#endif
