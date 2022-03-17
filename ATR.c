#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LETTRES 64

typedef struct atr {
        char c;
        struct atr* fg;
        struct atr* fd;
        struct atr* fils;
    } ATR;

ATR creer_ATR_vide() {
    ATR arbre;
    arbre.fils = NULL;
    arbre.fd = NULL;
    arbre.fg = NULL;
    return arbre;
}

ATR* alloue_arbre(char lettre){
    ATR* arbre;
    arbre = (ATR*) malloc(sizeof(ATR));
    if (arbre) {
        arbre->c = lettre;
        arbre->fd = NULL;
        arbre->fils = NULL;
        arbre->fg = NULL;
    }
    return arbre;
}

void liberer_ATR(ATR* A) {
    if (!A) {
        return;
    }
    if (A->fd) {
        liberer_ATR(A->fd);
    }
    if (A->fils) {
        liberer_ATR(A->fils);
    }
    if (A->fg){
        liberer_ATR(A->fg);
    }
    free(A);
}

void affiche_aux(ATR* A, char buffer[], int position) {
    if (A) {
        buffer[position] = A->c;
        if (A->c == '\0') {
            printf("%s\n", buffer);
            position--;
        }

        if (A->fils) {
            affiche_aux(A->fils, buffer, position + 1);
        }

        if (A->fg) {
            affiche_aux(A->fg, buffer, position);
        }

        if (A->fd) {
            affiche_aux(A->fd, buffer, position);
        }
    }
}

void afficher_ATR(ATR A) {
    char buffer[MAX_LETTRES];
    int position = 0;
    affiche_aux(&A, buffer, position);
}

int recherche(ATR* A, char* mot) {
    if (!A) {return 0;}
    if (* mot == '\0') {return 1;}
    if (* mot == A->c) {return recherche(A->fils, mot + 1);}
    if (A->c == '\0') {return recherche(A->fils, mot);}
    if (* mot < A->c) {return recherche(A->fg, mot);}
    if (* mot > A->c) {return recherche(A->fd, mot);}
    return 0;
}

ATR* ajoute_branche(ATR* A, char* mot) {
    A = alloue_arbre(mot[0]);
    if (mot[0] == '\0') {
        return A;
    }
    return ajoute_branche(A, mot +1);
}

int inserer_dans_ATR(ATR* A, char* mot) {
    if (!A){
        A = ajoute_branche(A, mot);
        if (A) {return 1;}
        return 0;
    }
    if (A->c == '\0' && mot[0] != '\0') {
        return inserer_dans_ATR(A->fd, mot);
    }
    if (mot[0] == A->c) {
        /* le cas ou les mots commencent de la meme manière */
        return inserer_dans_ATR(A->fils, mot + 1);
    }
    if (mot[0] < A->c) {
        /* le cas ou le mot commence avec une lettre plus petite */
        return inserer_dans_ATR(A->fg, mot);
    }
    /* le cas ou le mot commence avec une lettre plus grande */
    return inserer_dans_ATR(A->fd, mot);
}





int main() {
    ATR* a = NULL;
    /*
    A = creer_ATR_vide();
    printf("fils : %p\n", A.fils);
    printf("fg : %p\n", A.fg);
    printf("fd : %p\n", A.fd);
    A = alloue_arbre(a);
    printf("lettre : %c\n", A->c);
    printf("fils : %p\n", A->fils);
    printf("fg : %p\n", A->fg);
    printf("fd : %p\n", A->fd);
    inserer_dans_ATR(A, "pouet");
    printf("%c\n", A->fils->c);
    //afficher_ATR(*A);
    */
    
    a = alloue_arbre('l');
    a->fils = alloue_arbre('e');
    a->fils->fils = alloue_arbre('\0');

    a->fils->fils->fils = alloue_arbre('s');
    a->fils->fils->fils->fils = alloue_arbre('\0');

    a->fils->fils->fils->fd = alloue_arbre('u');
    a->fils->fils->fils->fd->fils = alloue_arbre('r');
    a->fils->fils->fils->fd->fils->fils = alloue_arbre('\0');

    afficher_ATR(*a);
    inserer_dans_ATR(a, "la");
    printf("\n");
    afficher_ATR(*a);
    
    return 0;
}
