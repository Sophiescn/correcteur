#include "ArbreBK.h"
#include "ouverture.h"
#include "Liste.h"
#include "correcteur.h"
#include "levenshtein.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
/*
    ArbreBK a = NULL;
    inserer_dans_ArbreBK(&a, "dans");
    inserer_dans_ArbreBK(&a, "du");
    inserer_dans_ArbreBK(&a, "foi");
    inserer_dans_ArbreBK(&a, "ville");
    inserer_dans_ArbreBK(&a, "marchande");
    inserer_dans_ArbreBK(&a, "premiere");
    inserer_dans_ArbreBK(&a, "de");
    inserer_dans_ArbreBK(&a, "la");
    inserer_dans_ArbreBK(&a, "une");
    inserer_dans_ArbreBK(&a, "fois");
    inserer_dans_ArbreBK(&a, "foie");
    inserer_dans_ArbreBK(&a, "qui");
    inserer_dans_ArbreBK(&a, "il");
    inserer_dans_ArbreBK(&a, "elle");
    inserer_dans_ArbreBK(&a, "ma");
    inserer_dans_ArbreBK(&a, "dit");
    inserer_dans_ArbreBK(&a, "vends");
    inserer_dans_ArbreBK(&a, "foix");
    inserer_dans_ArbreBK(&a, "se");
    inserer_dans_ArbreBK(&a, "est");
    inserer_dans_ArbreBK(&a, "je");
    inserer_dans_ArbreBK(&a, "et");
    inserer_dans_ArbreBK(&a, "que");
    inserer_dans_ArbreBK(&a, "etait");
    inserer_dans_ArbreBK(&a, "vendait");
    inserer_dans_ArbreBK(&a, "derniere");


    afficher_ArbreBK(a);

    printf("%d\n", rechercher_dans_ArbreBK(a, "dans"));
    printf("%d\n", rechercher_dans_ArbreBK(a, "elle"));
    printf("%d\n", rechercher_dans_ArbreBK(a, "erreur"));


    liberer_ArbreBK(&a);
    printf("suppression\n");
    afficher_ArbreBK(a);
    printf("%d\n", rechercher_dans_ArbreBK(a, "dans"));
    printf("%d\n", rechercher_dans_ArbreBK(a, "elle"));
    printf("%d\n", rechercher_dans_ArbreBK(a, "erreur"));
*/
    ArbreBK a;
    Liste dico_liste;
    Liste l;
    Liste erreurs;
    Liste proposition;
    Cellule* courant_erreurs;
    Cellule* courant_proposition;
    char* dico, *liste;
    char* source_1, *source_2;
    int res;

    /* verfication des arguments */
    if (!(res = arguments_valides(argc, argv))) {
        return 0;
    }
    source_1 = argv[1];
    source_2 = argv[2];
    /* remplissage des structures en fonction de l'ordre des fichiers */
    if (res == 1) {
        dico = lecture_fichier(source_1);
        liste = lecture_fichier(source_2);
    } else {
        dico = lecture_fichier(source_2);
        liste = lecture_fichier(source_1);
    }

    a = initialiser_BK(dico);
    l = initialiser_liste(liste);
    erreurs = correction(l, NULL, a);
    if (!erreurs) {
        printf("aucun\n");
        return 0;
    }





    return 0;
}

