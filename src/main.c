#include <stdio.h>
#include <string.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <hex_to_sdl_colour.h>
#include "config.h"

int main(int argc, char* argv[]) 
{
	SDL_Color backgroundColour;
	if (argc > 2)
	{
		backgroundColour = hexToSDL_Color(argv[1]);
		load_config();
	}
	else
	{
		puts("Usage: ./sticky_notes \"#FFFF88\" \"line1\" \"line2\" \"line3\"");
		return -1;
	}

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_Event event;
	SDL_Window * window = SDL_CreateWindow("sticky notes", window_width, window_height, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, NULL);
	TTF_TextEngine * textEngine = TTF_CreateRendererTextEngine(renderer);
	TTF_Text * textObject;
	TTF_Font * font = TTF_OpenFont(font_address, font_size);

	int running = 1;

    while (running) 
	{
		if (SDL_WaitEvent(&event))
		{
			if (event.key.key == SDLK_ESCAPE) {	running = 0; }
		}
		while(SDL_PollEvent(&event))
		{
			if (event.key.key == SDLK_ESCAPE) {	running = 0; }
		}

		SDL_SetRenderDrawColor(renderer, backgroundColour.r, backgroundColour.g, backgroundColour.b, backgroundColour.a);
		SDL_RenderClear(renderer);
		for (int i = 2, y = 0; i < argc; i++, y++)
		{
			textObject = TTF_CreateText(textEngine, font, argv[i], 0);
			TTF_SetTextColor(textObject, 0, 0, 0, 255);
			TTF_DrawRendererText(textObject, 10, 5 + (y * (font_size + 5)));
			TTF_DestroyText(textObject);
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
    }

    TTF_DestroyRendererTextEngine(textEngine);
	TTF_CloseFont(font);
    SDL_DestroyWindow(window);
	TTF_Quit();
    SDL_Quit();

    return 0;
}
