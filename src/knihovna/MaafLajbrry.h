#pragma once

#define MaafLajbrryEpsilon 0.0000000000001//0.0001

class MaafLajbrry
{
public:
    /**
     * @brief MaafLajbrry
     * Konstruktor
     */
	MaafLajbrry();

    /**
     * @brief ~MaafLajbrry
     * Destruktor
     */
	~MaafLajbrry();
  
	double add(double a, double b);  //secte 2 cisla  
	double sub(double a, double b);  //odecte 2 cisla
	double mul(double a, double b);  //vynasobi 2 cisla
	double divid(double a, double b);  //vydeli 2 cisla
	long long factorial(int a);	//vypocita faktorial
	double pow(double a, double b);  //vypocita mocninu a^b
	double rad(double a, double b);    ////vypocita odmocninu b|/a
	long long komb(int a, int b); //vypocita kombinacni cislo a nad b

protected:
	double invert(double a); //vrati cislo s opacnym znamenkem
	int checkInt(double a); // zkontroluje, jestli je v promenne (double a) ulozeno cele cislo
	long long doubleToInt(double a); // prevede double na long long int

};

