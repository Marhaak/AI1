#include "Graphix.h"
using namespace std;

Graphix::Graphix() {
	InitSDL();
}

void Graphix::Draw(int _x, int _y, int _i) {

	//Put things on buffer
	ApplySurface(_x, _y, textureSheet[_i], renderer);
}
	
bool Graphix::InitSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		cout << SDL_GetError() << endl;
		return false;
	}

	// Creating the window
	window = SDL_CreateWindow("Vacuum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, NULL);
    if (window == nullptr){
        cout << SDL_GetError() << "\n";
		return false;
    }

	// Creating the renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        std::cout << SDL_GetError() << std::endl;
		return false;
    }

	textureSheet[0] = loadImage("ground.png");
	textureSheet[1] = loadImage("dirt.png");
	textureSheet[2] = loadImage("wall.png");
	textureSheet[3] = loadImage("vacuum.png");
	// Everything went ok
	return true;
}

Graphix::~Graphix() {
	SDL_DestroyTexture(textureSheet[0]);
	SDL_DestroyTexture(textureSheet[1]);
	SDL_DestroyTexture(textureSheet[2]);
	SDL_DestroyTexture(textureSheet[3]);
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphix::ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend) {
	SDL_Rect pos;
    pos.x = x;
    pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h); 
    SDL_RenderCopy(rend, tex, NULL, &pos);
}

SDL_Texture* Graphix::loadImage(string _file) {
	SDL_Texture* tex = nullptr;
	tex = IMG_LoadTexture(renderer, _file.c_str());
    if (tex == nullptr) {
		cout<<"Failed to load image: "<< _file.c_str()<<" "<<  IMG_GetError();
		cin.get();
	}
	
    return tex;
}

SDL_Renderer* Graphix::Renderer() {
	return renderer;
}

//bool Graphix::Event(_event) {
//
//
//}