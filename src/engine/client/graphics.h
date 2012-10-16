#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
 
#include <SDL.h>
#include "gl.h"
#include "glu.h"
 
class graphics
{
    public:
       loadimage(char* filename,GLuint* image);
       graphics();
};
#endif
