/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#include "correcteur.h"
#include "levenshtein.h"
#include <stdio.h>

#define INF 999999999

Cellule* correction(Cellule* liste, Noeud* dico) {
    Liste erreurs = NULL;
    Liste actuel;

    actuel = liste;

    while (actuel) {
        if (!recherche(dico, actuel->mot)) {
            inserer_en_tete(&erreurs, actuel->mot);
        }
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
