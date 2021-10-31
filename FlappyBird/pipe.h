#include "pipe.c"

void MovePipePos(struct Pipe *movingPipe, int playerX);

void DrawPipe(struct Pipe *movingPipe);

void PipeHoleCreate(struct Pipe *pipe);

struct Pipe CreatePipe(int width);
