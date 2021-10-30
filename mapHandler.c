#include <stdio.h>
#include <stdlib.h>

const int mapH = 20, mapW = 100;

char **gameMap;

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

    gameMap = (char**)malloc(mapH * sizeof(char*));
    for (i = 0; i < mapH; i++)
        gameMap[i] = (char*)malloc((mapW+1) * sizeof(char));

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
void DestroyMap()
{
    for (int i = 0; i < mapH; i++)
        free(gameMap[i]);
 
    free(gameMap);
}

char ChangeCell(int height, int width, char symbol)
{
    if(height>mapH || height < 0 || width > mapW || width < 0) return '\0';
    char prevChar = gameMap[height][width];
    gameMap[height][width] = symbol;
    return prevChar;
}

char GetCellVal(int height, int width)
{
    return gameMap[height][width];
}