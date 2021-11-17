/*Krzysztof Pacek*/
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "argumentHandler.c"
#include "mapHandler.h"
#include "FlappyBird/flappyBird.h"
#include "mainMenu.h"

const double _TIMEOUT = 1000/8;

void Setup();

void Exit(int gameType);

void FlappyBird();

int main(int argc, char **argv)
{
    int gameType = 0;
    if (ArgumentHandler(argc, argv, &gameType) == 1)
        return 0;
    Setup();
    CreateMainScreen();
    if(gameType == 0)
        Menu(&gameType);
    if(gameType == -1) {Exit(gameType); return 0;}
    else if(gameType==1) FlappyBird();
    else {printf("No more games\n");}
    Exit(gameType);
    return 0;
}

void FlappyBird()
{
    int gameLoop = 1;
    PipeArraySetUp();
    playerBird = CreateBird(4, mapH / 2);
    timeout(_TIMEOUT);
    while (gameLoop == 1)
    {
        ShowMap();
        if(getch() == ' ')
            JumpBird(4);
        else
            gameLoop = UpdateFlappyBird();

    }
    
}

void Setup()
{
    initscr();
    noecho();
    CreateMap();
}

void Exit(int gameType)
{
    DestroyMap();
    endwin();
    if(gameType > 0)
        printf("%i \n", FBGetPoints());
}

