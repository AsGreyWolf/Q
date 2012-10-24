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
	
	Screen = SDL_SetVideoMode(640,640,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
	
	if ( !Screen )
	{
		fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
		Quit( 1 );
	}
	SDL_WM_SetCaption("ololo game","v1");
	//Init()    	
	
	if(m_pText->Init() == 0 && Running == false )
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
	Map map;
		
	if(m_pAudio->Init() == 0 && Running == false )
		return -1;
	map.Open("data/maps/first.m");
	Running = true;
	SDL_Color clr;
	Coord dest;
	dest.SetX(4);
	dest.SetY(4);
	clr.r = 255;
	clr.g = 255;
	clr.b = 0;
	int mouseposx=0;
	int mouseposy=0;
	SDL_Color clr2;
	clr2.r = 255;
	clr2.g = 255;
	clr2.b = 255;
	Coord dest2;
	dest2.SetX(16);
	dest2.SetY(16);
	SDL_Surface *cursor;
	image=LoadImage("data/images/kolobok.bmp"); 
	cursor=LoadImage("data/gui_cursor.png"); 
	Coord CirclePos;
	Uint8 *keys;
	char fpss[10];
	CirclePos.SetX(2);
	CirclePos.SetY(2);
	
	Sound* sound=new Sound;
	sound->Load("1.wav");
	sound->Play(1, 100);
	bool playing=true;
	while(Running) 
	{
		SDL_GetMouseState(&mouseposx, &mouseposy);
		//OnCleanUp()
		SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));
		DrawIMGRect(image, CirclePos.GetRect() ,Screen);
		//OnRender()
		map.OnRender(Screen);
		m_pText->print_ttf(Screen, "SDL_ttf example", "data/courier.ttf", 1, clr, dest.GetRect(),false,false);
		m_pText->print_ttf(Screen,sfps , "data/courier.ttf", 0.3, clr2, dest2.GetRect(),true,true);
		DrawIMG(cursor, mouseposx,mouseposy, Screen);
		if(!sound->IsPlaying() && playing){
		playing=false;
		sound->UnLoad();
		}
		SDL_Flip(Screen);
		SDL_Event Event;
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
		if(keys[SDLK_UP]){ CirclePos.SetY(CirclePos.GetY()-0.05); }
		if(keys[SDLK_DOWN]){ CirclePos.SetY(CirclePos.GetY()+0.05); }
		if(keys[SDLK_LEFT]){ CirclePos.SetX(CirclePos.GetX()-0.05); }
		if(keys[SDLK_RIGHT]){ CirclePos.SetX(CirclePos.GetX()+0.05); }
		Frames++;
		
		{
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
