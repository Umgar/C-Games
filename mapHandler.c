#include <stdio.h>
#include <stdlib.h>

const int mapH = 20, mapW = 50;

char gameMap[20][51];

void ShowMap()
{
    int i, j;
    system("clear");
    for (i = 0; i < mapH; i++)
    {
        printf("%s", gameMap[i]);
        printf("\n");
    }
}

void CreateMap()
{
    int i, j;

    for (i = 0; i < mapW; i++)
        gameMap[0][i] = '#';
    gameMap[0][mapW] = '\0';

    for (i = 0; i < mapW; i++)
        gameMap[mapH-1][i] = '#';
    gameMap[mapH-1][mapW] = '\0';

    for (i = 1; i < mapH-1; i++)
    {
        for (j = 0; j < mapW; j++)
            gameMap[i][j] = ' ';
        gameMap[i][mapW] = '\0';
    }

    for (i = 1; i < mapH-1; i++)
    {
        gameMap[i][0] = '#';
        gameMap[i][mapW-1] = '#';
    }
}