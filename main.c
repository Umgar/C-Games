#include <stdio.h>
#include <unistd.h>
#include <curses.h>
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

    while (gameLoop == 1)
    {
        ShowMap();
        gameLoop = UpdateFlappyBird();
        if(getch() == ' ')
            JumpBird(3);
    }
    Exit();
    return 0;
}

void Setup()
{
    initscr();
    noecho();
    timeout(1000/8);
    CreateMap();
    PipeArraySetUp();
    playerBird = CreateBird(4, mapH / 2);
}

void Exit()
{
    DestroyMap();
    sleep(10000);
    endwin();

}
