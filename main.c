#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LETTRES 50

typedef struct noeud {
    char c;
    struct noeud* fg;
    struct noeud* fd;
    struct noeud* fils;
} Noeud, * Arbre;


Noeud* alloue_noeud(char c) {
    Noeud* n = (Noeud*) malloc(sizeof(Noeud));
    if (n) {
        if ('A' <= c && c <= 'Z') {
            n->c = c - 'A' + 'a';
        } else {
            n->c = c;
        }
        n->fg = NULL;
        n->fd = NULL;
        n->fils = NULL;
    }
    return n;
}

int recherche(Arbre a, char* mot) {
    if (!a) {return 0;}
    if (* mot == '\0') {return 1;}
    if (* mot == a->c) {return recherche(a->fils, mot + 1);}
    if (a->c == '\0') {return recherche(a->fils, mot);}
    if (* mot < a->c) {return recherche(a->fg, mot);}
    if (* mot > a->c) {return recherche(a->fd, mot);}
    return 0;
}

void ajoute_branche(Arbre* a, char* mot) {
    if ((*a = alloue_noeud(*mot))) {
        if (*mot != '\0') {
            ajoute_branche(&((*a)->fils), mot + 1);
        }
    }
}

void insertion(Arbre* a, char* mot) {
    if (!(*a)) {
        ajoute_branche(a, mot);
        return;
    }
    if ((*a)->c == '\0' && * mot != '\0') {
        insertion(&(*a)->fils, mot);
    } else if (* mot == '\0') {
        (*a)->fils = alloue_noeud('\0');
    } else if ((*a)->c == * mot) {
        insertion(&(*a)->fils, mot + 1);
    } else if ((*a)->c < * mot) {
        insertion(&((*a)->fd), mot);
    } else if ((*a)->c > * mot) {
        insertion(&((*a)->fg), mot);
    }
}

void suppression_aux(Arbre a, Arbre* tmp, char* mot, char buffer[], int position) {
    if (a) {
        buffer[position] = a->c;
        if (a->c == '\0' && strcmp(buffer, mot)) {
            insertion(tmp, buffer);
            position--;
        } else if (a->c == '\0') {
            position--;
        }

        if (a->fils) {
            suppression_aux(a->fils, tmp, mot, buffer, position + 1);
        }

        if (a->fg) {
            suppression_aux(a->fg, tmp, mot, buffer, position);
        }

        if (a->fd) {
            suppression_aux(a->fd, tmp, mot, buffer, position);
        }
    }
}

Arbre suppression(Arbre a, char* mot) {

    if (!recherche(a, mot)) {return a;}

    char buffer[MAX_LETTRES];
    int position = 0;
    Arbre tmp = NULL;
    suppression_aux(a, &tmp, mot, buffer, position);
    return tmp;
}

void affiche_aux(Arbre a, char buffer[], int position) {
    if (a) {
        buffer[position] = a->c;
        if (a->c == '\0') {
            printf("%s\n", buffer);
            position--;
        }

        if (a->fils) {
            affiche_aux(a->fils, buffer, position + 1);
        }

        if (a->fg) {
            affiche_aux(a->fg, buffer, position);
        }

        if (a->fd) {
            affiche_aux(a->fd, buffer, position);
        }
    }
}

void affiche(Arbre a) {
    char buffer[MAX_LETTRES];
    int position = 0;
    affiche_aux(a, buffer, position);
}


int main(void) {

    // arbre exemple : le la les leur de des en un

    Arbre a = NULL;
/*
    a = alloue_noeud('l');
    a->fils = alloue_noeud('e');
    a->fils->fils = alloue_noeud('\0');

    a->fils->fg = alloue_noeud('a');
    a->fils->fg->fils = alloue_noeud('\0');

    a->fils->fils->fils = alloue_noeud('s');
    a->fils->fils->fils->fils = alloue_noeud('\0');

    a->fils->fils->fils->fd = alloue_noeud('u');
    a->fils->fils->fils->fd->fils = alloue_noeud('r');
    a->fils->fils->fils->fd->fils->fils = alloue_noeud('\0');

    a->fg = alloue_noeud('d');
    a->fg->fils = alloue_noeud('e');
    a->fg->fils->fils = alloue_noeud('\0');

    a->fg->fils->fils->fils = alloue_noeud('s');
    a->fg->fils->fils->fils->fils = alloue_noeud('\0');

    a->fg->fd = alloue_noeud('e');
    a->fg->fd->fils = alloue_noeud('n');
    a->fg->fd->fils->fils = alloue_noeud('\0');

    a->fd = alloue_noeud('u');
    a->fd->fils = alloue_noeud('n');
    a->fd->fils->fils = alloue_noeud('\0');
*/


    insertion(&a, "le");
    insertion(&a, "la");
    insertion(&a, "les");
    insertion(&a, "leur");
    insertion(&a, "de");
    insertion(&a, "un");
    insertion(&a, "en");


/*
    printf("\n\n%d\n", recherche(a, "le"));
    printf("\n\n%d\n", recherche(a, "en"));
    printf("\n\n%d\n", recherche(a, "uhuhu"));
    printf("\n\n%d\n", recherche(a, "de"));
    printf("\n\n%d\n", recherche(a, "desf"));

*/

    affiche(a);


    a = suppression(a, "le");

    printf("\n");
    affiche(a);

    printf("%c %c %c\n", a->c, a->fils->c, a->fils->fils->c);

    return 0;
}