#include "ATR.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LETTRES 64

ATR creer_ATR_vide() {
    ATR arbre;
    arbre = NULL;
    return arbre;
}

Noeud* alloue_arbre(char lettre) {
    Noeud* noeud;
    noeud = (Noeud*) malloc(sizeof(Noeud));
    if (noeud) {
        noeud->c = lettre;
        noeud->fd = NULL;
        noeud->fils = NULL;
        noeud->fg = NULL;
    }
    return noeud;
}

void liberer_ATR(ATR* A) {
    if (!(*A)) {
        return;
    }
    if ((*A)->fg) {
        liberer_ATR(&(*A)->fd);
    }
    if ((*A)->fils) {
        liberer_ATR(&(*A)->fils);
    }
    if ((*A)->fd){
        liberer_ATR(&(*A)->fg);
    }
    free(*A);
    *A = creer_ATR_vide();
}

void affiche_aux(ATR A, char buffer[], int position) {
    if (A) {
        buffer[position] = A->c;
        if (A->c == '\0') {
            printf("%s\n", buffer);
            position--;
        }

        if (A->fils) {
            affiche_aux(A->fils, buffer, position + 1);
        }

        if (A->fg) {
            affiche_aux(A->fg, buffer, position);
        }

        if (A->fd) {
            affiche_aux(A->fd, buffer, position);
        }
    }
}

void afficher_ATR(ATR A) {
    char buffer[MAX_LETTRES];
    int position = 0;
    affiche_aux(A, buffer, position);
}

int recherche(ATR A, char* mot) {
    if (!A) {return 0;}
    if (mot[0] == '\0' && A->c == '\0') {return 1;}
    if (A->c == '\0') {return recherche(A->fils, mot);}
    if (mot[0] == A->c) {return recherche(A->fils, mot + 1);}
    if (mot[0] < A->c) {return recherche(A->fg, mot);}
    if (mot[0] > A->c) {return recherche(A->fd, mot);}
    return 0;
}

void ajoute_branche(ATR* A, char* mot) {
    if ((*A = alloue_arbre(mot[0]))) {
        if (mot[0] != '\0') {
            ajoute_branche(&((*A)->fils), mot + 1);
        }
    }
}

int inserer_dans_ATR(ATR* A, char* mot) {
    if (!(*A)) {
        ajoute_branche(A, mot);
        return 1;
    }
    if ((*A)->c == '\0' && mot[0] != '\0') {
        return inserer_dans_ATR(&(*A)->fils, mot);
    } else if (mot[0] == '\0') {
        (*A)->fils = alloue_arbre('\0');
    } else if ((*A)->c == mot[0]) {
        return inserer_dans_ATR(&(*A)->fils, mot + 1);
    } else if ((*A)->c < mot[0]) {
        return inserer_dans_ATR(&(*A)->fd, mot);
    } else if ((*A)->c > mot[0]) {
        return inserer_dans_ATR(&(*A)->fg, mot);
    }
    return 0;
}

void suppression_aux(ATR A, ATR* tmp, char* mot, char buffer[], int position) {
    if (A) {
        buffer[position] = A->c;
        if (A->c == '\0' && strcmp(buffer, mot)) {
            inserer_dans_ATR(tmp, buffer);
            position--;
        } else if (A->c == '\0') {
            position--;
        }

        if (A->fils) {
            suppression_aux(A->fils, tmp, mot, buffer, position + 1);
        }

        if (A->fg) {
            suppression_aux(A->fg, tmp, mot, buffer, position);
        }
        
        if (A->fd) {
            suppression_aux(A->fd, tmp, mot, buffer, position);
        }
    }
}

void supprimer_dans_ATR(ATR* A, char* mot) {
    char buffer[MAX_LETTRES];
    int position;
    ATR tmp;

    if (!recherche(*A, mot)) {return;}

    position = 0;
    tmp = creer_ATR_vide();
    suppression_aux(*A, &tmp, mot, buffer, position);
    *A = tmp;
    
}

Noeud* initialiser_ATR(char* chaine) {
    int i, cmpt;
    char* mot = NULL;
    ATR a;

    a = creer_ATR_vide();

    cmpt = 0;
    mot = (char*) malloc(sizeof(char) * (TAILLE_MOT) + 1);

    for (i = 0; i < strlen(chaine); i++) {
        if (chaine[i] == '\n') {
            mot[cmpt] = '\0';
            cmpt = 0;
            inserer_dans_ATR(&a, mot);
            mot = (char*) malloc(sizeof(char) * (TAILLE_MOT) + 1);
        } else {
            mot[cmpt] = chaine[i];
            cmpt++;
        }
    }
    return a;
}
