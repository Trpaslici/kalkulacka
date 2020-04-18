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
            factorial(A, &vysledek);
            return vysledek;
        }
        if (strcmp(argv[2], "invert") == 0) {
            invert(A, &vysledek);
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
            add(A, B, &vysledek);
            return vysledek;
        }
        if (strcmp(argv[2], "sub") == 0) {
            sub(A, B, &vysledek);
            return vysledek;
        }
        if (strcmp(argv[2], "mul") == 0) {
            mul(A, B, &vysledek);
            return vysledek;
        }
        if (strcmp(argv[2], "divid") == 0) {
            divid(A, B, &vysledek);
            return vysledek;
        }
        if (strcmp(argv[2], "pow") == 0) {
            pow(A, B, &vysledek);
            return vysledek;
        }
        if (strcmp(argv[2], "rad") == 0) {
            rad(A, B, &vysledek);
            return vysledek;
        }
        if (strcmp(argv[2], "komb") == 0) {
            komb(A, B, &vysledek);
            return vysledek;
        }
        else {
            fprintf(stderr, "spatne zadany argument");
        }
    }

    return 0;
}
