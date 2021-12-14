/*Krzysztof Pacek*/
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "argumentHandler.h"
#include "mapHandler.h"
#include "FlappyBird/flappyBird.h"
#include "mainMenu.h"
#include "Scoreboard/scoreboard.h"

const double _TIMEOUT = 1000 / 8;
char nickname[20];

void Setup();

void Exit();

void FlappyBird();

int CheckScreenSize(int minWidth, int minHeight);

int main(int argc, char **argv)
{
    
    int gameType = 0;
    if (ArgumentHandler(argc, argv, &gameType) == 1)
        return 0;
    Setup();
    do
    {
        CreateMainScreen();
        if (gameType == 0)
            Menu(&gameType);
        if (gameType == -1)
        {
            Exit(gameType);
            return 0;
        }
        else if (gameType == 1)
            FlappyBird();
        else if (gameType == 2)
            ShowScore();
        else
        {
            printf("No more games\n");
            Exit();
            return 0;
        }
        clear();
        gameType = 0;
    } while (true);
    return 0;
}

void FlappyBird()
{
    int gameLoop = 1;
    int input;
    int gameHeight = 20;
    int gameWidth = 100;
    if(CheckScreenSize(gameWidth+1, gameHeight+1)!=0)
        return;
    CreateMap(gameHeight, gameWidth);
    SetUpFlappyBird(mapH);
    DestroyMap();
    CreateMap(gameHeight, gameWidth);
    PipeArraySetUp();
    timeout(_TIMEOUT);
    while (gameLoop == 1)
    {
        ShowMap();
        input = getch();
        if (input == ' ')
            JumpBird(4);
        else
            gameLoop = UpdateFlappyBird();
    }
    DestroyMap();
    int score = FBGetPoints();
    AddScore(score, nickname);
}

int CheckScreenSize(int minWidth, int minHeight)
{
    int exitStatus = 0;
    clear();
    if(COLS < minWidth)
    {
        printw("Terminal jest za waski! Musi miec szerokosc min:%i\nObecnie ma szerokosc:%i\n",minWidth, COLS);
        exitStatus = 1;
    }
    if(LINES < minHeight)
    {
        printw("Terminal jest za niski! Musi miec wysokosc min:%i\nObecnie ma wysokosc:%i\n",minHeight, LINES);
        exitStatus = 1;
    }
    if(exitStatus != 0)
    {
        printw("\nPress any button to return...\n");
        getch();
    }
    clear();
    return exitStatus;
}

void Setup()
{
    LoadScore();
    printf("Enter nickname: ");
    scanf("%s", nickname);
    initscr();
    use_env(TRUE);
    noecho();
}

void Exit()
{

    endwin();
}
