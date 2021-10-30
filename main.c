#include <stdio.h>
#include <unistd.h>
#include "argumentHandler.c"
#include "mapHandler.h"
#include "FlappyBird/flappyBird.h"

void Setup();

void Exit();

int main(int argc, char **argv)
{
    if (ArgumentHandler(argc, argv) == 0)
        return 0;
    Setup();

    int gameLoop = 1;
    int input;

    struct timespec gameLoopTime[2] = {0, 1000000000L/8};

    while (gameLoop == 1)
    {
        ShowMap();
        gameLoop = UpdateFlappyBird();
        nanosleep(gameLoopTime, NULL);
    }
    Exit();
    return 0;
}

void Setup()
{
    CreateMap();
    PipeArraySetUp();
    playerBird = CreateBird(4, mapH / 2);
}

void Exit()
{
    DestroyMap();
}
