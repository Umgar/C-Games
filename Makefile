CC = gcc
CFlags = -Wall
CLib = -lncurses
FBD = FlappyBird
SD = Scoreboard
objects = main.o mainMenu.o argumentHandler.o mapHandler.o scoreboard.o flappyBird.o bird.o pipe.o

all: $(objects)
	$(CC) $(CFlags) $(objects) $(CLib) -o CGame.out

main.o: main.c
	$(CC) $(CFlags) -c main.c $(CLib)

mainMenu.o: mainMenu.c mainMenu.h
	$(CC) $(CFlags) -c mainMenu.c $(CLib)
	
argumentHandler.o: argumentHandler.c argumentHandler.h
	$(CC) $(CFlags) -c argumentHandler.c $(CLib)
	
mapHandler.o: mapHandler.c mapHandler.h
	$(CC) $(CFlags) -c mapHandler.c $(CLib)

scoreboard.o: $(SD)/scoreboard.c $(SD)/scoreboard.h
	$(CC) $(CFlags) -c $(SD)/scoreboard.c $(CLib)
	
flappyBird.o: $(FBD)/flappyBird.h $(FBD)/flappyBird.c
	$(CC) $(CFlags) -c $(FBD)/flappyBird.c $(CLib)

bird.o: $(FBD)/bird.c $(FBD)/bird.h
	$(CC) $(CFlags) -c $(FBD)/bird.c $(CLib)
	
pipe.o: $(FBD)/pipe.c $(FBD)/pipe.h
	$(CC) $(CFlags) -c $(FBD)/pipe.c $(CLib)

clean:
	rm *.o
