#ifndef __PIPE__
#define __PIPE__

void MovePipePos(struct Pipe *movingPipe, int playerX);

void DrawPipe(struct Pipe *movingPipe);

void PipeHoleCreate(struct Pipe *pipe);

struct Pipe CreatePipe(int width);
extern struct Pipe
{
    int partOne, partTwo;
    int width;
    int begI, endI;
    int free;
    int pipeHoleSize;
};
#endif