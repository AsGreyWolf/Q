#ifndef _MAIN_H_
#define _MAIN_H_
 
#include <SDL.h>
 
class main 
{
    public:
       main();
       int Execute();
	bool Init();
	void Cleanup();
	void Event(SDL_Event* Event);
    private:
	SDL_Surface*    Screen;
       bool Running;
};
#endif
