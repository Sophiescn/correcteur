#ifndef __BK__
#define __Bk__

    typedef struct noeudBK{
        char* mot;
        int valeur;
        struct noeudBK* filsG; /* ?? */
        struct noeudBK* frereD;
    } NoeudBK, * ArbreBK;

    int inserer_dans_ArbreBK(ArbreBK * A, char * mot);
    
#endif
