
echiquier::echiquier(SDL_Renderer* renderer,SDL_Rect rect,SDL_Color face1,SDL_Color face2):rect(rect),face1(face1),face2(face2){
	SDL_Surface* surface=IMG_Load("img/back.png");
	SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,surface);
	SDL_Rect dest={0,0,1200,1000};
	//copier le dessin dans le rectangle
	SDL_RenderCopy(renderer,texture,nullptr,&dest);

	}
	
echiquier::~echiquier(){
	
	}
	
void echiquier::draw(SDL_Renderer* renderer,SDL_Color white,SDL_Color black){
	
	for(int a=1;a<9;a++,rect.y+=100){
	
		if(a%2==0){
			face1=white;
			face2=black;
		}
		else{
			face1=black;
			face2=white;
			}
	
		for (int i=1;i<11;i++,rect.x+=100){
			if(i%2==0){
				SDL_SetRenderDrawColor(renderer,face1.r,face1.g,face1.b,face1.a);
				SDL_RenderFillRect(renderer,&rect);
			}
			else{
				SDL_SetRenderDrawColor(renderer,face2.r,face2.g,face2.b,face2.a);
				SDL_RenderFillRect(renderer,&rect);
			}
		}
		rect.x=100;	
	
	}
	
	}

SDL_Color echiquier::getface1(){
	return face1;
	}
	
void echiquier::setface1(SDL_Color color){
	face1=color;
	}
	
SDL_Color echiquier::getface2(){
	return face2;
	}
	
void echiquier::setface2(SDL_Color color){
	face2=color;
	}
	
SDL_Rect echiquier::getRect(){
	return rect;
	}
	
void echiquier::setRect(SDL_Rect rct){
	rect=rct;
	}
