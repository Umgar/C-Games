CC = gcc
CFlags = -Wall

all:
	make compile main flappybird scoreboard\
main:
	$(CC) $(CFlags) -lncurses -c main.c mainMenu.c mapHandler.c argumentHandler.c 
flappybird:
	$(CC) $(CFlags) -c FlappyBird/bird.c FlappyBird/flappyBird.c FlappyBird/pipe.c 
scoreboard:
	$(CC) $(CFlags) -c Scoreboard/scoreboard.c 
compile: main flappybird scoreboard
	gcc -lncurses *.o\
	rm *.o
clean:
	rm *.o
