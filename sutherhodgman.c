#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 20

typedef struct {
    float x, y;
} Point;

int inside(Point p, int edge, float boundary) {
    if (edge == 0) return p.x >= boundary; // Left
    if (edge == 1) return p.x <= boundary; // Right
    if (edge == 2) return p.y >= boundary; // Bottom
    return p.y <= boundary;                // Top
}

Point intersect(Point p1, Point p2, int edge, float boundary) {
    Point i;
    float m = 0;

    if (p1.x != p2.x)
        m = (p2.y - p1.y) / (p2.x - p1.x);

    if (edge == 0 || edge == 1) { // Left or Right
        i.x = boundary;
        i.y = p1.y + m * (boundary - p1.x);
    } else { // Top or Bottom
        if (p1.x != p2.x) {
            i.y = boundary;
            i.x = p1.x + (boundary - p1.y) / m;
        } else {
            i.x = p1.x;
            i.y = boundary;
        }
    }

    return i;
}

int clipPolygon(Point in[], int n, Point out[], int edge, float boundary) {
    Point s = in[n - 1];
    int m = 0;

    for (int i = 0; i < n; i++) {
        Point p = in[i];

        if (inside(p, edge, boundary)) {
            if (inside(s, edge, boundary)) {
                out[m++] = p;
            } else {
                out[m++] = intersect(s, p, edge, boundary);
                out[m++] = p;
            }
        } else {
            if (inside(s, edge, boundary)) {
                out[m++] = intersect(s, p, edge, boundary);
            }
        }
        s = p;
    }

    return m;
}

void drawPolygon(Point p[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(p[i].x, p[i].y, p[(i + 1) % n].x, p[(i + 1) % n].y);
    }
}

int main() {
    char choice[10];
    printf("Type 'before' to see original polygon only.\n");
    printf("Type 'after' to see clipped polygon only.\n");
    scanf("%s", choice);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    cleardevice();

    // Clipping window
    float xmin = 100, ymin = 100, xmax = 300, ymax = 300;
    setcolor(BLUE);
    rectangle(xmin, ymin, xmax, ymax);

    // Define the polygon
    Point polygon[MAX] = {
        {80, 120}, {120, 80}, {200, 90}, {250, 150}, {150, 250}, {100, 200}
    };
    int n = 6;

    // Arrays for intermediate steps
    Point temp1[MAX], temp2[MAX];

    if (strcmp(choice, "before") == 0) {
        drawPolygon(polygon, n, BLACK);
        outtextxy(10, 10, "Original Polygon (before)");
    } else if (strcmp(choice, "after") == 0) {
        int vertices = n;
        vertices = clipPolygon(polygon, vertices, temp1, 0, xmin); // Left
        vertices = clipPolygon(temp1, vertices, temp2, 1, xmax);   // Right
        vertices = clipPolygon(temp2, vertices, temp1, 2, ymin);   // Bottom
        vertices = clipPolygon(temp1, vertices, temp2, 3, ymax);   // Top

        drawPolygon(temp2, vertices, BLACK);
        outtextxy(10, 10, "Clipped Polygon (after)");
    } else {
        outtextxy(10, 10, "Invalid input. Type 'before' or 'after'.");
    }

    getch();
    closegraph();
    return 0;
}
