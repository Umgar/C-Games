#include <stdio.h>

int OptionHandler(int argc, char **argv, int i, int *gameType);

int ArgumentHandler(int argc, char **argv, int *gameType)
{
    int i;
    if(argc > 1)
        for(i=0;i<argc;i++)
        {
            if(argv[i][0] == '-') return OptionHandler(argc, argv, i, gameType);
        }
    return 0;
}

int OptionHandler(int argc, char **argv, int i, int *gameType)
{
    if(argv[i][1] == 'h' )
    {
        printf("Program napisany przez Krzysztofa Packa\n");
        printf("Do kompilacji wymagana jest biblioteka ncurses\n\n");
        printf(" -h[--help] wyswietla dodatkowe informacje o programie\n -f[--flappyBird] wlacza bezposrednio gre flappyBird\n");
        return 1;
    }
    if(argv[i][1] == 'f')
        (*gameType) = 1;
    return 0;
}