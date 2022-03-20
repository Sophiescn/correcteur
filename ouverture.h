/* ouverture.h */

#ifndef __ouverture__
#define __ouverture__

    #include <stdio.h>

    int fichier_valide(char* fichier);
    int est_dictionnaire(char* chaine);
    int arguments_valides (int argc, char* argv[]);
    void ordonne_fichiers(int res, char* source_1, char* source_2);
    int taille_fichier(FILE* fichier);
    char* lecture_fichier(char* nom);

#endif
