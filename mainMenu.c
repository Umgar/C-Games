#include <stdlib.h>
#include <curses.h>

void Menu(int *gameType)
{
    timeout(-1);
    int input = 0;
    do 
    {
        input = getch();
        input -= 48;
    }while(input < 0 || input > 3);
    switch (input)
    {
    case 1:
        *gameType = 1;
        break;
    case 2:
        *gameType = 2;
        break;
    case 3:
        *gameType = -1;
        break;
    default:
        break;
    }
}

void CreateMainScreen()
{
    char optionListA[] = "Play Flappy Bird";
    char optionListB[] = "Scoreboard";
    char optionListC[] = "Exit";
    printw("1) %s\n", optionListA);
    printw("2) %s\n", optionListB);
    printw("3) %s\n", optionListC);
}
