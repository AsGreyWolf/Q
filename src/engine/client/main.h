#ifndef _MAIN_H_
#define _MAIN_H_  
#include "graphics.h"
#include <SDL.h> 
#include "textrender.h"
#include "player.h"
#include "audio.h"
#include "sound.h"

class mainmain 
{
    public:
      mainmain();
      int Execute();
	bool Init();
	void Quit( int returnCode );
	Player *m_pPlayer;		
	Graphics *m_pGraphics;
	TextRender *m_pText;
	
    private:
	SDL_Surface*    Screen;
	SDL_Surface *image;
	float timer;
      bool Running;
};
#endif
