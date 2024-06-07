#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a circle
    circle(200, 200, 50);

    // Draw a rectangle
    rectangle(100, 100, 200, 200);

    getch();
    closegraph();

    return 0;
}