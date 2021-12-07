#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <curses.h>

struct sbItem
{
    int score;
    char nick[20]; 
};

struct sbItem scoreboardList[5];

void LoadScore()
{
    FILE *scFile;
    scFile = fopen("scoreboard.txt", "r");
    int i;
    if (scFile) 
    {
        for(i=0;i<5;i++)
            fscanf(scFile, "%d %s", &scoreboardList[i].score, scoreboardList[i].nick);
        fclose(scFile);
    }
    else
    {
        scFile = fopen("scoreboard.txt", "w");
        for(i=0;i<5;i++)
            fprintf(scFile, "%d %s\n", -1, "-------");
        fclose(scFile);
    }
}

void ShowScore()
{
    timeout(-1);
    clear();
    int i;
    for(i=0;i<5;i++)
            printw("%i %s\n", scoreboardList[i].score, scoreboardList[i].nick);
    printw("\nPress q to return\n");
    do{;} while (tolower(getch()) != 'q');
        
}



void AddScore(int score, char *nickname)
{
    timeout(-1);
    struct sbItem temp[6];
    struct sbItem z;
    int i, j;
    for(i=0;i<5;i++)
        temp[i] = scoreboardList[i];
    temp[5].score = score;
    for(i=0;i<20;i++)
        temp[5].nick[i] = nickname[i];
    for(i=0;i<5;i++)
        for(j=i+1;j<6;j++)
            {
                if(temp[i].score < temp[j].score)
                {
                    z = temp[i];
                    temp[i] = temp[j];
                    temp[j] = z;
                }
            }
    for(i=0;i<5;i++)
        scoreboardList[i] = temp[i];
    FILE *scFile;
    scFile = fopen("scoreboard.txt", "w");
    for(i=0;i<5;i++)
            fprintf(scFile, "%d %s\n", scoreboardList[i].score, scoreboardList[i].nick);
    fclose(scFile);
}