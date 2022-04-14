#include "ArbreBK.h"
#include <stdlib.h>

NoeudBK* alloue_arbreBK(char* mot, int valeur) {
    NoeudBK* noeud;
    noeud = (NoeudBK*) malloc(sizeof(NoeudBK));
    if (noeud) {
        noeud->mot = mot;
        noeud->valeur = valeur;
        noeud->frereD = NULL;
        noeud->filsG = NULL;
    }
    return noeud;
}

int inserer_dans_ArbreBK(ArbreBK * A, char * mot) {
    if (!A) {
        *A = alloue_arbreBK(mot, 0);
        if (A) {
            return 1;
        }
        return 0;
    }
}
