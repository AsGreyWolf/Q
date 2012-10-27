#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#include "graphics.h"

GLuint GetTex( SDL_Surface* image,int mode)
{
	GLuint texture[1];
	/* Create storage space for the texture */
    SDL_Surface* NewSurface;

    /* Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit */
    if ( image )
        {

	   NewSurface = SDL_ConvertSurface(image, image->format,SDL_SWSURFACE | SDL_SRCALPHA);
	    /* Create The Texture */
	    glGenTextures( 1, &texture[0] );

	    /* Typical Texture Generation Using Data From The Bitmap */
	    glBindTexture( GL_TEXTURE_2D, texture[0] );
		
	    /* Generate The Texture */
	   // glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
	//		  TextureImage[0]->h, 0, GL_BGR,
	//		  GL_UNSIGNED_BYTE, TextureImage[0]->pixels );
	    SDL_PixelFormat *format = NewSurface->format;
	    
   		if (format->Amask)
   		{
   			int f;
	    		if(mode==0){
	    			f=GL_RGBA;
	    		}else{
	    			f=GL_BGRA;
	    		}
      			gluBuild2DMipmaps(GL_TEXTURE_2D, 4,
         		NewSurface->w, NewSurface->h, f,GL_UNSIGNED_BYTE, NewSurface->pixels);
   		}
   		else
   		{
   			int f;
	    		if(mode==0){
	    			f=GL_RGB;
	    		}else{
	    			f=GL_BGR;
	    		}
     			gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
         		NewSurface->w, NewSurface->h, f, GL_UNSIGNED_BYTE, NewSurface->pixels);
   		}

	    /* Linear Filtering */
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP);
    	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP);
    	    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE); 
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); 
        }

    /* Free up any memory we may have used */
  
	return texture[0];
}
GLuint LoadImage(char* image,int mode)
{
	GLuint texture[1];
	/* Create storage space for the texture */
    SDL_Surface *TextureImage[1]; 
    SDL_Surface* NewSurface;

    /* Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit */
    if ( ( TextureImage[0] = IMG_Load( image ) ) )
        {

	    /* Set the status to true */
		NewSurface = SDL_ConvertSurface(TextureImage[0], TextureImage[0]->format,SDL_SWSURFACE | SDL_SRCALPHA);
	    /* Create The Texture */
	    glGenTextures( 1, &texture[0] );

	    /* Typical Texture Generation Using Data From The Bitmap */
	    glBindTexture( GL_TEXTURE_2D, texture[0] );
		
	    /* Generate The Texture */
	   // glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
	//		  TextureImage[0]->h, 0, GL_BGR,
	//		  GL_UNSIGNED_BYTE, TextureImage[0]->pixels );
	    SDL_PixelFormat *format = NewSurface->format;
   		if (format->Amask)
   		{
   			int f;
	    		if(mode==0){
	    			f=GL_RGBA;
	    		}else{
	    			f=GL_BGRA;
	    		}
      			gluBuild2DMipmaps(GL_TEXTURE_2D, 4,
         		NewSurface->w, NewSurface->h, f,GL_UNSIGNED_BYTE, NewSurface->pixels);
   		}
   		else
   		{
   			int f;
	    		if(mode==0){
	    			f=GL_RGB;
	    		}else{
	    			f=GL_BGR;
	    		}
     			gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
         		NewSurface->w, NewSurface->h, f, GL_UNSIGNED_BYTE, NewSurface->pixels);
   		}

	    /* Linear Filtering */
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP);
    	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP);
    	    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE); 
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); 
        }

    /* Free up any memory we may have used */
    if ( TextureImage[0] )
	    SDL_FreeSurface( TextureImage[0] );
	return texture[0];
}
void DrawIMG(GLuint img, float x, float y, float w, float h)
{

	glBindTexture(GL_TEXTURE_2D, img);
	//SDL_BlitSurface(img, NULL, screen, &dest);
	glBegin(GL_QUADS);
	//printf("rendered x=%f, y=%f, w=%f, h=%f\n",x,-y,w,h);
       glTexCoord2f(0.0f, 1.0f); glVertex3f(x,  -y-h,  1.0f);	// Низ лево
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x+w, -y-h,  1.0f);	// Низ право
	glTexCoord2f(1.0f, 0.0f); glVertex3f( x+w,  -y,  1.0f);	// Верх право
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x,  -y,  1.0f);	// Верх лево
       glEnd();

}


#endif
