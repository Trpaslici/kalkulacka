/**
 * \file main.c
 *
 * \brief Hlavni zdrojovy soubor, ktery vola matematicke funkce
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "knihovna.h"

int main(int argc, char* argv[])
{
    double vysledek;
    double A;
    double B;

    if (argc < 3){ //nedosatek argumentu
        fprintf(stderr, "zadejte cislo");
        return 1;
    }
    if (argc > 4) { //moc argumentu
        fprintf(stderr, "spatny pocet argumentu");
        return 1;
    }
    if (argc == 3) {
        A = atof(argv[1]);

        if (strcmp(argv[2], "factorial") == 0) {
            vysledek = factorial(A);
            return vysledek;
        }
        if (strcmp(argv[2], "invert") == 0) {
            vysledek = invert(A);
            return vysledek;
        }
        else {
            fprintf(stderr, "spatne zadany argument");
        }
    }
    if (argc == 4) {
        A = atof(argv[1]);
        B = atof(argv[3]);

        if (strcmp(argv[2], "add") == 0) {
            vysledek = add(A, B);
            return vysledek;
        }
        if (strcmp(argv[2], "sub") == 0) {
            vysledek = sub(A, B);
            return vysledek;
        }
        if (strcmp(argv[2], "mul") == 0) {
            vysledek = mul(A, B);
            return vysledek;
        }
        if (strcmp(argv[2], "divid") == 0) {
            vysledek = divid(A, B);
            return vysledek;
        }
        if (strcmp(argv[2], "pow") == 0) {
            vysledek = pow(A, B);
            return vysledek;
        }
        if (strcmp(argv[2], "rad") == 0) {
            vysledek = rad(A, B);
            return vysledek;
        }
        if (strcmp(argv[2], "komb") == 0) {
            vysledek = komb(A, B);
            return vysledek;
        }
        else {
            fprintf(stderr, "spatne zadany argument");
        }
    }

    return 0;
}

/*** Konec souboru main.c ***/
