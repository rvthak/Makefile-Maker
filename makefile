CC=gcc
CFLAGS= 

all: kaka

kaka: makefileMK.o
	$(CC) $(CFLAGS) -o kaka makefileMK.o

makefileMK.o: makefileMK.c
	$(CC) $(CFLAGS) -c makefileMK.c 

.PHONY: clean

clean:
	rm -f *o kaka
