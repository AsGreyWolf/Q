#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
  
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

	#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16

/* Set up some booleans */
#define TRUE  1
#define FALSE 0

class Graphics
{
    public:


/* This is our SDL surface */
SDL_Surface *surface;

GLfloat xrot; /* X Rotation ( NEW ) */
GLfloat yrot; /* Y Rotation ( NEW ) */
GLfloat zrot; /* Z Rotation ( NEW ) */
	GLuint images[1];
       int LoadImage(char* filename,GLuint image);
	int Init(  );
	int drawGLScene(  ); 
       Graphics();
	int resizeWindow( int width, int height );
};
#endif
