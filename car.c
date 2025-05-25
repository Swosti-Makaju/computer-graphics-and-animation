#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void drawCar(int x, int y) {
    setcolor(BLUE);

    // Car body
    rectangle(x, y, x + 100, y + 20);
    rectangle(x + 20, y - 20, x + 80, y);

    // Wheels
    setcolor(RED);
    circle(x + 25, y + 25, 7);
    circle(x + 75, y + 25, 7);
    floodfill(x + 25, y + 25, RED);
    floodfill(x + 75, y + 25, RED);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(WHITE);
    cleardevice();

    int x = 0, y = 200;

    while (!kbhit()) {
        cleardevice();
        setbkcolor(WHITE); // Maintain white background
        drawCar(x, y);
        delay(50);
        x += 5;

        // Reset to left after it exits the screen
        if (x > getmaxx()) {
            x = -100;
        }
    }

    getch();
    closegraph();
    return 0;
}
