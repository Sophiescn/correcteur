/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 21-03-2022
* Modification :  03-04-2022 */

#include "ATR.h"
#include "ouverture.h"
#include "Liste.h"
#include "correcteur.h"
#include "levenshtein.h"
#include "ArbreBK.h"
#include <stdio.h>


int main(int argc, char* argv[]) {
    ATR a;
    Liste dico_liste;
    Liste l;
    Liste erreurs;
    Liste proposition;
    Cellule* courant_erreurs;
    Cellule* courant_proposition;
    char* dico, *liste;
    char* source_1, *source_2;
    int res;

    if (!(res = arguments_valides(argc, argv))) {
        return 0;
    }
    source_1 = argv[1];
    source_2 = argv[2];
    
    if (res == 1) {
        dico = lecture_fichier(source_1);
        liste = lecture_fichier(source_2);
    } else {
        dico = lecture_fichier(source_2);
        liste = lecture_fichier(source_1);
    }



    a = initialiser_ATR(dico);
    l = initialiser_liste(liste);
    dico_liste = initialiser_liste(dico);

    erreurs = correction(l, a, NULL);

    if (!erreurs) {
        printf("aucun\n");
        return 0;
    }

    courant_erreurs = erreurs;

    while (courant_erreurs) {

        proposition = force_brute(courant_erreurs->mot, dico_liste);
        courant_proposition = proposition;

    
        printf("Mot mal orthographie : %s\n", courant_erreurs->mot);
        printf("Proposition(s) : ");


        while (courant_proposition) {
            printf("%s ", courant_proposition->mot);
            courant_proposition = courant_proposition->next_cell;
        }
        printf("\n");
        liberer_liste(&proposition);


        courant_erreurs = courant_erreurs->next_cell;
    }

    liberer_liste(&l);
    liberer_liste(&erreurs);
    liberer_ATR(&a);

    return 0;
}

