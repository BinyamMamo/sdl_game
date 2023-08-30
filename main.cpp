#include <SDL2/SDL.h>
#include <iostream>

// using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;

void rect(int x, int y, int w, int h)
{
    for (int i = x; i < x+w; i++)
    {
        for (int j = y; j < y+h; j++)
        {
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
}
int main()
{
    int a;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 100, 0, 150, 25);
    for (int i = 0; i < 640; i++)
    {
        for (int j = 0; j < 480; j++)
        {
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    rect(100, 300, 100, 100);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    rect(200, 200, 100, 100);

    SDL_RenderPresent(renderer);
    SDL_Rect rect = {100, 100, 100, 100};
	SDL_SetRenderDrawColor(renderer, 255, 0, 10, 255);
	SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
    // SDL_RenderDelay(3000);
    std::cin >> a;
    return 0;
}

