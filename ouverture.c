#include "ouverture.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int taille_fichier(FILE* fichier) {
    int taille;
    fseek(fichier, 0, SEEK_END);
    taille = ftell(fichier);
    rewind(fichier);
    return taille;
}

char* lecture_fichier(char* nom) {
    FILE* fichier = NULL;
    char c;
    int taille;
    char* chaine = NULL;
    int i;

    fichier = fopen(nom, "r");
    if (!fichier) {return NULL;}
    taille = taille_fichier(fichier);
    chaine = (char*) malloc(sizeof(char) * (taille + 1));

    for (i = 0; i < taille; i++) {
        c = fgetc(fichier);
        chaine[i] = c;
    }
    fclose(fichier);

    return chaine;
}
