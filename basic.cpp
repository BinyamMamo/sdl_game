#include <iostream>
#include "all.h"

using namespace std;

int main() {
	createCanvas(640, 480);
	background(200);
	cout << "hi" << endl;
	// fill(200, 0, 0, 200);
	rect(100, 100, 200, 200);
	update();
}
