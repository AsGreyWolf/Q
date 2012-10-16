#ifndef _TEXTRENDER_H_
#define _TEXTRENDER_H_

#include <SDL.h>
#include "gl.h"
#include "glu.h"
 
class TextRender
{ 
    public:
       GLuint* loadimage(char* filename,GLuint* image);
       graphics();
};
#endif
