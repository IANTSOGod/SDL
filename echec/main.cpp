#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include "classes/echiquier.h"
#include "func/echiquier.cxx"

int main(int argc,char* argv[]){
	//Composantes SDL
	SDL_Window* window=NULL;
	SDL_Renderer* renderer=NULL;
	SDL_Color white={0,0,0,255};
	SDL_Color black={255,255,255,255};
	SDL_Color face1,face2;
	SDL_Rect rect ={100,100,100,100};
	
	//Initialisation SDL
	SDL_Init(SDL_INIT_VIDEO);
	
	//Creation fenetre
	window=SDL_CreateWindow("Echec",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1200,1000,SDL_WINDOW_SHOWN);
	renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	
	SDL_Surface* surface=IMG_Load("img/komi.png");
	SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,surface);
	
	//Creation echiquier
	echiquier* principale=new echiquier(renderer,rect,face1,face2);
	principale->draw(renderer,white,black);
	
	//rectangle de destination
	SDL_Rect dest=principale->getRect();
	dest.y=100;
	//copier le dessin dans le rectangle
	SDL_RenderCopy(renderer,texture,nullptr,&dest);
	 
	//Mise a jour de l'affichage
	SDL_RenderPresent(renderer);
	
	
	bool quit=false;
	SDL_Event e;
	
	while(!quit){
		while(SDL_PollEvent(&e)!=0){
			if(e.type==SDL_QUIT){
				quit=true;
			}
		}
	}
	//Fin de traitement
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
	}
