#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "argumentHandler.c"
#include "mapHandler.h"
#include "FlappyBird/flappyBird.h"

const double _TIMEOUT = 1000/8;

void Setup();

void Exit();

void FlappyBird();

int Menu();

int main(int argc, char **argv)
{
    int gameType = 0;
    if (ArgumentHandler(argc, argv, &gameType) == 1)
        return 0;
    Setup();
    gameType = Menu();
    if(gameType==1) FlappyBird();
    else {printf("No more games\n");}
    Exit();
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

void Exit()
{
    DestroyMap();
    endwin();
    printf("%i \n", FBGetPoints());
}

int Menu()
{
    int val = 0;
    int gameLoop = 1;
    timeout(-1);
    int input;
    int maxI = 2;
    int i = 0;
    
    while (gameLoop == 1)
    {
        input = getch();
        printw("%i == %i\n", i, KEY_DOWN);
        if(input == KEY_DOWN)
            if(i+1 >= maxI) i = 0;
            else i++;
        if(input == KEY_DOWN)
            if(i-1 <= 0) i = maxI;
            else i--;
        if(input == KEY_ENTER)
            {val = i;
            gameLoop = 0;}
    }
    return val;
}