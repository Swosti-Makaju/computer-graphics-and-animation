#include <graphics.h>
#include <conio.h>

int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // The "" is the path to the BGI folder

  
    // Draw a Rectangle
    setcolor(WHITE);  // Set the color to blue
    rectangle(100, 100, 500, 300);  // Draw a rectangle with top-left (100,100) and bottom-right (500,300)


    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}
