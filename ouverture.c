#include <stdio.h>
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

int conversion_accent(int c) {
    printf("%d %c", c, c);
    if (97 <= c && c <= 122) {
        return c; /* a - z */
    }
    if (64 <= c && c <= 90) {
        return tolower(c); /* A - Z */
    }
    if (c == 50089) {
        return 101; /* e */
    }
    if (c == 'à') {
        return 91; /* a */
    }
}

int main(void) {

    char* chaine;
    chaine = lecture_fichier("a_corriger_0.txt");

    printf("%s\n", chaine);

    for (int i = 0; i < strlen(chaine); i++) {
        printf("%d %c\n", chaine[i], chaine[i]);
        chaine[i] = conversion_accent(chaine[i]);
    }

    printf("%s\n", chaine);

    return 0;
}
