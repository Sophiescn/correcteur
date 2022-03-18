CC=gcc
CFLAGS=-ansi -pedantic -Wall

main: ATR.o main.o
	$(CC) -o main main.o ATR.o $(CFLAGS)

main.o: main.c ATR.h
	$(CC) -c main.c $(CFLAGS)

ATR.o: ATR.c ATR.h
	$(CC) -c ATR.c $(CFLAGS)

clean:
	rm -f *.o
