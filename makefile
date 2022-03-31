CC=gcc
CFLAGS=-ansi -pedantic -Wall
all: correcteur_0 correcteur_1

correcteur_0: Liste.o ATR.o ouverture.o correcteur.o correcteur_0.o
	$(CC) -o correcteur_0 correcteur_0.o Liste.o ATR.o ouverture.o correcteur.o

correcteur_1: Liste.o ATR.o ouverture.o correcteur.o levenshtein.o correcteur_1.o
	$(CC) -o correcteur_1 correcteur_1.o Liste.o ATR.o ouverture.o correcteur.o levenshtein.o

correcteur_0.o: correcteur_0.c Liste.h ATR.h ouverture.h correcteur.h
	$(CC) -c correcteur_0.c $(CFLAGS)

correcteur_1.o: correcteur_1.c Liste.h ATR.h ouverture.h correcteur.h levenshtein.h
	$(CC) -c correcteur_1.c $(CFLAGS)

Liste.o: Liste.c Liste.h
	$(CC) -c Liste.c $(CFLAGS)

ATR.o: ATR.c ATR.h
	$(CC) -c ATR.c $(CFLAGS)

ouverture.o: ouverture.c ouverture.h
	$(CC) -c ouverture.c $(CFLAGS)

correcteur.o: correcteur.c correcteur.h ATR.h Liste.h
	$(CC) -c correcteur.c $(CFLAGS)

levenshtein.o: levenshtein.c levenshtein.h
	$(CC) -c levenshtein.c $(CFLAGS)

clean:
	rm -f *.o
