#include <limits.h>

// --------------knihovna -------------------------

int add(int a, int b);  //secte 2 cisla
int sub(int a, int b);  //odecte 2 cisla
int mul(int a, int b);  //vynasobi 2 cisla
float divid(float a, float b);  //vydeli 2 cisla
long long factorial(int a); //vypocita faktorial
float pow(float a, float b);  //vypocita mocninu a^b
float rad(float a, float b);    ////vypocita odmocninu b|/a
long long komb(int a, int b); //vypocita kombinacni cislo a nad b
double invert(double a); //vrati cislo s opacnym znamenkem

//----------------------------------------------------
int add(int a, int b){
    return (a + b);
}
//----------------------------------------------------
int sub(int a, int b){
    return (a - b);
}
//----------------------------------------------------
int mul(int a, int b){
    return (a * b);
}
//----------------------------------------------------
float divid(float a, float b){
    if(b == 0){
        fprintf(stderr,"Error, deleni nulou\n");
        return 1;
    }

    else {
        return (a / b);
    }
}
//----------------------------------------------------
long long factorial(int a){
    long long pom = 1;
    if(a < 0){
        fprintf(stderr, "Error, zadejte kladne cele cislo\n");
        exit(1);
    }
    else if(a == 0){
        return 1;
    }
    else{
        for(int i = a; i > 1; i--){
            pom = pom * i;
        }
    }
    return pom;
}
//----------------------------------------------------
float pow(float a, float b){
    float pom;

    if (a == 0){
        return 0;
    }
    if((b == 0) && (a > 0)){
        return 1;
    }
    if((b == 0) && (a < 0)){
        return -1;
    }
    if (b < 0){
        b = b * (-1);
        pom = a;
        while(b > 1){
            pom = pom * a;
            b--;
        }
    return (1 / pom);
    }
    else{
        pom = a;
        while(b > 1){
            pom = pom * a;
            b--;
        }
        return pom;
    }

}
//----------------------------------------------------
float rad(float a, float b){
    float Min = 1;
    float Max;
    float pom;
    float diff;
    float mocnina;

    if((((int)b % 2)== 0) && (a < 0)){      //neni lichou odmocninou a pod odmocninou je zaporne cislo
        fprintf(stderr, "Error, zaporne cislo pod odmocninou");
        return -1;
    }
    if(a > 0){      //kladna odmocnina
        Max = a;
        pom = (Min + Max)/2;
        do{
            mocnina = pow(pom, b);      //zkouska vysledku pomoci funkce pow, hledani pomocí puleni intervalu
            if(a > mocnina){

                Min = pom;
            }
            if(a < mocnina){
                Max = pom;
            }
            diff = pom;
            pom = (Min + Max)/2;
            diff = diff - pom;      //rodil mezi vypocty
            if(diff < 0){
                diff = diff * (-1); //abslutni hodnota rozdilu
            }
        }while(diff > 0.0001);
        return pom;
    }
    else{           // zaporna odmocnina
        Min = a;    //zaporna odmocnina se lisi prohozenymi hranicemi
        Max = 0;
        pom = (Min + Max)/2;
        do{
            mocnina = pow(pom, b);
            if(a > mocnina){

                Min = pom;
            }
            if(a < mocnina){
                Max = pom;
            }
            diff = pom;
            pom = (Min + Max)/2;
            diff = diff - pom;
            if(diff < 0){
                diff = diff * (-1);
            }
        }while(diff > 0.0001);
        return pom;
    }
}
//----------------------------------------------------
long long komb(int a, int b)
{
    long long citatel = 1;
    int opti_b = b;
    int max_a = 0;

    if(a < 0 || b < 0) // a, b musi byt z N_0
    {
        fprintf(stderr, "Math ERROR\n");
        exit(1);
    }

    else if(a < b) // a musi byt vetsi nez b
    {
        fprintf(stderr, "Math ERROR\n");
        exit(1);
    }

    else if(b == 0) // 'cokoliv' nad 0 = 1
        return 1;

    else if(a == b) // a nad a = 1
        return 1;

    else // jinak vypocitej jako: a nad b = (a*(a-1)*(a-2)*...*(a-b+1)) / factorial(b)
    {
        if(b > a/2) // a nad b = a nad (a-b) -- pokud je to vhodne
        {
        opti_b = a - b;
        }

        if(opti_b > 14) //pokud by b bylo vetsi, dochazelo by k chybe
        {
            fprintf(stderr, "Math ERROR\n");
            exit(1);
        }

        if(opti_b == 1) // 'cokoliv' nad 1 = 'cokoliv'
            return a;

        switch(opti_b) // osetreni preteceni promenne citatel (basically)
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
                max_a = INT_MAX; // obvykle 2 147 483 647
                break;
        }

        if(a > max_a)
        {
            fprintf(stderr, "Math ERROR\n");
            exit(1);
        }

        for(int i = a; i >= (a - opti_b + 1); i--) // nakonec samotny vypocet :)
        {
            citatel = i * citatel;
        }
        return (citatel / factorial(opti_b));
    }
}
//----------------------------------------------------
double invert(double a)
{
    if(a == 0)
        return 0;

    else
        return -a;
}
