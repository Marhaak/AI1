#pragma once
#include "Include.h"


class Graphix {

private:
	SDL_Texture* textureSheet[3];		// Array with the textures
	SDL_Window*   window;				// The window
	SDL_Renderer* renderer;				// The renderer
public:
	Graphix();
	void Draw(int _x, int _y, int _i);
	bool InitSDL();
	SDL_Texture* loadImage(std::string _file);
	void ApplySurface(int _x, int _y, SDL_Texture* _tex, SDL_Renderer* _rend);
	~Graphix();
	SDL_Renderer* Renderer();
	bool Event(SDL_Event* _event);
};

