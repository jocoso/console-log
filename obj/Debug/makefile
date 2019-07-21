CC = gcc
CFLAGS = -c -w -DDEBUG

OES = hash_test.o hashmap.o debug.o stddefs.o

MODULES = ../../modules/
TOOLS = ../../modules/tools/
UTILITIES = ../../modules/utilities/

all: nsbela

nsbela: $(OES) 
		$(CC) $(OES) -o test

hash_test.o: hash_test.c 
		$(CC) $(CFLAGS) hash_test.c $(UTILITIES)debug.h $(UTILITIES)stddefs.h $(TOOLS)hashmap.h
hashmap.o: $(TOOLS)hashmap.c 
		$(CC) $(CFLAGS) $(TOOLS)hashmap.c $(UTILITIES)stddefs.h $(UTILITIES)debug.h
linkedlist.o: $(TOOLS)linkedlist.c 
		$(CC) $(CFLAGS) $(TOOLS)linkedlist.c $(UTILITIES)stddefs.h
debug.o: $(UTILITIES)debug.c 
		$(CC) $(CFLAGS) $(UTILITIES)debug.c
stddefs.o: $(UTILITIES)stddefs.c 
		$(CC) $(CFLAGS) $(UTILITIES)stddefs.c

clean:
		rm -rf *o test