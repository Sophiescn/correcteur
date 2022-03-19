/* Liste.h */

/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  */

#ifndef __Liste__
#define __Liste__

    typedef struct cellule {
        char* mot;
        struct cellule* next_cell;
    } Cellule, * Liste;

    Cellule * allouer_Cellule(char * mot);
    int inserer_en_tete(Liste* L, char * mot);
    void liberer_liste(Liste* L);
    void afficher_liste(Liste L);

#endif
