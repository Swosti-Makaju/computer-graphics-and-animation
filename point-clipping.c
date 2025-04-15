#include <stdio.h>
#include <graphics.h>

int main() {
    int Xmin, Xmax, Ymin, Ymax;
    int x, y;
    
    printf("Enter the clipping window boundaries (Xmin Xmax Ymin Ymax): ");
    scanf("%d %d %d %d", &Xmin, &Xmax, &Ymin, &Ymax);

    printf("Enter the coordinates of the point (x y): ");
    scanf("%d %d", &x, &y);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(Xmin, Ymin, Xmax, Ymax);

    if (x > Xmin && x < Xmax && y > Ymin && y < Ymax) {
        setcolor(WHITE);
        outtextxy(20, 20, "Point is inside the clipping window.");
    } else {
        setcolor(WHITE);
        outtextxy(20, 20, "Point is outside the clipping window.");
    }

    setcolor(WHITE);
    circle(x, y, 3);
    floodfill(x, y, WHITE);

    getch(); 
    closegraph(); 

    return 0;
}
