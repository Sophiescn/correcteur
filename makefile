CC=gcc
CFLAGS=-ansi -pedantic -Wall

correcteur_0: Liste.o ATR.o main.o ouverture.o correcteur.o
	$(CC) -o correcteur_0 main.o Liste.o ATR.o ouverture.o correcteur.o

main.o: main.c Liste.h ATR.h ouverture.h correcteur.h
	$(CC) -c main.c $(CFLAGS)

Liste.o: Liste.c Liste.h
	$(CC) -c Liste.c $(CFLAGS)

ATR.o: ATR.c ATR.h
	$(CC) -c ATR.c $(CFLAGS)

ouverture.o: ouverture.c ouverture.h
	$(CC) -c ouverture.c $(CFLAGS)

correcteur.o: correcteur.c correcteur.h ATR.h Liste.h
	$(CC) -c correcteur.c $(CFLAGS)

clean:
	rm -f *.o
