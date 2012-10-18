#ifndef _MAIN_H_
#define _MAIN_H_  
#include "graphics.h"
#include <SDL.h>
 

class mainmain 
{
    public:
       mainmain();
       int Execute();
	bool Init();
void Quit( int returnCode );
	void Cleanup();		
Graphics *m_pGraphics;
    private:
	SDL_Surface*    Screen;
       bool Running;
};
#endif
