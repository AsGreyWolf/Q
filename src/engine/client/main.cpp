#ifndef _MAIN_CPP_
#define _MAIN_CPP_
#include "main.h"
 
mainmain::mainmain() 
{
	Screen = NULL;
	Running = true;
}
bool mainmain::Init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        return false;
	}
 
	if((Screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
	} 
    
	return true;
}
int mainmain::Execute() 
{
	if(Init() == false) {
		 return -1;
	    }
	 
	    SDL_Event Event;
	 
	    while(Running) {
		 while(SDL_PollEvent(&Event)) {
		     Event(&Event);
		 }	 
		
	    }
	 Cleanup();
	 return 0;    
}
 
int main(int argc, char* argv[]) 
{
	mainmain main0;
 
	return main0.Execute();
}
void mainmain::Cleanup()
{
	SDL_Quit();
}
void mainmain::Event(SDL_Event* Event) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
}
#endif
