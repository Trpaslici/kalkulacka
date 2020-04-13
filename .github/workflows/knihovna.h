#ifndef KNIHOVNA_H_INCLUDED
#define KNIHOVNA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// --------------matematicke funkce-------------------------
/**
 * Secte 2 realna cisla
 * \param a prvni cislo
 * \param b druhe cislo
 * \return (a+b)
 */
double add(double a, double b);
//----------------------------------------------------------
/**
 * Odecte od sebe 2 realna cisla
 * \param a prvni cislo
 * \param b druhe cislo
 * \return (a-b)
 */
double sub(double a, double b);
//----------------------------------------------------------
/**
 * Vynasobi 2 realna cisla
 * \param a prvni cislo
 * \param b druhe cislo
 * \return (a*b)
 */
double mul(double a, double b);
//----------------------------------------------------------
/**
 * Vydeli 2 realna cisla
 * \param a delenec
 * \param b delitel
 * \if (b == 0)
 *      Vrati chybu a ukonci se
 * \endif
 * \return (a/b)
 */
double divid(double a, double b);
//----------------------------------------------------------
/**
 * Vypocita faktorial celeho kladneho cisla
 * \pre Pred uzitim funkce by mel volajici overit, zda parametr a je cele cislo
 * \param a cele kladne cislo
 * \if (a < 0)
 *      Vrati chybu a ukonci se
 * \endif
 * \if (a > 20)
 *      Vrati chybu a ukonci se
 * \endif
 * \return 1 pokud a == 0
 * \return a!
 */
long long factorial(int a);
//----------------------------------------------------------
/**
 * Vypocita mocninu a^b
 * \param a mocnenec
 * \param b mocnitel
 * \return 0 pokud a ==  0
 * \return 1 pokud b == 0 && a > 0
 * \return -1 pokud b == 0 && a < 0
 * \return a^b
 */
double pow(double a, double b);
//----------------------------------------------------------
/**
 * Vypocita odmocninu b|/a
 * \param a odmocnenec
 * \param b odmocnitel
 * \if (zaporne cislo pod sudou odmocninou)
 *      Vrati chybu a ukonci se
 * \endif
 * \return b|/a
 */
double rad(double a, double b);
//----------------------------------------------------------
/**
 * Vypocita kombinacni cislo a nad b
 * == pocet zpusobu, jak vybrat b-prvkovou podmnozinu z a-prvkove mnoziny
 * a nad b = (a*(a-1)*(a-2)*...*(a-b+1)) / b!
 * \pre Pred uzitim funkce by mel volajici overit, zda jsou parametry a, b cela cisla
 * \param a pocet prvku puvodni mnoziny
 * \param b pocet prvku hledane podmnoziny
 * \if (a < 0 nebo b < 0)
 *      Vrati chybu a ukonci se
 * \endif
 * \if (a < b)
 *      Vrati chybu a ukonci se
 * \endif
 * \return 1 pokud b = 0
 * \return 1 pokud a = b
 * \if (a nebo b je mimo povoleny rozsah)
 *      Vrati chybu a ukonci se
 * \endif
 * \return (a nad b)
 */
long long komb(int a, int b);
//----------------------------------------------------------
/**
 * Vrati cislo s opacnym znamenkem
 * \param a libovolne realne cislo
 * \return 0 pokud a == 0
 * \return -a
 */
double invert(double a);

// -----------------utilities-------------------------------

/**
 * Zkontroluje, jestli je v promenne a ulozeno cele cislo
 * \param a zkoumane cislo
 * \return 1 pokud se jedna o cele cislo
 * \return 0 pokud se nejedna o cele cislo
 */
int checkInt(double a);
//----------------------------------------------------------
/**
 * Prevede double na long long int
 * \pre Pred uzitim funkce by mel volajici overit, jestli je v promenne a ulozeno cele cislo
 * \param a libovolne realne cislo
 * \return (long long)a
 */
long long doubleToInt(double a);

#endif // KNIHOVNA_H_INCLUDED
