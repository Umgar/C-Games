#include <stdio.h>

int HelpInfo();

int ArgumentHandler(int argc, char **argv)
{
    int i;
    if(argc > 1)
        for(i=0;i<argc;i++)
            if(argv[i] == "-h" || "--help") return HelpInfo();
    return 1;
}

int HelpInfo()
{
    printf("\nProgram napisany przez Krzysztofa Packa\n");
    printf("W celu skompilowania programu potrzebna jest biblioteka ncurses\n");
    return 0;
}