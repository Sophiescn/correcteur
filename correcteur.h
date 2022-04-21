/* correcteur.h */

/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#ifndef __correcteur__
#define __correcteur__

    #include "Liste.h"
    #include "ArbreBK.h"
    #include "ATR.h"

    Cellule* correction(Cellule* liste, Noeud* dico, ArbreBK dicoB);
    Cellule* force_brute(char* mot, Liste liste_dico);
    ArbreBK correction_BK_aux(char* mot, ArbreBK a);
    Cellule* correction_BK(char* mot, ArbreBK dico);

#endif
