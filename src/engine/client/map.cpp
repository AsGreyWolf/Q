#ifndef _MAP_CPP_
#define _MAP_CPP_
#include "map.h"

int Map::Open(char* path){
char a[1100];
int str=1;
int simv=1;
ifstream file(path);
file.getline(a,1000,"\n");
for(int i=0;i<1000;i++) {
	if(a[i]==':'){
	tiles[str][simv].mode=a[i+1];
	}else if(a[i]==';'){
	simv++;
	}else if(a[i]=='#'){
	simv=1;
	str++;
	}
	else{
       tiles[str][simv].x=simv;
       tiles[str][simv].y=str;
       tiles[str][simv].tex = atoi(&a[i]);
   	}
	}
}
int Map::Clear(){
for(int i=0;i<10;i++) {
for(int ii=0;ii<100;ii++) {
tiles[i][ii].x=0;
tiles[i][ii].y=0;
tiles[i][ii].tex=0;
tiles[i][ii].mode=0;
}
}
}
void Map::OnRender(SDL_Surface *img,SDL_Surface *Screen){
	for(int i=0;i<10;i++) {
		for(int ii=0;ii<100;ii++) {
		if(tiles[i][ii].tex==1){
			SDL_Rect dest;
			SDL_Rect dest.x=tiles[i][ii].x*16/640;
			SDL_Rect dest.y=tiles[i][ii].y*16/640;
			SDL_BlitSurface(img, NULL, screen, &dest);
			}
		}
	}
}
#endif
