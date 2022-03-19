/* ouverture.h */

#ifndef __ouverture__
#define __ouverture__

    #include <stdio.h>

    int fichier_valide(char* fichier);
    int arguments_valides (int argc, char* argv[]);
    int taille_fichier(FILE* fichier);
    char* lecture_fichier(char* nom);

#endif
