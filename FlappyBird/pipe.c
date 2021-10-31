#include <stdio.h>
#include <time.h>

struct Pipe
{
    int partOne, partTwo;
    int width;
    int begI, endI;
    int free;
};

void MovePipePos(struct Pipe *movingPipe, int playerX)
{
    int i;
    if(movingPipe->begI<=1)
    {
        if(movingPipe->width <= 0)
        {
            for (i = 1; i < mapH-1; i++)
                ChangeCell(i, 1, ' ');
            movingPipe->free = 0;
            return;
        }
        else
        {
            movingPipe->endI--;
            movingPipe->width--;
        }
    }
    else
    {
        movingPipe->begI--;
        movingPipe->endI--;
    }
    if(movingPipe->endI < mapW-2)
    {
        for (i = 1; i < mapH-1; i++)
            ChangeCell(i, movingPipe->endI+1, ' ');
    }
}

void DrawPipe(struct Pipe *movingPipe)
{
    int i, j;
    if(movingPipe->free == 0) movingPipe->free = 1;
    for (i = 0; i < movingPipe->width; i++)
    {
        if (i + movingPipe->begI >= mapW - 1)
            return;
        for (j = 1; j < mapH - 1; j++)
        {
            if(j<movingPipe->partOne || j>movingPipe->partTwo)
                ChangeCell(j, i + movingPipe->begI, '@');
        }
    }
}

void PipeHoleCreate(struct Pipe *pipe)
{
    srand(time(NULL));
    int randomNum = rand() % (mapH-6) + 1;
    pipe->partOne = randomNum;
    pipe->partTwo = randomNum+5;
}

struct Pipe CreatePipe(int width)
{
    struct Pipe newPipe;
    newPipe.begI = mapW - 1;
    newPipe.width = width;
    newPipe.endI = newPipe.begI + newPipe.width - 1;
    PipeHoleCreate(&newPipe);
    newPipe.free = 0;
    return newPipe;
}

