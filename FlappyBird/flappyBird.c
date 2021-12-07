#include <stdlib.h>
#include <curses.h>
#include "pipe.h"
#include "bird.h"
#include "../mapHandler.h"

int flappyBirdPoints = 0;

Pipe pipeArray[10];

Bird playerBird;
const int pipeWidth = 6;

const int pipeNum = 10;

void FBAddPoints(int val)
{
    flappyBirdPoints += val;
}

int FBGetPoints()
{
    return flappyBirdPoints;
}

void PipeArraySetUp()
{
    int i;
    for(i=0;i<pipeNum;i++)
        pipeArray[i].free = 0;
    pipeArray[0] = CreatePipe(6);
    DrawPipe((void *)&pipeArray[0]);
}


int timer = 0;

void UpdatePipes(int maxGap)
{
    int i;
    for(i=0; i<pipeNum; i++)
    {
        if(pipeArray[i].free == 0) continue;
        if(pipeArray[i].endI == 0) {pipeArray[i].free = 0; continue;}
        MovePipePos((void *)&pipeArray[i], playerBird.x);
        if(pipeArray[i].endI == playerBird.x) FBAddPoints(100);
        DrawPipe((void *)&pipeArray[i]);
    }
    if(timer>=maxGap)
    for(i=0; i<pipeNum; i++)
    {
        if(pipeArray[i].free == 1) continue;
        pipeArray[i] = CreatePipe(pipeWidth);
        DrawPipe((void *)&pipeArray[i]);
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

void SetUpFlappyBird(int mapH){
    playerBird = CreateBird(4, mapH / 2);
    int y = 16;
    int x = 42;
    int i;
    char string[] = "***Press space***";
    for(i=0;i<17;i++)
        ChangeCell(y, x+i, string[i]);
    ShowMap();
    do{
        if(getch() == ' ') return;
    }while(1==1);
}


int UpdateFlappyBird()
{
    UpdatePipes(pipeWidth + 13);
    if(GetCellVal(playerBird.y, playerBird.x) == '@') return 0;
    UpdateBird(&playerBird, -1, mapH);
    ChangeCell(playerBird.y, playerBird.x, playerBird.playerChar);
    return 1;
}

void JumpBird(int val)
{
    UpdateBird((void*)&playerBird, val, mapH);
}