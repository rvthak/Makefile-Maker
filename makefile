CC=gcc
CFLAGS= 

all: myprog

myprog: makefileMK.o
	$(CC) $(CFLAGS) -o myprog makefileMK.o

makefileMK.o: makefileMK.c
	$(CC) $(CFLAGS) -c makefileMK.c 

.PHONY: clean

clean:
	rm -f *o myprog
