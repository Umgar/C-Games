#include "mapHandler.c"
/*
    Pokazuje aktualna mape przechowana w tablicy gameMap
*/
void ShowMap();

void CreateMap(int mapHeight,int mapWidth);

void DestroyMap();

char ChangeCell(int height, int width, char symbol);

char GetCellVal(int height, int width);