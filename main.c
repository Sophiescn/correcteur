#include "ATR.h"
#include <stdio.h>


int main(void) {
    Liste l;
    ATR a;
    char* chaine;

    
/* creer un liste a partir de a_corriger_0.txt */
    chaine = lecture_fichier("a_corriger_0.txt");
    
    l = initialiser_liste(chaine);
    afficher_liste(l);
    
    
    
    
    a = creer_ATR_vide();
 
    a = alloue_arbre('l');
    a->fils = alloue_arbre('e');
    a->fils->fils = alloue_arbre('\0');
    afficher_ATR(a);

/* inserer */

    inserer_dans_ATR(&a, "les");
    inserer_dans_ATR(&a, "lese");
    printf("\n");
    afficher_ATR(a);
    printf("\n");

/* supprimer */

    supprimer_dans_ATR(&a, "lese");
    afficher_ATR(a);


/* liberer */

    liberer_ATR(&a);
    printf("\n");
    inserer_dans_ATR(&a, "final");
    inserer_dans_ATR(&a, "oksuper");
    afficher_ATR(a);


    /*
    printf("%d %d %d\n", recherche(a, "le"), recherche(a, "les"), recherche(a, "de"));
    */


    return 0;
}
