#include "all.h"
#include <iostream>
#include <SDL2/SDL.h>

SDL_Window* window;
SDL_Renderer* renderer;

void background(int clr)
{
	SDL_SetRenderDrawColor(renderer, clr, 0, 0, 100);
	SDL_RenderClear(renderer);
}

void fill(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
void line(double x1, double y1, double x2, double y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void update()
{
	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN)
			{
				quit = true;
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// Quit SDL2
	SDL_Quit();
}

void rect(int x, int y, int w, int h)
{
	SDL_Rect rect = {x, y, w, h};
	SDL_SetRenderDrawColor(renderer, 255, 0, 10, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

int createCanvas(int width, int height)
{
	const int WINDOW_WIDTH = width;
	const int WINDOW_HEIGHT = height;
	// Initialize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	// Create a window
	window = SDL_CreateWindow("Drawing Shapes with SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	// Create a renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	return 1;
}
