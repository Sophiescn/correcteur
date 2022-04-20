/* ArbreBK.h */

#ifndef __BK__
#define __BK__

    typedef struct noeudBK {
        char* mot;
        int valeur;
        struct noeudBK* fils;
        struct noeudBK* frere;
    } NoeudBK, * ArbreBK;

    NoeudBK* alloue_arbreBK(char* mot, int leven);
    int inserer_dans_ArbreBK_suite(ArbreBK* A, char* mot, int leven);
    int inserer_dans_ArbreBK(ArbreBK * A, char * mot);
    int rechercher_dans_ArbreBK_aux(ArbreBK A, char* mot, int leven);
    int rechercher_dans_ArbreBK(ArbreBK A, char* mot);
    void libere_noeudBK(NoeudBK** A);
    void liberer_ArbreBK(ArbreBK* A);
    void afficher_ArbreBK_aux(ArbreBK A, int profondeur);
    void afficher_ArbreBK(ArbreBK A);
    ArbreBK initialiser_BK(char* chaine);
    
#endif
