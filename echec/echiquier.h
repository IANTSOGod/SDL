class echiquier{
	
	public:
		echiquier(SDL_Renderer* renderer,SDL_Rect rect,SDL_Color face1,SDL_Color face2);
		~echiquier();
		void draw(SDL_Renderer* renderer,SDL_Color white,SDL_Color black);
	private:
		SDL_Color face1,face2;
		SDL_Rect rect ={100,100,100,100};
	
	};
