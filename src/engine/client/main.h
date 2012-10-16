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
	void Cleanup();	
	class Graphics *Graphics() {return Graphics};
    private:
	class Graphics *Graphics;
	SDL_Surface*    Screen;
       bool Running;
};
#endif
