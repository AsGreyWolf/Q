#ifndef _MAIN_CPP_
#define _MAIN_CPP_ 
#include "main.h"
#include <sstream>
using std::stringstream;
#include <iostream>

int mainmain::resizeWindow( int width, int height )
{
    GLfloat ratio;
 
    /* Protect against a divide by zero */
    if ( height == 0 )
	height = 1;

    ratio = ( GLfloat )width / ( GLfloat )height;

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLint )width, ( GLint )height );

    /*
     * change to the projection matrix and set
     * our viewing volume.
     */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( ); 

    return 1;
}
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
	lasttimer=0;
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		fprintf( stderr, "SDL initialization failed: %s\n",
		SDL_GetError( ) );
		Quit( 1 );
	}
	
	Screen = SDL_SetVideoMode(640,640,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_OPENGL|SDL_GL_DOUBLEBUFFER|SDL_HWPALETTE); 
	
	if ( !Screen )
	{
		fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
		Quit( 1 );
	}
	SDL_WM_SetCaption("ololo game","v1");
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	 glEnable( GL_TEXTURE_2D );

    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

    /* Depth buffer setup */
    glClearDepth( 1.0f );

    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );

    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      resizeWindow(640,640);
	//Init()    	
	//glTranslatef(-6.0f,0.0f,-6.0f);
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
	GLuint cursor;
	image=LoadImage("data/images/kolobok.bmp",1); 
	cursor=LoadImage("data/gui_cursor.png",0); 
	Coord CirclePos;
	Coord Camera;
	Uint8 *keys;
	char fpss[10];
	CirclePos.SetX(2);
	CirclePos.SetY(2);
	CirclePos.SetW(2);
	CirclePos.SetH(2);
	Camera.SetW(16);
	Camera.SetH(16);
	Camera.SetX(8);
	Camera.SetY(8);
	Sound* sound=new Sound;
	sound->Load("1.wav");
	sound->Play(1, 100);
	bool playing=true;
	 //glTranslatef(-1.5f,0.0f,-6.0f);  
	while(Running) 
	{
		SDL_GetMouseState(&mouseposx, &mouseposy);
		//OnCleanUp()
		//SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
              // очистка Экрана и буфера глубины
        	glLoadIdentity();
              // Сброс просмотра
              glTranslatef( -1.0f, 1.0f, -3.4f );
		DrawIMG(image, CirclePos.x,CirclePos.y,CirclePos.w,CirclePos.h);
		//OnRender()
		map.OnRender(Screen,Camera.x,Camera.y,Camera.w,Camera.h);
		m_pText->print_ttf("SDL_ttf example", "data/courier.ttf", 1, clr, dest.x, dest.y,false,false);
		m_pText->print_ttf(sfps , "data/courier.ttf", 0.3, clr2, dest2.x, dest2.y,true,true);
		DrawIMG(cursor, pixtogl(mouseposx,false),pixtogl(mouseposy,true),localtogl(1, false),localtogl(1, true) );
		SDL_GL_SwapBuffers( );
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
		if(keys[SDLK_UP]){ CirclePos.SetY(CirclePos.GetY()-(timer-lasttimer)*5);
		 	Camera.SetY(Camera.GetY()-(timer-lasttimer)*5); }
		if(keys[SDLK_DOWN]){ CirclePos.SetY(CirclePos.GetY()+(timer-lasttimer)*5);
		 	Camera.SetY(Camera.GetY()+(timer-lasttimer)*5); }
		if(keys[SDLK_LEFT]){ CirclePos.SetX(CirclePos.GetX()-(timer-lasttimer)*5);
		 	Camera.SetX(Camera.GetX()-(timer-lasttimer)*5); }
		if(keys[SDLK_RIGHT]){ CirclePos.SetX(CirclePos.GetX()+(timer-lasttimer)*5);
		 	Camera.SetX(Camera.GetX()+(timer-lasttimer)*5); }
		Frames++;
		
		{
			int t = SDL_GetTicks();
			lasttimer=timer;
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
