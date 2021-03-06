#ifndef __PIPE__
#define __PIPE__

typedef struct pipe
{
    int partOne, partTwo;
    int width;
    int begI, endI;
    int free;
    int pipeHoleSize;
}Pipe;

void MovePipePos(Pipe *movingPipe, int playerX);

void DrawPipe(Pipe *movingPipe);

void PipeHoleCreate(Pipe *pipe);

Pipe CreatePipe(int width);


#endif