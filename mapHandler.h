#ifndef __MAPHANDLER__
#define __MAPHANDLER__

extern int mapH, mapW;

extern char **gameMap;

void ShowMap();

void CreateMap(int mapHeight,int mapWidth);

void DestroyMap();

char ChangeCell(int height, int width, char symbol);

char GetCellVal(int height, int width);
#endif
