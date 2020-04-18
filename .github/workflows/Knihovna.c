#include "knihovna.h"

// --------------knihovna -------------------------


double add(double a, double b, double* vysledek) { // secte 2 cisla
    *vysledek = (a + b);
    return 0;
}
//----------------------------------------------------
double sub(double a, double b, double* vysledek) { // odecte 2 cisla
    *vysledek = (a - b);
    return 0;
}
//----------------------------------------------------
double mul(double a, double b, double* vysledek) { // vynasobi 2 cisla
    *vysledek = (a * b);
    return 0;
}
//----------------------------------------------------
double divid(double a, double b, double* vysledek) { // vydeli 2 cisla
    if (b == 0) {
        fprintf(stderr, "Error, deleni nulou\n");
        return 1;
    }

    else {
        *vysledek = (a / b);
        return 0;
    }
}
//----------------------------------------------------
long long factorial(int a, double* vysledek) { // vrati faktorial celeho kladneho cisla
    long long pom = 1;
    if (a < 0) {
        fprintf(stderr, "Error, zadejte kladne cele cislo\n");
        return 1;
    }
    else if (a > 20) {
        fprintf(stderr, "Error, zadejte kladne cele cislo\n");
        return 1;
    }
    else if (a == 0) {
        *vysledek = 1;
        return 0;
    }
    else {
        for (int i = a; i > 1; i--) {
            pom = pom * i;
        }
    }
    *vysledek = (double)pom;
    return 0;
}
//----------------------------------------------------
double pow(double a, double b, double* vysledek) { // vypocita mocninu a^b
    double pom;

    if (a == 0) {
        *vysledek = 0;
        return 0;
    }
    if ((b == 0) && (a > 0)) {
        *vysledek = 1;
        return 0;
    }
    if ((b == 0) && (a < 0)) {
        return 1;
    }
    if (b < 0) {
        b = b * (-1);
        pom = a;
        while (b > 1) {
            pom = pom * a;
            b--;
        }
        *vysledek = (1 / pom);
        return 0;
    }
    else {
        pom = a;
        while (b > 1) {
            pom = pom * a;
            b--;
        }
        *vysledek = pom;
        return 0;
    }

}
//----------------------------------------------------
double rad(double a, double b, double* vysledek) { // vypocita odmocninu b|/a
    double Min = 1;
    double Max;
    double pom;
    double diff;
    double mocnina;

    if ((((long long)b % 2) == 0) && (a < 0)) {      //neni lichou odmocninou a pod odmocninou je zaporne cislo
        fprintf(stderr, "Error, zaporne cislo pod odmocninou");
        return 1;
    }
    if (a > 0) {      //kladna odmocnina
        Max = a;
        pom = (Min + Max) / 2;
        do {
            pow(pom, b, &mocnina);      //zkouska vysledku pomoci funkce pow, hledani pomocí puleni intervalu
            if (a > mocnina) {

                Min = pom;
            }
            if (a < mocnina) {
                Max = pom;
            }
            diff = pom;
            pom = (Min + Max) / 2;
            diff = diff - pom;      //rodil mezi vypocty
            if (diff < 0) {
                diff = diff * (-1); //abslutni hodnota rozdilu
            }
        } while (diff > 0.0001);
        *vysledek = pom;
        return 0;
    }
    else {           // zaporna odmocnina
        Min = a;    //zaporna odmocnina se lisi prohozenymi hranicemi
        Max = 0;
        pom = (Min + Max) / 2;
        do {
            pow(pom, b, &mocnina);
            if (a > mocnina) {

                Min = pom;
            }
            if (a < mocnina) {
                Max = pom;
            }
            diff = pom;
            pom = (Min + Max) / 2;
            diff = diff - pom;
            if (diff < 0) {
                diff = diff * (-1);
            }
        } while (diff > 0.0001);
        *vysledek = pom;
        return 0;
    }
}
//----------------------------------------------------
long long komb(int a, int b, double* vysledek) // vypocita kombinacni cislo a nad b
{
    long long citatel = 1;
    int opti_b = b;
    int max_a = 0;

    if (a < 0 || b < 0) // a, b musi byt z N_0
    {
        fprintf(stderr, "Math ERROR\n");
        return 1;
    }

    else if (a < b) // a nesmi byt mensi nez b
    {
        fprintf(stderr, "Math ERROR\n");
        return 1;
    }

    else if (b == 0) {// 'cokoliv' nad 0 = 1
        *vysledek = 1;
        return 0;
    }

    else if (a == b) {// a nad a = 1
        *vysledek = 1;
        return 0;
    }

    else // jinak vypocitej jako: a nad b = (a*(a-1)*(a-2)*...*(a-b+1)) / factorial(b)
    {
        if (b > a / 2) // a nad b = a nad (a-b) -- pokud je to vhodne
        {
            opti_b = a - b;
        }

        if (opti_b > 14) //pokud by b bylo vetsi nez 14, dochazelo by k chybe
        {
            fprintf(stderr, "Math ERROR\n");
            return 1;
        }

        if (opti_b == 1) { // 'cokoliv' nad 1 = 'cokoliv'
            *vysledek = a;
            return 0;
        }

        switch (opti_b) // osetreni preteceni promenne citatel (basically)
        {
        case 14:        // pokud b = 14, potom a muze byt maximalne 29
            max_a = 29;
            break;
        case 13:        // atd...
            max_a = 35;
            break;
        case 12:
            max_a = 42;
            break;
        case 11:
            max_a = 58;
            break;
        case 10:
            max_a = 83;
            break;
        case 9:
            max_a = 132;
            break;
        case 8:
            max_a = 238;
            break;
        case 7:
            max_a = 515;
            break;
        case 6:
            max_a = 1450;
            break;
        case 5:
            max_a = 6210;
            break;
        case 4:
            max_a = 55110;
            break;
        case 3:
            max_a = 2097153;
            break;
        case 2:
            max_a = INT_MAX; // obvykle 2 147 483 647 == (0111 1111 1111 1111 1111 1111 1111 1111)binary
            break;
        }

        if (a > max_a)
        {
            fprintf(stderr, "Math ERROR\n");
            return 1;
        }

        for (int i = a; i >= (a - opti_b + 1); i--) // nakonec samotny vypocet :)
        {
            citatel = i * citatel;
        }
        double pom;
        factorial(opti_b, &pom);
        *vysledek = (citatel / pom);
        return 0;
    }
}
//----------------------------------------------------
double invert(double a, double* vysledek) // vrati cislo s opacnym znamenkem
{
    if (a == 0) {
        *vysledek = 0;
        return 0;
    }

    else {
        *vysledek = -a;
        return 0;
    }
}
//----------------------------------------------------
int checkInt(double a, double* vysledek) // zkontroluje, jestli je v double a ulozeno cele cislo
{
    if (a - (long long)a == 0) {
        *vysledek = 1;
        return 0;
    }
    else {
        *vysledek = 0;
        return 0;
    }
}
//----------------------------------------------------
long long doubleToInt(double a, long long* vysledek) // prevede double na long long int
{
    *vysledek = (long long)a;
    return 0;
}
