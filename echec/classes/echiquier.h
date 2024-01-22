class echiquier{
	
	public:
		echiquier(SDL_Renderer* renderer,SDL_Rect rect,SDL_Color face1,SDL_Color face2);
		~echiquier();
		void draw(SDL_Renderer* renderer,SDL_Color white,SDL_Color black);
		SDL_Color getface1();
		void setface1(SDL_Color color);
		SDL_Color getface2();
		void setface2(SDL_Color color);
		SDL_Rect getRect();
		void setRect(SDL_Rect rct);
		
	private:
		SDL_Color face1,face2;
		SDL_Rect rect;
	
	};
