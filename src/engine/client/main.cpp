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
    /* clean up the window */
    SDL_Quit( );
    m_pText->TextRender_Exit();
    /* and exit appropriately */
    exit( returnCode );
}
bool mainmain::Init() 
{
	int videoFlags;
    /* this holds some info about our display */
    const SDL_VideoInfo *videoInfo;

    /* initialize SDL */

    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
	    fprintf( stderr, "SDL initialization failed: %s\n",
		     SDL_GetError( ) );
	    Quit( 1 );
	}

    /* Fetch the video info */
    videoInfo = SDL_GetVideoInfo( );

    if ( !videoInfo )
	{
	    fprintf( stderr, "Video query failed: %s\n",
		     SDL_GetError( ) );
	    Quit( 1 );
	}

    /* the flags to pass to SDL_SetVideoMode */
 videoFlags = SDL_RESIZABLE;    
videoFlags  |= SDL_OPENGL;          /* Enable OpenGL in SDL */
    videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
          /* Enable window resizing */
	videoFlags |= SDL_DOUBLEBUF;

    /* This checks to see if surfaces can be stored in memory */
    if ( videoInfo->hw_available )
	videoFlags |= SDL_HWSURFACE;
    else
	videoFlags |= SDL_SWSURFACE;

    /* This checks if hardware blits can be done */
    if ( videoInfo->blit_hw )
	videoFlags |= SDL_HWACCEL;

    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* get a SDL surface */
    Screen = SDL_SetVideoMode(640,480,32,videoFlags); 

    /* Verify there is a surface */
    if ( !Screen )
	{
	    fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
	    Quit( 1 );
	}

    /* initialize OpenGL */
    /* Load in the texture */
    	SDL_WM_SetCaption("ololo game","v1");
	return true;
}
int mainmain::Execute()
{
	static GLint Frames = 0;
	static GLint T0     = 0;
	if(Init() == false && Running == false ) 
		 return -1;
	    	
	if(m_pGraphics->Init() == 0) 
		 return -1;
	    
	 if(m_pText->Init() == 0 && Running == false )
		return -1;

 		Running = true;
		SDL_Color clr;
 		SDL_Rect dest;
		clr.r = 255;
		clr.g = 255;
		clr.b = 0;
		dest.x = 80;
		dest.y = 250;
		SDL_Color clr2;
 		SDL_Rect dest2;
		clr2.r = 255;
		clr2.g = 255;
		clr2.b = 255;
		dest2.x = 0;
		dest2.y = 0;
		stringstream iostr;
		
		char sfps[5];
		iostr<<0.0;
		iostr>>sfps;
 		//SDL_Surface* sFont;
 		//sFont = m_pText->LoadFont("font.png");
 		//m_pText->DrawText(sFont, 20, 150, "BITMAP FONT EXAMPLE", Screen);
		//SDL_Flip(Screen);
	    while(Running) {
		 glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		 //m_pGraphics->drawGLScene( );

		 m_pText->print_ttf( "SDL_ttf example", "data/courier.ttf", 46, clr, dest);
		m_pText->print_ttf(sfps , "data/courier.ttf", 15, clr2, dest2);
		
		 SDL_GL_SwapBuffers( );
		 SDL_Event Event;
		 while(SDL_PollEvent(&Event)) {
		       if (Event.type == SDL_QUIT){ 
      				Running = false;
     			}	
		 }
	Frames++;
    {
	GLint t = SDL_GetTicks();
	if (t - T0 >= 1000) {
	    GLfloat seconds = (t - T0) / 1000.0;
	    GLfloat fps = Frames / seconds;
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
