#ifndef _MAP_H_
#define _MAP_H_
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include <GL/glu.h>
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
    Tile tiles[50001];
    GLuint imgs[50001];
    bool loadedimg[50001];
    int Open(char* path);
    int Clear();
    void OnRender(SDL_Surface *Screen, float camerax, float cameray, float cameraw, float camerah);
};
#endif
