/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#include "correcteur.h"
#include <stdio.h>

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
