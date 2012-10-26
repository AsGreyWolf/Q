#ifndef _MAP_CPP_
#define _MAP_CPP_
#include "map.h"
#include "graphics.h"
#include "coords.h"
int Map::Open(char* path){
Clear();
char a[100100]={0};
int str=1;
int simv=1;
int tile=1;
char texfolder[112];
const char *name=basename(path);
ifstream file(path);
file.getline(a,100000);
for(int i=0;i<100000;i++) {
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
	tile++;
       tiles[tile].tex=(a[i]-'0');
       if(!loadedimg[tiles[tile].tex]){
       sprintf(texfolder,"data/maps/%sap/%d.png",name,tiles[tile].tex);
      	imgs[tiles[tile].tex]=LoadImage(texfolder);
      	cout<<tiles[tile].tex<<" texture loaded:path "<< texfolder<<"\n";
      	loadedimg[tiles[tile].tex]=true;
      	}
       //cout<<tiles[tile].tex<<"x=";
       tiles[tile].x= simv-1;
       tiles[tile].y= str-1;
       // cout<<tiles[tile].x<<"y=";
       //  cout<<tiles[tile].y<<":";
   	}
	}
	file.close();
	//cout<<"\n";
	return 1;
}
int Map::Clear(){
for(int i=0;i<50000;i++) {
tiles[i].x= 0;
tiles[i].y= 0;
loadedimg[tiles[i].tex]=false;
tiles[i].tex= 0;
tiles[i].mode= 0;
}
return 1;
}
void Map::OnRender(SDL_Surface *Screen, SDL_Rect Camera){
	//Open("data/maps/first.m");
	for(int i=0;i<50000;i++) {
		if(tiles[i].tex!=0){
		
			SDL_Rect dest;
			dest.x=-Camera.x+640/2+maptopix(tiles[i].x,false);
			dest.y=-Camera.y+640/2+maptopix(tiles[i].y,true);
			if(dest.x>maptopix(-1,false) && dest.x<maptopix(16,false) && dest.y>maptopix(-1,true) && dest.y<maptopix(16,true))
			//cout<<"x="<<dest.x<<" y="<<dest.y<<"\n";
			DrawIMGRect(imgs[tiles[i].tex], dest,  Screen);
			}
		
	}
}
#endif
