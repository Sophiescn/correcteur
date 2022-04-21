/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#include "correcteur.h"
#include "levenshtein.h"
#include "ArbreBK.h"
#include <stdio.h>

#define INF 999999999

Cellule* correction(Cellule* liste, Noeud* dico, ArbreBK dicoB) {
    Liste erreurs = NULL;
    Liste actuel;
    int version;
    if (dico) {
        version = 0;
    } else if (dicoB) {
        version = 1;
    } 

    actuel = liste;

    while (actuel) {
        if (!version) {
            if (recherche(dico, actuel->mot)) {
                actuel = actuel->next_cell;
                continue;
            }
        } else if (version == 1) {
            if (rechercher_dans_ArbreBK(dico, actuel->mot)) {
                actuel = actuel->next_cell;
                continue;
            }
        }
        inserer_en_tete(&erreurs, actuel->mot);
        actuel = actuel->next_cell;
    }

    return erreurs;
}

Cellule* force_brute(char* mot, Liste dico_liste) {
    Liste correction = NULL;
    Liste courant;
    int d, dmin;

    dmin = INF;

    courant = dico_liste;

    while (courant) {

        d = levenshtein(mot, courant->mot);

        if (d <= dmin) {
            if (d < dmin) {
                dmin = d;
                liberer_liste(&correction);
            }

            inserer_en_tete(&correction, courant->mot);
        }

        courant = courant->next_cell;
    }

    return correction;    
}

Cellule* correction_BK(char* mot, ArbreBK dico) {
    
}


