CC=gcc
CFLAGS=-ansi -pedantic -Wall
all: correcteur_0 correcteur_1 correcteur_2

correcteur_0: Liste.o ATR.o ouverture.o correcteur.o levenshtein.o ArbreBK.o correcteur_0.o
	$(CC) -o correcteur_0 correcteur_0.o Liste.o ATR.o ouverture.o levenshtein.o correcteur.o ArbreBK.o

correcteur_1: Liste.o ATR.o ouverture.o correcteur.o levenshtein.o ArbreBK.o correcteur_1.o
	$(CC) -o correcteur_1 correcteur_1.o Liste.o ATR.o ouverture.o correcteur.o levenshtein.o ArbreBK.o

correcteur_2: Liste.o ouverture.o correcteur.o levenshtein.o correcteur_2.o ArbreBK.o
	$(CC) -o correcteur_2 correcteur_2.o Liste.o ATR.o ouverture.o correcteur.o levenshtein.o ArbreBK.o

correcteur_0.o: correcteur_0.c Liste.h ATR.h ouverture.h correcteur.h
	$(CC) -c correcteur_0.c $(CFLAGS)

correcteur_1.o: correcteur_1.c ArbreBK.h Liste.h ATR.h ouverture.h correcteur.h levenshtein.h
	$(CC) -c correcteur_1.c $(CFLAGS)

correcteur_2.o: correcteur_2.c ArbreBK.h levenshtein.h ouverture.h Liste.h correcteur.h
	$(CC) -c correcteur_2.c $(CFLAGS)

Liste.o: Liste.c Liste.h
	$(CC) -c Liste.c $(CFLAGS)

ATR.o: ATR.c ATR.h
	$(CC) -c ATR.c $(CFLAGS)

ouverture.o: ouverture.c ouverture.h
	$(CC) -c ouverture.c $(CFLAGS)

correcteur.o: correcteur.c correcteur.h Liste.h ArbreBK.h levenshtein.h
	$(CC) -c correcteur.c $(CFLAGS)

levenshtein.o: levenshtein.c levenshtein.h
	$(CC) -c levenshtein.c $(CFLAGS)

arbreBK.o: ArbreBK.c ArbreBK.h levenshtein.h ATR.h
	$(CC) -c ArbreBK.c $(CFLAGS)

clean:
	rm -f *.o

