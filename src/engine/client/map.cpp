#ifndef _MAP_CPP_
#define _MAP_CPP_
#include "map.h"

int Map::Open(char* path){
Clear();
char a[1100]={0};
int str=1;
int simv=1;
int tile=1;
ifstream file(path);
file.getline(a,1000);
for(int i=0;i<1000;i++) {
	if(a[i]==':'){
	
	tiles[tile].mode=(a[i+1]-'0');
	//cout<<tiles[tile].mode;
	i++;
	}else if(a[i]==';'){
	simv++;
	//cout<<';';
	}else if(a[i]=='#'){
	simv=1;
	str++;
	//cout<<"\n";
	}
	else if(a[i]){
       tiles[tile].tex=(a[i]-'0');
       //cout<<tiles[tile].tex<<"x=";
       tiles[tile].x= simv;
       tiles[tile].y= str;
       // cout<<tiles[tile].x<<"y=";
       //  cout<<tiles[tile].y<<":";
   	}
   	tile++;
	}
	file.close();
	//cout<<"\n";
	return 1;
}
int Map::Clear(){
for(int i=0;i<300;i++) {
tiles[i].x= 0;
tiles[i].y= 0;
tiles[i].tex= 0;
tiles[i].mode= 0;
}
return 1;
}
void Map::OnRender(SDL_Surface *img,SDL_Surface *Screen){
	//Open("data/maps/first.m");
	for(int i=0;i<300;i++) {
		if(tiles[i].tex==1){
		
			SDL_Rect dest;
			dest.x=(tiles[i].x-1)*640/16;
			dest.y=(tiles[i].y-1)*640/16;
			//cout<<"x="<<dest.x<<" y="<<dest.y<<"\n";
			SDL_BlitSurface(img, NULL, Screen, &dest);
			}
		
	}
}
#endif
