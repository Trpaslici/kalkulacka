#include <stdio.h>
#include "knihovna.c"
// ******propojeni projektu*****


double profiling();


int main() {
    double vysledek;
    vysledek = profiling();
    printf("%f\n", vysledek);

    return 0;
}


double profiling() {
    double N = 0; //pocet cisel
    double prumer = 0;
    double suma = 0;
    double mocnina;
    double pom;
    double s; //odchylka

    double num;
    while (fscanf(stdin, "%lf", &num) != EOF) //nacita double do num, oddeluje se bilym znakem
    {
        prumer = add(prumer, num);

        mocnina = pow(num, 2);
        suma = add(suma, mocnina);
        N++;
    }
    prumer = divid(prumer, N);
    mocnina = pow(prumer, 2);
    pom = mul(N, mocnina);
    //N*prumer(x)^2
    pom = sub(suma, pom);
    //suma - N*prumer(x)^2
    N--;
    s = divid(pom, N);
    s = rad(s, 2);

    return s;
}
