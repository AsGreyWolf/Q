#ifndef _MAIN_H_
#define _MAIN_H_  
#include "graphics.h"
#include <SDL.h>
#include "textrender.h"
#include "player.h"
class mainmain 
{
    public:
      mainmain();
      int Execute();
	bool Init();
	void Quit( int returnCode );
	void Cleanup();
	Player *m_pPlayer;		
	Graphics *m_pGraphics;
	TextRender *m_pText;
    private:
	SDL_Surface*    Screen;
	SDL_Surface *image;
      bool Running;
};
#endif
