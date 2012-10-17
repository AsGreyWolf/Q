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
    	SDL_WM_SetCaption("ololo game","v1");
	return true;
}
int mainmain::Execute()
{
	if(Init() == false) {
		 return -1;
	    }
	 
	   	Graphics *m_pGraphics; 
	    while(Running) {
		m_pGraphics->drawGLScene( );
		 SDL_Event Event;
		 while(SDL_PollEvent(&Event)) {
		       if (Event.type == SDL_QUIT){ 
      				Running = false;
     			}
		 }	 
		
	    }
	 Cleanup(); 
	 return 0;    
}
 
int main(int argc, char* argv[]) 
{
	mainmain main0;
Graphics *m_pGraphics;
	m_pGraphics->Init();
	return main0.Execute();
}
void mainmain::Cleanup()
{
	SDL_Quit();
}
#endif
