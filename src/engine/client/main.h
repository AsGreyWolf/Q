#ifndef _MAIN_H_
#define _MAIN_H_  
#include "graphics.h"
#include <SDL.h> 
#include <GL/gl.h>
#include <GL/glu.h>
#include "textrender.h"
//#include "player.h"
#include "audio.h"
#include "sound.h"
#include "coords.h"
#include "map.h"

class mainmain
{	
public:
	mainmain();
	int Execute();
	bool Init();
	void Quit( int returnCode );
	int resizeWindow( int width, int height );		
	//class Graphics *m_pGraphics;
	class TextRender *m_pText;
private:
	SDL_Surface*    Screen;
	GLuint image;
	float timer;
	float lasttimer;
	bool Running;
};
#endif
