#ifndef __BIRD__
#define __BIRD__

extern struct bird
{
    char playerChar;
    int x;
    int y;
    };
 typedef struct bird Bird;

void UpdateBird(Bird *playerBird, int _y, int mapH);
Bird CreateBird(int _x, int _y);
#endif