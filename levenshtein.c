#include "levenshtein.h"
#include <stdio.h>
#include <string.h>


int levenshtein(char* un, char* deux) {

    int mot1, mot2;
    int l1, l2, l3;

    mot1 = strlen(un);
    mot2 = strlen(deux);

    if (!mot1 || !mot2) {
        if (mot1) {return mot1;}
        else {return mot2;}
    }

    if (un[0] == deux[0]) {
        return levenshtein(un + 1, deux + 1);
    }

    l1 = levenshtein(un + 1, deux);
    l2 = levenshtein(un, deux + 1);
    l3 = levenshtein(un + 1, deux + 1);

    if (l1 <= l2 && l1 <= l3) {
        return 1 + l1;
    } else if (l2 <= l1 && l2 <= l3) {
        return 1 + l2;
    } else {
        return 1 + l3;
    }
}
