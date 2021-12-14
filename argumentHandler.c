#include <stdio.h>


int OptionHandler(int argc, char **argv, int i, int *gameType)
{
    if(argv[i][1] == 'h' )
    {
        printf("Program napisany przez Krzysztofa Packa\n");
        printf("Program to konsolowa wersja popularnej niegdyś gry \"Flappy bird\".\nGra polega na przeprowadzeniu gracza(literka C) przez otwory w slupach.\nGracz moze poruszac sie w gore przy uzyciu [spacji]. Za kazda pokonana przeszkode gracz zyskuje 100 punktow.\nCelem gry jest uzyskanie jak najwiekszej ilosci punktow.\n\n");
        printf(" -h wyswietla dodatkowe informacje o programie\n -f wlacza bezposrednio gre flappyBird\n\n");
        return 1;
    }
    if(argv[i][1] == 'f')
        (*gameType) = 1;
    return 0;
}

int ArgumentHandler(int argc, char **argv, int *gameType)
{
    int i;
    if(argc > 1)
        for(i=0;i<argc;i++)
        {
            if(argv[i][0] == '-') if(OptionHandler(argc, argv, i, gameType) == 1) return 1;
        }
    return 0;
}
