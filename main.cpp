#include <SDL2/SDL.h>
#include <iostream>
#include "defs.h"
#include "structs.h"
#include "init.cpp"
#include "input.cpp"
#include "draw.cpp"
#include "common.h"

App app;

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));

	initSDL();

	atexit(cleanup);

	while (1)
	{
		prepareScene();

		doInput();

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}