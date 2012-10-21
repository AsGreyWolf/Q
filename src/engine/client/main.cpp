#ifndef _MAIN_CPP_
#define _MAIN_CPP_ 
#include "main.h"
#include <sstream>
using std::stringstream;
#include <iostream>

mainmain::mainmain() 
{
	Screen = NULL;
	Running = false;
} 
void mainmain::Quit( int returnCode )
{
    SDL_Quit( );
    m_pText->TextRender_Exit();    
    exit( returnCode );
}
bool mainmain::Init() 
{

    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
	    fprintf( stderr, "SDL initialization failed: %s\n",
		     SDL_GetError( ) );
	    Quit( 1 );
	}
    
    Screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 

    if ( !Screen )
	{
	    fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
	    Quit( 1 );

    	SDL_WM_SetCaption("ololo game","v1");
	return true;
	}
}
int mainmain::Execute()
{
	static int Frames = 0;
	static int T0     = 0;
	stringstream iostr;
	char sfps[5];
		iostr<<0.0;
		iostr>>sfps;
	if(Init() == false && Running == false ) 
		 return -1;
	    	
	    
	 if(m_pText->Init() == 0 && Running == false )
		return -1;
		Running = true;
		SDL_Color clr;
 		SDL_Rect dest;
		clr.r = 255;
		clr.g = 255;
		clr.b = 0;
		dest.x = 70;
		dest.y = 200;
		SDL_Color clr2;
 		SDL_Rect dest2;
		clr2.r = 255;
		clr2.g = 255;
		clr2.b = 255;
		dest2.x = 0;
		dest2.y = 0;
		image=m_pGraphics->LoadImage("data/images/kolobok.bmp"); 
		Uint8 *keys;
		m_pPlayer->m_Posx = 10;
		m_pPlayer->m_Posy = 10;
	    while(Running) 
	    {
	    	SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));
		m_pGraphics->DrawIMG(image, m_pPlayer->m_Posx,m_pPlayer->m_Posy ,Screen);
		m_pText->print_ttf(Screen, "SDL_ttf example", "data/courier.ttf", 46, clr, dest);
		m_pText->print_ttf(Screen,sfps , "data/courier.ttf", 15, clr2, dest2);
				
		SDL_Flip(Screen);
		SDL_Event Event;
		while(SDL_PollEvent(&Event))
		{
		      if (Event.type == SDL_QUIT)
		      { 
      				Running = false;
     			}	
		}
		
		   keys = SDL_GetKeyState(NULL);
		   if(keys[SDLK_UP]){ m_pPlayer->m_Posy -= 1; }
		   if(keys[SDLK_DOWN]){ m_pPlayer->m_Posy += 1; }
		   if(keys[SDLK_LEFT]){ m_pPlayer->m_Posx -= 1; }
		   if(keys[SDLK_RIGHT]){ m_pPlayer->m_Posx += 1; }
		   Frames++;
    		{
	int t = SDL_GetTicks();
	if (t - T0 >= 1000) {
	    float seconds = (t - T0) / 1000.0;
	    float fps = Frames / seconds;
		stringstream iostr2;
		iostr2<<fps;
    		iostr2>>sfps;
	    printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
	    T0 = t;
	    Frames = 0;
		}
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
	
	m_pText->TextRender_Exit();
}
#endif
