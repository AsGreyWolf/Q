#ifndef _MAIN_CPP_
#define _MAIN_CPP_ 
#include "main.h"

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
    videoFlags  = SDL_OPENGL;          /* Enable OpenGL in SDL */
    videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    videoFlags |= SDL_RESIZABLE;       /* Enable window resizing */

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
    Screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
				videoFlags );

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
	if(Init() == false && Running == false ) 
		 return -1;
	    	
	//if(m_pGraphics->Init() == 0) 
	//	 return -1;
	    
	 if(m_pText->Init() == 0 && Running == false )
		return -1;
 	Running = true;
		 SDL_Color clr = {255,50,40,100};
		 SDL_Rect dest = {80, 120,0,0};
m_pText->print_ttf(Screen, "SDL_ttf example", "data/courier.ttf", 46, clr, dest);
	SDL_Flip(Screen);

	    while(Running) {
		//m_pGraphics->drawGLScene( );

		 
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

	
	return main0.Execute();
}
void mainmain::Cleanup()
{
	SDL_Quit();
	m_pText->TextRender_Exit();
}
#endif
