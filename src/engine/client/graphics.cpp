#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#include "graphics.h"
#include <math.h>

int Graphics::round(double x)
{
	return (int)(x + 0.5);
}
int Graphics::DestroyImage(GLuint texture){
glDeleteTextures(1, &texture);
}
int Graphics::nextpoweroftwo(int x)
{
	double logbase2 = log(x) / log(2);
	return round(pow(2,ceil(logbase2)));
}
Graphics::Graphics()
{

}

int Graphics::resizeWindow( int width, int height )
{
    /* Height / width ration */
    GLfloat ratio;
 
    /* Protect against a divide by zero */
    if ( height == 0 )
	height = 1;

    ratio = ( GLfloat )width / ( GLfloat )height;

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLint )width, ( GLint )height );

    /*
     * change to the projection matrix and set
     * our viewing volume.
     */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( );

    return( TRUE );
}
GLuint Graphics::LoadImage(char* filename,GLuint image)
{
    /* Status indicator */
SDL_Surface *surface;	// This surface will tell us the details of the image
GLenum texture_format;
GLint  nOfColors;
 
if ( (surface = SDL_LoadBMP(filename)) ) { 
 
	// Check that the image's width is a power of 2
	if ( (surface->w & (surface->w - 1)) != 0 ) {
		printf("warning: image.bmp's width is not a power of 2\n");
	}
 
	// Also check if the height is a power of 2
	if ( (surface->h & (surface->h - 1)) != 0 ) {
		printf("warning: image.bmp's height is not a power of 2\n");
	}
 
        // get the number of channels in the SDL surface
        nOfColors = surface->format->BytesPerPixel;
        if (nOfColors == 4)     // contains an alpha channel
        {
                if (surface->format->Rmask == 0x000000ff)
                        texture_format = GL_RGBA;
                else
                        texture_format = GL_BGRA;
        } else if (nOfColors == 3)     // no alpha channel
        {
                if (surface->format->Rmask == 0x000000ff)
                        texture_format = GL_RGB;
                else
                        texture_format = GL_BGR;
        } else {
                printf("warning: the image is not truecolor..  this will probably break\n");
                // this error should not go unhandled
        }
 
	// Have OpenGL generate a texture object handle for us
	glGenTextures( 1, &image );
 
	// Bind the texture object
	glBindTexture( GL_TEXTURE_2D, image );
 
	// Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
 
	// Edit the texture object's image data using the information SDL_Surface gives us
	glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
                      texture_format, GL_UNSIGNED_BYTE, surface->pixels );
} 
else {
	printf("SDL could not load image.bmp: %s\n", SDL_GetError());
	SDL_Quit();
	return 0;
}    
 
// Free the SDL_Surface only if it was successfully created
if ( surface ) { 
	SDL_FreeSurface( surface );
}

    return image;
}


/* Here goes our drawing code */
int Graphics::drawGLScene(GLuint texture )
{
    /* These are to calculate our fps */
    
    

    /* Clear The Screen And The Depth Buffer */

    /* Move Into The Screen 5 Units */
    glLoadIdentity( );
    glTranslatef( 0.0f, 0.0f, -5.0f );

    glRotatef( 0.0f, 1.0f, 0.0f, 0.0f); /* Rotate On The X Axis */
    glRotatef( 0.0f, 0.0f, 1.0f, 0.0f); /* Rotate On The Y Axis */
    glRotatef( 0.0f, 0.0f, 0.0f, 1.0f); /* Rotate On The Z Axis */

    /* Select Our Texture */
    glBindTexture( GL_TEXTURE_2D, texture );

    /* NOTE:
     *   The x coordinates of the glTexCoord2f function need to inverted
     * for SDL because of the way SDL_LoadBmp loads the data. So where
     * in the tutorial it has glTexCoord2f( 1.0f, 0.0f ); it should
     * now read glTexCoord2f( 0.0f, 0.0f );
     */
    glBegin(GL_QUADS);
      /* Front Face */
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f, -1.0f, 1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f, -1.0f, 1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f,  1.0f, 1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f,  1.0f, 1.0f );

      /* Back Face */
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f,  1.0f, -1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f, -1.0f, -1.0f );

      /* Top Face */
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -1.0f,  1.0f,  1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f(  1.0f,  1.0f,  1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f(  1.0f,  1.0f, -1.0f );

      /* Bottom Face */
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f, -1.0f, -1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f, -1.0f,  1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f,  1.0f );

      /* Right face */
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( 1.0f, -1.0f, -1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( 1.0f,  1.0f, -1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f( 1.0f,  1.0f,  1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f( 1.0f, -1.0f,  1.0f );

      /* Left Face */
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f,  1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f,  1.0f,  1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
    glEnd( );

    /* Draw it to the screen */
    

    /* Gather our frames per second */
    
    return( TRUE );
}
int Graphics::Init( )  
{

/* Flags to pass to SDL_SetVideoMode */
    
//printf("initted");
    
    /* Enable Texture Mapping ( NEW ) */
    glEnable( GL_TEXTURE_2D );

    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

    /* Depth buffer setup */
    glClearDepth( 1.0f );
	
    /* Enables 	Depth Testing */
    glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );
    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

 resizeWindow( SCREEN_WIDTH, SCREEN_HEIGHT );

 
    return( TRUE );
}
#endif
