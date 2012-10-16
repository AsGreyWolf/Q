#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include "graphics.h"
 
graphics::graphics()
{

}
graphics::loadimage(char* filename, GLuint* image){
	AUX_RGBImageRec *texture1;
	texture1 = auxDIBImageLoad("filename");
	glGenTextures(1, &image);
	glBindTexture(GL_TEXTURE_2D, image);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0,
	GL_RGB, GL_UNSIGNED_BYTE, texture1->data);

}

#endif
