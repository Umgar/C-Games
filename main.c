/*Krzysztof Pacek*/
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "argumentHandler.c"
#include "mapHandler.h"
#include "FlappyBird/flappyBird.h"
#include "mainMenu.h"
#include "Scoreboard/scoreboard.h"

const double _TIMEOUT = 1000 / 8;
char nickname[20];

void Setup();

void Exit();

void FlappyBird();

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
    CreateMap(20, 100);
    SetUpFlappyBird();
    DestroyMap();
    CreateMap(20, 100);
    PipeArraySetUp();
    playerBird = CreateBird(4, mapH / 2);
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

void Setup()
{
    LoadScore();
    printf("Enter nickname: ");
    scanf("%s", nickname);
    initscr();
    noecho();
}

void Exit()
{

    endwin();
}
