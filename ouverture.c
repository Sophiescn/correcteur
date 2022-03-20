#include "ouverture.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int fichier_valide(char* fichier) {
    FILE* f;
    f = fopen(fichier, "r");
    if (f){
        fclose(f);
        return 1;
    }
    return 0;
}

int est_dictionnaire(char* chaine) {
    int i;
    for (i = 0; i < strlen(chaine); i++){
        if (chaine[i] == '.' && chaine[i + 1] == 'd') {
            return 1;
        }
    }
    return 0;
}

int arguments_valides (int argc, char* argv[]) {
    if (argc != 3){
        return 0;
    }
    if (!fichier_valide(argv[1]) || !fichier_valide(argv[2])) {
        return 0;
    }
    
    if (est_dictionnaire(argv[1])) {
        if (est_dictionnaire(argv[2])) {
            return 0;
        }
        return 1;
    }
    if (est_dictionnaire(argv[2])) {
        return 2;
    }
    return 0;
}

void ordonne_fichiers(int res, char* source_1, char* source_2) {
    char* temp;
    if (res == 1) {
        temp = source_1;
        source_1 = source_2;
        source_2 = temp;
    }
}

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
