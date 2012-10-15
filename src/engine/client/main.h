#include "SDL.h"
#include <stdio.h>
#include <stdlib.h> 
class CMain
{
public:
	void Init();
	int main(int argc, char *argv[]);
	/*void DrawIMG(SDL_Surface *img, int x, int y);
	void DrawIMG(SDL_Surface *img, int x, int y, int w, int h, int sx, int sy);
	void DrawBG(void);
	void DrawScene(void);*/
private:
	int m_Posx;
	int m_Posy;

}
