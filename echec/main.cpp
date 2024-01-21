#include <SDL2/SDL.h>
#include <cstdio>
#include <cstdlib>
#include "echiquier.h"
#include "echiquier.cxx"

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
	
	//Creation echiquier
	echiquier* principale=new echiquier(renderer,rect,face1,face2);
	principale->draw(renderer,white,black);
	
	//Mise a jour de l'affichage
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	
	//Fin de traitement
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
	}
