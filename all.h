#ifndef ALL_H
#define ALL_H

// init...
int createCanvas(int width, int height);
void background(int clr);
void update();

// draw ...
void fill(int r, int g, int b, int a);
void line(double x1, double y1, double x2, double y2);
void rect(int x, int y, int w, int h);


#endif