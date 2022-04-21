/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#include "correcteur.h"
#include "levenshtein.h"
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
            if (rechercher_dans_ArbreBK(dicoB, actuel->mot)) {
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

ArbreBK correction_BK_aux(char* mot, ArbreBK a) {
    ArbreBK courant, temp;
    int leven;

    courant = a;
    temp = a;
    leven = INF;

    while (courant) {
        if (leven > levenshtein(mot, courant->mot)) {
            leven = levenshtein(mot, courant->mot);
            temp = courant;
        }

        courant = courant->frere;
    }

    return temp;
}

Cellule* correction_BK(char* mot, ArbreBK a) {
    Liste correction = NULL;
    ArbreBK courant;
    int dmin;

    dmin = INF;

    courant = a;

    while (courant) {
        courant = correction_BK_aux(mot, courant);

        if (levenshtein(mot, courant->mot) <= dmin) {
            if (levenshtein(mot, courant->mot) < dmin) {
                dmin = levenshtein(mot, courant->mot);
                liberer_liste(&correction);
            }
            inserer_en_tete(&correction, courant->mot);
        }

        courant = courant->fils;
    }

    return correction;
}


