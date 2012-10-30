#ifndef _MAP_CPP_
#define _MAP_CPP_
#include "map.h"
#include "graphics.h"
#include "coords.h"
int Map::Open(char* path,char* name){
Clear();
char a[100100]={0};
int str=1;
int simv=1;
int tile=1;
char texfolder[112];
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
       sprintf(texfolder,"data/maps/%s/%d.png",name,tiles[tile].tex);
      	imgs[tiles[tile].tex]=LoadImage(texfolder,0);
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
void Map::OnRender(SDL_Surface *Screen, float camerax, float cameray, float cameraw, float camerah){
	//Open("data/maps/first.m");
	for(int i=0;i<50000;i++) {
		if(tiles[i].tex!=0){
		
			float x=-camerax+cameraw/2+maptogl(tiles[i].x,false);
			float y=-cameray+camerah/2+maptogl(tiles[i].y,true);
			float w=maptogl(1,false);
			float h=maptogl(1,true);
			if(x>maptogl(-1,false) && x<maptogl(16,false) && y>maptogl(-1,true) && y<maptogl(16,true))
			//cout<<"x="<<dest.x<<" y="<<dest.y<<"\n";
			DrawIMG(imgs[tiles[i].tex], x,y,w,h);
			}
		
	}
}
#endif
