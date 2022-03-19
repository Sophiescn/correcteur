#include "ATR.h"
#include "ouverture.h"
#include "Liste.h"
#include "correcteur.h"
#include <stdio.h>


int main(void) {
    ATR a;
    Liste l;
    Liste erreurs;
    char* dico;
    char* liste;

    dico = lecture_fichier("dico_1.dico");
    liste = lecture_fichier("a_corriger_0.txt");

    a = initialiser_ATR(dico);
    l = initialiser_liste(liste);

    erreurs = correction(l, a);

    afficher_liste(erreurs);



    /*
    LISTE


    Liste l;
    char* chaine;

    chaine = lecture_fichier("a_corriger_0.txt");
    
    l = initialiser_liste(chaine);
    afficher_liste(l);
    */
    

    /*
    ATR


    ATR a;
    a = creer_ATR_vide();
 
    a = alloue_arbre('l');
    a->fils = alloue_arbre('e');
    a->fils->fils = alloue_arbre('\0');
    afficher_ATR(a);

    inserer_dans_ATR(&a, "les");
    inserer_dans_ATR(&a, "lese");
    printf("\n");
    afficher_ATR(a);
    printf("\n");

    supprimer_dans_ATR(&a, "lese");
    afficher_ATR(a);

    liberer_ATR(&a);
    printf("\n");
    inserer_dans_ATR(&a, "final");
    inserer_dans_ATR(&a, "oksuper");
    afficher_ATR(a);
    */

    return 0;
}
