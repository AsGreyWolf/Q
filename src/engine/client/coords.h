#ifndef _COORDS_H_
#define _COORDS_H_  
# ifdef __gnu_linux__  

#include <include/lin_x64/SDL.h>

# else
#include <include/win_32/SDL.h>
# endif

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
