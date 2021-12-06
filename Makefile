all:
	sudo apt-get install libncurses5-dev
	gcc main.c -lncurses -o CGames.out
