#ifndef _COORDS_CPP_
#define _COORDS_CPP_  
#include "coords.h"

int Coord::SetX(float v)
{
	x=v/8*1.0f;
}
int Coord::SetY(float v)
{
	y=v/8*1.0f;
}
int Coord::SetW(float v)
{
	w=v/8*1.0f;
}
int Coord::SetH(float v)
{
	h=v/8*1.0f;
}
float Coord::GetX()
{
	return x*8/1.0f;
}
float Coord::GetY()
{
	return y*8/1.0f;
}
float Coord::GetW()
{
	return w*8/1.0f;
}
float Coord::GetH()
{
	return h*8/1.0f;
}
float localtogl(float v, bool height){
if(height){
return v/8*1.0f;
}else{
return v/8*1.0f;
}
}
int topoints(float v){
return v*(43+16-v);
}
float maptogl(float v, bool height){
if(height){
return v/8*1.0f;
}else{
return v/8*1.0f;
}
}
float pixtogl(int v, bool height){
if(height){
return (float)v/320*1.0f;
}else{
return (float)v/320*1.0f;
}
}


#endif
