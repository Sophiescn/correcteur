#include "ArbreBK.h"
#include "levenshtein.h"
#include "ATR.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

NoeudBK* alloue_arbreBK(char* mot, int leven) {
    NoeudBK* noeud;
    noeud = (NoeudBK*) malloc(sizeof(NoeudBK));
    if (noeud) {
        noeud->mot = mot;
        noeud->valeur = leven;
        noeud->fils = NULL;
        noeud->frere = NULL;
    }
    return noeud;
}

int inserer_dans_ArbreBK_suite(ArbreBK* A, char* mot, int leven) {
    ArbreBK temp = NULL;

    if (!(*A)) {
        *A = alloue_arbreBK(mot, leven);
        return 1;
    }

    if ((*A)->valeur == leven) {
        if (!strcmp((*A)->mot, mot)) {
            return 0;
        }
        leven = levenshtein((*A)->mot, mot);
        inserer_dans_ArbreBK_suite(&(*A)->fils, mot, leven);
        return 1;
    } else if ((*A)->valeur < leven) {
        inserer_dans_ArbreBK_suite(&(*A)->frere, mot, leven);
        return 1;
    } else if ((*A)->valeur > leven) {
        temp = (*A);
        *A = alloue_arbreBK(mot, leven);
        (*A)->frere = temp;
        return 1;
    }
    return 0;
}

int inserer_dans_ArbreBK(ArbreBK* A, char* mot) {
    int leven;

    if (!(*A)) {
        *A = alloue_arbreBK(mot, 0);
        return 1;
    }

    leven = levenshtein((*A)->mot, mot);

    if (inserer_dans_ArbreBK_suite(&(*A)->fils, mot, leven)) {return 1;}
    return 0;
}

int rechercher_dans_ArbreBK_aux(ArbreBK A, char* mot, int leven) {
    if (!A) {return 0;}

    if (!strcmp(A->mot, mot)) {return 1;}

    if (A->valeur == leven) {
        if (!strcmp(A->mot, mot)) {
            return 1;
        } else {
            return rechercher_dans_ArbreBK_aux(A->fils, mot, levenshtein(A->mot, mot));
        }
    } else {
        return rechercher_dans_ArbreBK_aux(A->frere, mot, leven);
    }
}

int rechercher_dans_ArbreBK(ArbreBK A, char* mot) {
    int leven;

    if (!A) {return 0;}

    if (!strcmp(A->mot, mot)) {return 1;}

    leven = levenshtein(A->mot, mot);

    return rechercher_dans_ArbreBK_aux(A->fils, mot, leven);
}

void libere_noeudBK(NoeudBK** A) {
    free(*A);
    *A = NULL;
}

void liberer_ArbreBK(ArbreBK* A) {
    assert(A);
    if ((*A)->fils) {
        liberer_ArbreBK(&(*A)->fils);
    }
    if ((*A)->frere) {
        liberer_ArbreBK(&(*A)->frere);
    }
    libere_noeudBK(A);
}

void afficher_ArbreBK_aux(ArbreBK A, int profondeur) {
    int i;

    if (!A) {return;}

    for (i = 0; i < profondeur; i++) {
        printf("        ");
    }

    printf("|--%d--> %s\n", A->valeur, A->mot);
    afficher_ArbreBK_aux(A->fils, profondeur + 1);
    afficher_ArbreBK_aux(A->frere, profondeur);
}

void afficher_ArbreBK(ArbreBK A) {
    if (!A) {return;}

    printf("%s\n", A->mot);

    afficher_ArbreBK_aux(A->fils, 0);
}

ArbreBK initialiser_BK(char* chaine) {
    int i, cmpt;
    char* mot = NULL;
    ArbreBK a;

    a = creer_ATR_vide();

    cmpt = 0;
    mot = (char*) malloc(sizeof(char) * (TAILLE_MOT) + 1);

    for (i = 0; i < strlen(chaine); i++) {
        if (chaine[i] == '\n') {
            mot[cmpt] = '\0';
            cmpt = 0;
            inserer_inserer_dans_ArbreBK(&a, mot);
            mot = (char*) malloc(sizeof(char) * (TAILLE_MOT) + 1);
        } else {
            mot[cmpt] = chaine[i];
            cmpt++;
        }
    }
    return a;
}

