#include "main.h"
#include "sdl.h"

Game game("Hi", 640, 480);

int main() {
	setup();
	while(true) {
		draw();
	}
	return 0;
}

void setup() {
	game.print("Hello World");
	game.background(50);
}

void draw() {
	game.fill(200, 0, 0, 200);
	game.rect(100, 100, 100, 100);
	game.update();
	// std::cout << game.quit();
	game.quit();
}
