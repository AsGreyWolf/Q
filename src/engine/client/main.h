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
	Graphics *Graphics();
    private:
	SDL_Surface*    Screen;
       bool Running;
};
#endif
