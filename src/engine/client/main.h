#ifndef _MAIN_H_
#define _MAIN_H_
 
#include <SDL.h>
 
class mainmain 
{
    public:
       mainmain();
       int Execute();
	bool Init();
	void Cleanup();
	
    private:
	SDL_Surface*    Screen;
       bool Running;
};
#endif
