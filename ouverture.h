/* ouverture.h */

/* Auteur : Quentin Benesby Sophie Cousson
* Creation : 05-03-2022
* Modification :  20-03-2022*/

#ifndef __ouverture__
#define __ouverture__

    #include <stdio.h>

    int fichier_valide(char* fichier);
    int est_dictionnaire(char* chaine);
    int arguments_valides (int argc, char* argv[]);
    int taille_fichier(FILE* fichier);
    char* lecture_fichier(char* nom);

#endif
