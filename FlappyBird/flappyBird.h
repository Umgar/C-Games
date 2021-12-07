#ifndef __FLAPPY_BIRD__
#define __FLAPPY_BIRD__

extern struct Bird playerBird;

void FBAddPoints(int val);
int FBGetPoints();

void PipeArraySetUp();

void UpdatePipes(int maxGap);

int FreePipesNum();

void SetUpFlappyBird(int mapH);

int UpdateFlappyBird();

void JumpBird(int val);
#endif