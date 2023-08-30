#include "sdl.h"

Game::Game(std::string title, int w, int h)
{
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;
	WINDOW_TITLE = title;
	// Initialize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit;
	}

	// Create a window
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit;
	}

	// Create a renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		exit;
	}
}

// clear
void Game::background(int clr)
{																												// todo: add 1 param, 2 param, 3 param and 4 param
	SDL_SetRenderDrawColor(renderer, clr, clr, clr, 100); // equivalent to fill
	SDL_RenderClear(renderer);														// is equivalent to background()
}

void Game::fill(int r, int g, int b, int a)
{ // todo: add 1 param, 2 param, 3 param and 4 param
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	NO_FILL = false;
}

// getters
int Game::width() { return this->WINDOW_WIDTH; }
int Game::height() { return this->WINDOW_HEIGHT; }

void Game::update()
{
	SDL_RenderPresent(renderer); // this is the real UPDATE
}

int Game::quit()
{
	bool quiting = false;
	SDL_Event e;
	if (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN)
		{
			quiting = true;
		}
	}

	if (quiting) {
		std::cout << "quiting";
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);

		// Quit SDL2
		SDL_Quit();
		return 1;
	}
	return 0;
}

void Game::rect(int x, int y, int w, int h)
{
	SDL_Rect rect = {x, y, w, h};
	if (NO_FILL)
		SDL_RenderDrawRect(renderer, &rect);
	else
		SDL_RenderFillRect(renderer, &rect);
}

void Game::line(double x1, double y1, double x2, double y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Game::print(std::string str)
{
	std::cout << str << std::endl;
}

// setter
void Game::nofill() { NO_FILL = true; }