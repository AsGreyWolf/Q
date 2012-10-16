#ifndef _MAIN_CPP_
#define _MAIN_CPP_
#include "main.h"
 
main::main() 
{
	Screen = NULL;
	Running = true;
}
bool main::Init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        return false;
	}
 
	if((Screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
	} 
    
	return true;
}
int main::Execute() 
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
	main main;
 
	return main.Execute();
}
void main::Cleanup()
{
	SDL_Quit();
}
void main::Event(SDL_Event* Event) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
}
#endif
