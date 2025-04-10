#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void symmetry(int x, int y, int xc, int yc) {
    putpixel(x + xc, y + yc, WHITE);   
    putpixel(-x + xc, y + yc, WHITE);  
    putpixel(x + xc, -y + yc, WHITE);  
    putpixel(-x + xc, -y + yc, WHITE);
    putpixel(y + xc, x + yc, WHITE); 
    putpixel(-y + xc, x + yc, WHITE);  
    putpixel(y + xc, -x + yc, WHITE); 
    putpixel(-y + xc, -x + yc, WHITE); 
}

int main() {
    int gd = DETECT, gm, xc, yc, r, x, y, p;
    initgraph(&gd, &gm, NULL);

    printf("Enter the center of circle: ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the radius of circle: ");
    scanf("%d", &r);
    
    x = 0;
    y = r;
    symmetry(x, y, xc, yc);  

    p = 1 - r; 

    // Midpoint circle drawing algorithm
    do {
        if (p < 0) {
            x = x + 1;
            p = p + 2 * x + 1;  
        } else {
            x = x + 1;
            y = y - 1;
            p = p + 2 * x - 2 * y + 1;  
        }

        symmetry(x, y, xc, yc); 

    } while (x < y); 

    getch();
    closegraph();
    return 0;
}
