/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  */

/* ATR.h */

#ifndef __ATR__
#define __ATR__

    include "Liste.h"

    typedef struct noeud {
        char c;
        struct noeud* fg;
        struct noeud* fd;
        struct noeud* fils;
    } Noeud, * ATR;


#endif