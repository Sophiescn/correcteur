/* correcteur.h */

/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#ifndef __correcteur__
#define __correcteur__

    #include "Liste.h"
    #include "ATR.h"

    Cellule* correction(Cellule* liste, Noeud* dico);
    Cellule* force_brute(char* mot, Liste liste_dico);
    Cellule* correction_BK(char* mot, ArbreBK dico);

#endif
