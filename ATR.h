/* ATR.h */

/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#ifndef __ATR__
#define __ATR__

    #define TAILLE_MOT 64

    typedef struct noeud {
        char c;
        struct noeud* fg;
        struct noeud* fd;
        struct noeud* fils;
    } Noeud, *ATR;

    ATR creer_ATR_vide();
    Noeud* alloue_arbre(char lettre);
    void liberer_ATR(ATR* A);
    void affiche_aux(ATR A, char buffer[], int position);
    void afficher_ATR(ATR A);
    int recherche(ATR A, char* mot);
    void ajoute_branche(ATR* A, char* mot);
    int inserer_dans_ATR(ATR* A, char* mot);
    void suppression_aux(ATR A, ATR* tmp, char* mot, char buffer[], int position);
    void supprimer_dans_ATR(ATR* A, char* mot);
    Noeud* initialiser_ATR(char* chaine);

#endif
