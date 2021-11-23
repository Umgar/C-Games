#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct sbItem
{
    int score;
    char nick[20]; 
};

struct sbItem scoreboardList[5];

void LoadScore()
{
    FILE *scFile;
    int c;
    int i;
    if (scFile = fopen("scoreboard.txt", "r")) 
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
    struct sbItem temp[5];
    int i=0, j=5, z;
    for(i=0;i<5;i++)
        temp[i] = scoreboardList[i];
    for(i=0;i<5;i++)
    {
        if(scoreboardList[i].score<score)
        {
            j=i;
            for(z=0;z<20;z++)
                scoreboardList[i].nick[z] = nickname[z];
            scoreboardList[i].score = score;
            break;
        }
    }
    for(i=j;i<4;i++)
        scoreboardList[j+1] = temp[j];
    FILE *scFile;
    scFile = fopen("scoreboard.txt", "w");
    for(i=0;i<5;i++)
            fprintf(scFile, "%d %s\n", scoreboardList[i].score, scoreboardList[i].nick);
    fclose(scFile);
}