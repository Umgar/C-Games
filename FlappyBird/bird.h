#ifndef __BIRD__
#define __BIRD__

extern struct Bird
{
    char playerChar;
    int x;
    int y;
};


void UpdateBird(struct Bird *playerBird, int _y, int mapH);
struct Bird CreateBird(int _x, int _y);
#endif