CC = gcc
CFLAGS = -c -w

all: nsbela

nsbela: main.o argshandler.o arraylist.o utilities.o 
		$(CC) main.o arraylist.o argshandler.o -o nsbela 

main.o: main.c 
		$(CC) $(CFLAGS) main.c modules/argshandler.h modules/tools/arraylist.h

argshandler.o: modules/argshandler.c
		$(CC) $(CFLAGS) modules/argshandler.c modules/tools/arraylist.h modules/tools/utilities.h
		
arraylist.o: modules/tools/arraylist.c
		$(CC) $(CFLAGS) modules/tools/arraylist.c
		
utilities.o: modules/tools/utilities.c
		$(CC) $(CFLAGS) modules/tools/utilities.c

hashmap.o: modules/tools/hashmap.c 
		$(CC) $(CFLAGS) modules/tools/hashmap.c 

clean:
		rm -rf *o nsbela
