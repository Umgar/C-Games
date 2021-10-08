#include <stdio.h>
#include "argumentHandler.c"
#include "mapHandler.h"

int main(int argc, char **argv)
{
    if(ArgumentHandler(argc, argv) == 0) return 0;
    CreateMap();
    ShowMap();
    
    return 0;
}

