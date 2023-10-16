#include <SDL2/SDL.h>
#include <iostream>
#include "defs.h"
#include "common.h"

extern App app;

void cleanup(void)
{
	SDL_DestroyRenderer(app.renderer);

	SDL_DestroyWindow(app.window);

	SDL_Quit();
}


void initSDL(void)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout<<"Couldn't initialize SDL:"<< SDL_GetError();
		exit(1);
	}

	app.window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
		std::cout<<"Failed to open window:"<< SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError();
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		std::cout<<"Failed to create renderer:" << SDL_GetError();
		exit(1);
	}
}

