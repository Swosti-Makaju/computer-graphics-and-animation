#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void drawDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
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
        drawDDA(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
    }
    
    getch();
    closegraph();
    return 0;
}
