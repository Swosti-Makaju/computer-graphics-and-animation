#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void drawBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1; 
    int sy = (y1 < y2) ? 1 : -1; 

    int err = dx - dy;

    while (1) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2) 
            break;

        int e2 = 2 * err;
        if (e2 > -dy) { 
            err -= dy; 
            x1 += sx; 
        }
        if (e2 < dx) { 
            err += dx; 
            y1 += sy; 
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int lines[8][4];  

    printf("Enter coordinates for 8 lines (x1 y1 x2 y2):\n");
    for (int i = 0; i < 8; i++) {
        printf("Line %d: ", i + 1);
        scanf("%d %d %d %d", &lines[i][0], &lines[i][1], &lines[i][2], &lines[i][3]);
    }

    for (int i = 0; i < 8; i++) {
        drawBresenham(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
    }

    printf("Press any key to exit...");
    getch();
    closegraph();
    return 0;
}



