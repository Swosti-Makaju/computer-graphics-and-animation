#include <graphics.h>
#include <stdio.h>
#include <math.h>

#define MAX 20

typedef struct {
    float x, y;
} Point;

void drawPolygon(Point p[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(p[i].x, p[i].y, p[(i + 1) % n].x, p[(i + 1) % n].y);
    }
}

void translate(Point in[], Point out[], int n, float tx, float ty) {
    for (int i = 0; i < n; i++) {
        out[i].x = in[i].x + tx;
        out[i].y = in[i].y + ty;
    }
}

void scale(Point in[], Point out[], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        out[i].x = in[i].x * sx;
        out[i].y = in[i].y * sy;
    }
}

void rotate(Point in[], Point out[], int n, float angle_deg) {
    float angle = angle_deg * M_PI / 180.0;
    for (int i = 0; i < n; i++) {
        out[i].x = in[i].x * cos(angle) - in[i].y * sin(angle);
        out[i].y = in[i].x * sin(angle) + in[i].y * cos(angle);
    }
}

void reflect(Point in[], Point out[], int n, int axis) {
    for (int i = 0; i < n; i++) {
        if (axis == 1) { // x-axis
            out[i].x = in[i].x;
            out[i].y = -in[i].y;
        } else if (axis == 2) { // y-axis
            out[i].x = -in[i].x;
            out[i].y = in[i].y;
        } else { // origin
            out[i].x = -in[i].x;
            out[i].y = -in[i].y;
        }
    }
}

void shear(Point in[], Point out[], int n, float shx, float shy) {
    for (int i = 0; i < n; i++) {
        out[i].x = in[i].x + shx * in[i].y;
        out[i].y = in[i].y + shy * in[i].x;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(WHITE);
    cleardevice();

    Point polygon[MAX], transformed[MAX];
    int n, choice, axis;
    float tx, ty, sx, sy, angle, shx, shy;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter coordinates of the polygon:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &polygon[i].x, &polygon[i].y);
    }

    printf("\nChoose transformation:\n");
    printf("1. Translation\n2. Scaling\n3. Rotation\n4. Reflection\n5. Shearing\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter tx and ty: ");
            scanf("%f %f", &tx, &ty);
            translate(polygon, transformed, n, tx, ty);
            break;
        case 2:
            printf("Enter sx and sy: ");
            scanf("%f %f", &sx, &sy);
            scale(polygon, transformed, n, sx, sy);
            break;
        case 3:
            printf("Enter angle in degrees: ");
            scanf("%f", &angle);
            rotate(polygon, transformed, n, angle);
            break;
        case 4:
            printf("Reflect about:\n1. X-axis\n2. Y-axis\n3. Origin\nEnter choice: ");
            scanf("%d", &axis);
            reflect(polygon, transformed, n, axis);
            break;
        case 5:
            printf("Enter shear factors shx and shy: ");
            scanf("%f %f", &shx, &shy);
            shear(polygon, transformed, n, shx, shy);
            break;
        default:
            printf("Invalid choice!\n");
            closegraph();
            return 0;
    }

    drawPolygon(polygon, n, BLACK);     // Original
    drawPolygon(transformed, n, GREEN); // Transformed

    getch();
    closegraph();
    return 0;
}
