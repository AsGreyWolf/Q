#ifndef _MAP_H_
#define _MAP_H_
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
class Map
{
    public:
    struct Tile{
    int x;
    int y;
    int tex;
    int mode;
    };
    Tile tiles[501];
    int Open(char* path);
    int Clear();
    void OnRender(SDL_Surface *img,SDL_Surface *Screen);
};
#endif
