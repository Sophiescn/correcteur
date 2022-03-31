/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#include "ATR.h"
#include "ouverture.h"
#include "Liste.h"
#include "correcteur.h"
#include <stdio.h>


int main(int argc, char* argv[]) {
    ATR a;
    Liste l;
    Liste erreurs;
    char* dico, *liste;
    char* source_1, *source_2;
    int res;

    source_1 = argv[1];
    source_2 = argv[2];


    if (!(res = arguments_valides(argc, argv))) {
        return 0;
    }

    if (res == 1) {
        dico = lecture_fichier(source_1);
        liste = lecture_fichier(source_2);
    } else {
        dico = lecture_fichier(source_2);
        liste = lecture_fichier(source_1);
    }



    a = initialiser_ATR(dico);
    l = initialiser_liste(liste);

    erreurs = correction(l, a);

    printf("Mot(s) mal orthographie(s) :\n");
    if (erreurs) {
        afficher_liste(erreurs);
    } else {
        printf("aucun\n");
    }

    liberer_liste(&l);
    liberer_liste(&erreurs);
    liberer_ATR(&a);

    return 0;
}
