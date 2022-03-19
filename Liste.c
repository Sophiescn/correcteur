#include <stdlib.h>
#include <stdio.h>
#include "Liste.h"


Cellule * allouer_Cellule(char * mot) {
    Cellule* cell = (Cellule*) malloc(sizeof(Cellule));
    if (!cell) {
        return NULL;
    }
    cell->mot = mot;
    cell->next_cell = NULL;
    return cell;
}

int inserer_en_tete(Liste* L, char * mot) {
    Cellule* cell = allouer_Cellule(mot);
    if (!cell) {return 0;}
    cell->next_cell = * L;
    * L = cell;
    return 1;
}

void liberer_liste(Liste* L) {
    Cellule* courant = *L;
    Cellule* suivant;

    while (courant) {
        suivant = courant->next_cell;
        free(courant);
        courant = suivant;
    }
    *L = NULL;
}

void afficher_liste(Liste L) {
    Cellule* courant;

    if (!L) {
        printf("null\n");
        return;
    }

    courant = L;
    while (courant) {
        printf("%s\n", courant->mot);
        courant = courant->next_cell;
    }
}
