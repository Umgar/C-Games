#include <stdlib.h>
#include "pipe.h"
#include "bird.h"

struct Pipe pipeArray[10];

struct Bird playerBird;

const int pipeWidth = 6;

const int pipeNum = 10;

void PipeArraySetUp()
{
    int i;
    for(i=0;i<pipeNum;i++)
        pipeArray[i].free = 0;
    pipeArray[0] = CreatePipe(6);
    DrawPipe(&pipeArray[0]);
}

int timer = 0;

void UpdatePipes(int maxGap)
{
    int i;
    for(i=0; i<pipeNum; i++)
    {
        if(pipeArray[i].free == 0) continue;
        if(pipeArray[i].endI == 0) {pipeArray[i].free = 0; continue;}
        MovePipePos(&pipeArray[i]);
        DrawPipe(&pipeArray[i]);
    }
    if(timer>=maxGap)
    for(i=0; i<pipeNum; i++)
    {
        if(pipeArray[i].free == 1) continue;
        pipeArray[i] = CreatePipe(pipeWidth);
        DrawPipe(&pipeArray[i]);
        timer=0;
        break;
    }
    timer++;
}

int FreePipesNum()
{
    int a =0, i;
    for(i=0; i<pipeNum; i++)
        if(pipeArray[i].free == 0) a++;
    return a;
}

int UpdateFlappyBird()
{
    UpdatePipes(pipeWidth + 9);
    if(GetCellVal(playerBird.y, playerBird.x) == '@') return 0;
    ChangeCell(playerBird.y, playerBird.x, playerBird.playerChar);
    UpdateBird(&playerBird, -1);
    return 1;
}

void JumpBird(int val)
{
    UpdateBird(&playerBird, val);
}