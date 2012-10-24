#ifndef _COORDS_H_
#define _COORDS_H_  
#include "SDL/SDL.h"

class Coord
{
public:
	int SetX(float v);
	int SetY(float v);
	int SetW(float v);
	int SetH(float v);
	float GetX();
	float GetY();
	float GetW();
	float GetH();	
	float x;
	float y;
	float w;
	float h;
	SDL_Rect GetRect();
private:
	int width;
	int height;
};
int localtopix(float v, bool height);
int maptopix(float v, bool height);
int topoints(float v);
#endif
