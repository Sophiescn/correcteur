CC=gcc
CFLAGS=-ansi -pedantic -Wall

correcteur_0: Liste.o ATR.o main.o ouverture.o
	$(CC) -o correcteur_0 main.o Liste.o ATR.o ouverture.o $(CFLAGS)

main.o: main.c Liste.h
	$(CC) -c main.c $(CFLAGS)

Liste.o: Liste.c Liste.h
	$(CC) -c Liste.c $(CFLAGS)

ATR.o: ATR.c ATR.h
	$(CC) -c ATR.c $(CFLAGS)

ouverture.o: ouverture.c ouverture.h
	$(CC) -c ouverture.c $(CFLAGS)

clean:
	rm -f *.o
