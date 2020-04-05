// --------------knihovna -------------------------

int add(int a, int b);  //secte 2 cisla
int sub(int a, int b);  //odecte 2 cisla
int mul(int a, int b);  //vynasobi 2 cisla
float divid(float a, float b);  //vydeli 2 cisla
int factorial(int a); //vypocita faktorial
float pow(float a, float b);  //vypocita mocninu a^b
float rad(float a, float b);    ////vypocita odmocninu b|/a

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
int factorial(int a){
    int pom = 1;
    if(a <= 0){
        fprintf(stderr, "Error, zadejte kladne cele cislo\n");
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
