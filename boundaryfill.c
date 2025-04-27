#include <graphics.h>
#include <conio.h>
#include <dos.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int current = getpixel(x, y);
    if (current != boundaryColor && current != fillColor) {
        putpixel(x, y, fillColor);
        delay(0); // for animation effect
        boundaryFill(x + 1, y, fillColor, boundaryColor);  // right
        boundaryFill(x - 1, y, fillColor, boundaryColor);  // left
        boundaryFill(x, y + 1, fillColor, boundaryColor);  // down
        boundaryFill(x, y - 1, fillColor, boundaryColor);  // up
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // leave blank if using Dev C++

    // draw a rectangle as boundary
    rectangle(100, 100, 300, 200);
    
    int seedX = 150, seedY = 150;
    int fillColor = RED;
    int boundaryColor = WHITE;

    boundaryFill(seedX, seedY, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}
