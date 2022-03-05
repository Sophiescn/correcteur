#include <stdlib.h>
#include <stdio.h>
#include "Liste.h"


Cellule * allouer_Cellule(char * mot) {
    Cellule * cell = (Cellule*) malloc(sizeof(Cellule));
    if (!cell) {
        return NULL;
    }
    cell->mot = mot;
    cell->next_cell = NULL;
    return cell;
}


int inserer_en_tete(Liste * L, char * mot) {
    // fonction de merde avec un type de merde ca marche pas 
    Cellule* cell = allouer_Cellule(mot);
    if (!cell) {return 0;}
    cell->next_cell = *L;
    L = &cell;
    /*
     while (*L) {
        printf("%s\n", (*L)->mot);
        L = &((*L)->next_cell);
    }
    */
    return 1;
}

/*
int main(){
    char* mot = "pouet";
    char* mot2 = "pouetpouet";
    Liste l = allouer_Cellule(mot);
    inserer_en_tete(&l, mot2);


   


    return 0;
}
*/