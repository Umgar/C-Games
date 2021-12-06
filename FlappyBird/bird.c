#include <stdlib.h>

struct Bird
{
    char playerChar;
    int x;
    int y;
};

void UpdateBird(struct Bird *playerBird, int _y)
{
    ChangeCell(playerBird->y, playerBird->x, ' ');
    playerBird->y-=_y;
    if(playerBird->y < 0)
            playerBird->y=0;
    else if(playerBird->y >= mapH-1)
        playerBird->y = mapH-2;
}

struct Bird CreateBird(int _x, int _y)
{
    struct Bird newBird;
    newBird.playerChar = 'C';
    newBird.x = 4;
    newBird.y = mapH/2;
    return newBird;
}
