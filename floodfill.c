#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int oldColor, int newColor) {
    int current = getpixel(x, y);
    if (current == oldColor) {
        putpixel(x, y, newColor);
        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw closed boundary (a rectangle)
    rectangle(100, 100, 200, 200);

    // Set boundary color (WHITE) and fill color (RED)
    int x = 150, y = 150; // seed point inside the rectangle
    int oldColor = BLACK; // background
    int newColor = WHITE;

    floodFill(x, y, oldColor, newColor);


    getch();
    closegraph();
    return 0;
}
