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
};
float localtogl(float v, bool height);
float maptogl(float v, bool height);
float pixtogl(int v, bool height);
int topoints(float v);
#endif
