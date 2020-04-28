#include <stdio.h>
#include "MaafLajbrry.h"
// ******propojeni projektu*****


double profiling();


int main() {
	double vysledek;
	vysledek = profiling();
	printf("%f\n", vysledek);

	return 0;
}


double profiling() {
	MaafLajbrry knihovna;
	double N = 0; //pocet cisel
	double prumer = 0;
	double suma = 0;
	double mocnina;
	double pom;
	double s; //odchylka

	double num;
	while (fscanf(stdin, "%lf", &num) != EOF) //nacita double do num, oddeluje se bilym znakem
	{
		prumer = knihovna.add(prumer, num);

		mocnina = knihovna.pow(num, 2);
		suma = knihovna.add(suma, mocnina);
		N++;
	}
	prumer = knihovna.divid(prumer, N);
	mocnina = knihovna.pow(prumer, 2);
	pom = knihovna.mul(N, mocnina);
	//N*prumer(x)^2
	pom = knihovna.sub(suma, pom);
	//suma - N*prumer(x)^2
	N--;
	s = knihovna.divid(pom, N);
	s = knihovna.rad(s, 2);

	return s;
}