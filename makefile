CC = gcc
CFLAGS = -c -w

ARGH_H = modules/tools/linkedlist.h modules/tools/utilities.h 
OES = main.o hashmap.o utilities.o linkedlist.o

all: nsbela

nsbela: $(OES) 
		$(CC) $(OES) -o nsbela 

main.o: main.c 
		$(CC) $(CFLAGS) main.c modules/tools/linkedlist.h 

argshandler.o: modules/argshandler.c
		$(CC) $(CFLAGS) modules/argshandler.c $(ARGH_H)
		
arraylist.o: modules/tools/arraylist.c
		$(CC) $(CFLAGS) modules/tools/arraylist.c
		
utilities.o: modules/tools/utilities.c
		$(CC) $(CFLAGS) modules/tools/utilities.c

hashmap.o: modules/tools/hashmap.c 
		$(CC) $(CFLAGS) modules/tools/hashmap.c 

linkedlist.o: modules/tools/linkedlist.c
		$(CC) $(CFLAGS) modules/tools/linkedlist.c 

clean:
		rm -rf *o nsbela
