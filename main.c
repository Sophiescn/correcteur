#include "ATR.h"
#include "ouverture.h"
#include "Liste.h"
#include "correcteur.h"
#include <stdio.h>


int main(void) {
    ATR a;
    char* dico, *liste;
    char* source_1, *source_2;
    int res;
  
    source_1 = argv[1];
    source_2 = argv[2];
    if (!(res = arguments_valides(argc, argv))) {
        return 0;
    }

    ordonne_fichiers(res, source_1, source_2);

    dico = lecture_fichier("dico_1.dico");
    liste = lecture_fichier("a_corriger_0.txt");

    a = initialiser_ATR(dico);
    l = initialiser_liste(liste);

    erreurs = correction(l, a);

    printf("Mot(s) mal orthographié(s) :\n");
    if (erreurs) {
        afficher_liste(erreurs);
    }
    printf("aucun\n");
    return 0;
}
