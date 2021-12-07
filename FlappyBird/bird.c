#include <stdlib.h>
#include "../mapHandler.h"
struct bird
{
    char playerChar;
    int x;
    int y;
};
typedef struct bird Bird;

void UpdateBird(Bird *playerBird, int _y, int mapH)
{
    ChangeCell(playerBird->y, playerBird->x, ' ');
    playerBird->y-=_y;
    if(playerBird->y < 0)
            playerBird->y=0;
    else if(playerBird->y >= mapH-1)
        playerBird->y = mapH-2;
}

Bird CreateBird(int _x, int _y)
{
    Bird newBird;
    newBird.playerChar = 'C';
    newBird.x = 4;
    newBird.y = mapH/2;
    return newBird;
}
