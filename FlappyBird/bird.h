#ifndef __BIRD__
#define __BIRD__

typedef struct Bird
{
    char playerChar;
    int x;
    int y;
    } Bird;

void UpdateBird(Bird *playerBird, int _y, int mapH);
Bird CreateBird(int _x, int _y);
#endif