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
int Coord::SetW(float v)
{
	width=640;
	height=640;
	w=v*width/16;
}
int Coord::SetH(float v)
{
	width=640;
	height=640;
	h=v*height/16;
}
float Coord::GetX()
{
	return x*16/width;
}
float Coord::GetY()
{
	return y*16/height;
}
float Coord::GetW()
{
	return 2*16/width;
}
float Coord::GetH()
{
	return h*16/height;
}
SDL_Rect Coord::GetRect()
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	return dest;
}
int localtopix(float v, bool height){
if(height){
return v*640/16;
}else{
return v*640/16;
}
}
int topoints(float v){
return v*(43+16-v);
}
int maptopix(float v, bool height){
if(height){
return v*640/16;
}else{
return v*640/16;
}
}


#endif
