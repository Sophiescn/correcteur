/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  03-04-2022*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
        return;
    }

    courant = L;
    while (courant) {
        printf("%s\n", courant->mot);
        courant = courant->next_cell;
    }
}

Cellule* initialiser_liste(char* chaine) {
    int i, cmpt;
    char* mot = NULL;
    Liste l = NULL;

    cmpt = 0;
    mot = (char*) malloc(sizeof(char) * (TAILLE_MOT) + 1);
    l = NULL;

    for (i = 0; i < strlen(chaine); i++) {
        if (chaine[i] == ' ' || chaine[i] == '\0' || chaine[i] == '\n') {
            mot[cmpt] = '\0';
            cmpt = 0;
            inserer_en_tete(&l, mot);
            mot = (char*) malloc(sizeof(char) * (TAILLE_MOT) + 1);
        } else {
            mot[cmpt] = chaine[i];
            cmpt++;
        }
    }
    return l;
}
