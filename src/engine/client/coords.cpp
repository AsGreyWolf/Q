#ifndef _COORDS_CPP_
#define _COORDS_CPP_  
#include "coords.h"

int Coord::SetX(float v)
{
	width=640;
	height=640;
	x=v*width/16;
}
int Coord::SetY(float v)
{
	width=640;
	height=640;
	y=v*height/16;
}
float Coord::GetX()
{
	return x*16/width;
}
float Coord::GetY()
{
	return y*16/height;
}	
int Coord::GetPixX()
{
	return x;
}
int Coord::GetPixY()
{
	return y;
}
SDL_Rect Coord::GetRect()
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	return dest;
}


#endif
