CC = gcc
CFlags = -Wall
CLib = -lncurses

all:
	make compile main flappybird scoreboard
main:
	$(CC) $(CFlags) -c main.c mainMenu.c mapHandler.c argumentHandler.c $(CLib)
flappybird:
	$(CC) $(CFlags) -c FlappyBird/bird.c FlappyBird/flappyBird.c FlappyBird/pipe.c $(CLib)
scoreboard:
	$(CC) $(CFlags) -c Scoreboard/scoreboard.c $(CLib)
compile: main flappybird scoreboard 
	gcc *.o $(CLib) -o CGame.out
	rm *.o
clean:
	rm *.o
