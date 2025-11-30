#include <stdio.h>
#include <hex_to_sdl_colour.h>

SDL_Color hexToSDL_Color(const char * hexColour)
{
	unsigned int r, g, b;
	int result = sscanf(hexColour, "#%02x%02x%02x", &r, &g, &b);
	if (result == 3)
	{
		return (SDL_Color){r, g, b, 255};
	}
	return (SDL_Color){255, 255, 136, 255};
}
