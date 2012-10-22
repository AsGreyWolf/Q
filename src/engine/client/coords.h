#ifndef _COORDS_H_
#define _COORDS_H_  
#include "SDL/SDL.h"

class Coord
{
public:
	int SetX(float v);
	int SetY(float v);
	float GetX();
	float GetY();	
	int GetPixX();
	int GetPixY();
	float x;
	float y;
	SDL_Rect GetRect();
private:
	int width;
	int height;
};
#endif
