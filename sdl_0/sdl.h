#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <string.h>


class Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int WINDOW_WIDTH, WINDOW_HEIGHT;
	std::string WINDOW_TITLE;
	bool NO_FILL = false;

	public:
		Game(std::string title, int w, int h);
		void background(int clr);
		void fill(int r, int g, int b, int a);
		//draw shapes
		void line(double, double, double, double);
		void rect(int, int, int, int);
		//keep da loop
		void update();
		int quit();
		// getters
		int width();
		int height();
		// setters
		void nofill();
		// testing
		void print(std::string);

};

#endif
