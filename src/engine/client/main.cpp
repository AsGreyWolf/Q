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
	//Quit()
	SDL_Quit( );
	m_pText->TextRender_Exit();
	exit( returnCode );
}
bool mainmain::Init() 
{
	timer=0;
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
	}
	//name******************************************8
	SDL_WM_SetCaption("ololo game","v1");
	//name******************************************8
	    	
	if(m_pText->Init() == 0 && Running == false )
		return -1;
	if(m_pPlayer->Init() == 0)
		return -1;
	SDL_ShowCursor(0);
	return true;
}
int mainmain::Execute()
{
	static int Frames = 0;
	static int T0     = 0;
	static int T1     = 0;
	char sfps[8];
	
	if(Init() == false && Running == false ) 
		return -1;
		
	Audio *m_pAudio;
		
	if(m_pAudio->Init() == 0 && Running == false )
		return -1;
		
	Running = true;
	//******************
	SDL_Color clr;
	SDL_Rect dest;
	clr.r = 255;
	clr.g = 255;
	clr.b = 0;
	//******************
	int mouseposx=0;
	int mouseposy=0;
	//*****************
	dest.x = 70;
	dest.y = 200;
	SDL_Color clr2;
	SDL_Rect dest2;
	clr2.r = 255;
	clr2.g = 255;
	clr2.b = 255;
	dest2.x = 0;
	dest2.y = 0;
	//*****************
	SDL_Surface *cursor;
	image=m_pGraphics->LoadImage("data/images/kolobok.bmp"); 
	cursor=m_pGraphics->LoadImage("data/gui_cursor.bmp"); 
	Uint8 *keys;
	//******************
	char fpss[10];
	Sound* sound=new Sound;
	sound->LoadSound("1.wav");
	sound->PlaySound();
	//****************
	bool stopxp;
	bool stopxm;
	bool stopyp;
	bool stopym;
	while(Running) 
	{
		//****************
		SDL_GetMouseState(&mouseposx, &mouseposy);
		//OnCleanUp()
		SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));
		m_pGraphics->DrawIMG(image, m_pPlayer->m_Posx,m_pPlayer->m_Posy ,Screen);
		//OnRender()
		m_pText->print_ttf(Screen, "SDL_ttf example", "data/courier.ttf", 46, clr, dest);
		m_pText->print_ttf(Screen,sfps , "data/courier.ttf", 15, clr2, dest2);
		m_pGraphics->DrawIMG(cursor, mouseposx,mouseposy, Screen);
		SDL_Flip(Screen);
		SDL_Event Event;
		if(m_pPlayer->m_Posx == 500)
			stopxp = true;
		else 	stopxp = false;
		if(m_pPlayer->m_Posx == 0)
			stopxm = true;
		else 	stopxm = false;
		if(m_pPlayer->m_Posy == 400)
			stopyp = true;
		else 	stopyp = false;
		if(m_pPlayer->m_Posy == 0)
			stopym = true;
		else 	stopym = false;
		//**********************
		while(SDL_PollEvent(&Event)) 
		{
			//OnEvent
			if (Event.type == SDL_QUIT)
			{ 
				Running = false;
			}
		}
		//OnKeyDown()
		keys = SDL_GetKeyState(NULL);
		if(keys[SDLK_UP])
		{ 
			if(!stopym)
			m_pPlayer->m_Posy -= 1; 
		}
		if(keys[SDLK_DOWN])
		{
			if(!stopyp)
				m_pPlayer->m_Posy += 1; 
		}
		if(keys[SDLK_LEFT])
		{ 
			if(!stopxm)
				m_pPlayer->m_Posx -= 1; 
		}
		
		if(keys[SDLK_RIGHT])
		{
			if(!stopxp)
				m_pPlayer->m_Posx += 1; 
		}
		Frames++;
	
		//ticks
		int t = SDL_GetTicks();
		timer += (t - T1) / 1000.0;
		T1 = t;
	
		if (t - T0 >= 1000) 
		{
			float seconds = (t - T0) / 1000.0;
			float fps = Frames / seconds;
			sprintf(sfps,"%d FPS", (int)fps);
			printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
			T0 = t;
			Frames = 0;
		}
	}	
	
	m_pAudio->Quit();
	Quit(0);
	return 0;
}
 
int main(int argc, char* argv[]) 
{
	mainmain main0;

	
	return main0.Execute();
}
#endif
