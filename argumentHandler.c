#include <stdio.h>

int HelpInfo();

int ArgumentHandler(int argc, char **argv)
{
    if(argc > 1)
        for(int i=0;i<argc;i++)
            if(argv[i] == "-h" || "--help") return HelpInfo();
    return 1;
}

int HelpInfo()
{
    printf("\nProgram napisany przez Krzysztofa Packa\n");
    return 0;
}