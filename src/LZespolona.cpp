#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */
int poprawne=0;
int niepoprawne=0;
int ilosc_pytan=0;
bool  operator != (LZespolona  Skl1,  LZespolona  Skl2){
  if ((Skl1.re != Skl2.re)||(Skl1.im != Skl2.im))
    {
      return true;
    }
  else {
    return false;
  }
}

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    {
      poprawne++;
      ilosc_pytan++;
      return true;
    }
  else {
    niepoprawne++;
    ilosc_pytan++;
    return false;
  }
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  /*
  if abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF
    return true;
  else
    return false;
  */
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

/*
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = ((Skl1.re*Skl1.im)-(Skl2.re*Skl2.im));
  Wynik.im = ((Skl1.re*Skl2.im)+(Skl2.re*Skl1.im));
  return Wynik;
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  if (((pow(Skl2.re, 2)+pow(Skl2.im, 2)==0))) 
    {
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }
  if (((pow(Skl2.re, 2)+pow(Skl2.im, 2)!=0))) 
    {
      Wynik.re = ((Skl1.re*Skl2.re)+(Skl1.im*Skl2.im))/(pow(Skl2.re, 2)+pow(Skl2.im, 2));           /*korzystam z przeksztalconego wzoru sprzezenia*/
      Wynik.im = ((Skl1.im*Skl2.re)-(Skl1.re*Skl2.im))/(pow(Skl2.re, 2)+pow(Skl2.im, 2));
    }
  return Wynik;
}


/* Wyswietl LZespolona*/
std::ostream & operator <<( std::ostream & s, LZespolona Skl1 )
{
    return s << "(" << std::noshowpos << Skl1.re << std::showpos << Skl1.im << "i)" << std::noshowpos;
}

/*Wczytaj LZespolona*/
std::istream & operator >> (std::istream &StrWej, LZespolona &LZesp)
{
  char Nawias, Litera;
  StrWej >> Nawias;
  if (StrWej.fail())
    return StrWej;
  if (Nawias != '(')
    {
      StrWej.setstate(std::ios::failbit);
      return StrWej;
    }
  StrWej >> LZesp.re;
  if (StrWej.fail())
    return StrWej;
  StrWej >> LZesp.im;
  if (StrWej.fail())
    return StrWej;
  StrWej >> Litera;
  if (StrWej.fail())
    return StrWej;
  if (Litera !='i')
    {
      StrWej.setstate(std::ios::failbit);
      return StrWej;
    }
  StrWej >> Nawias;
  if(StrWej.fail())
    return StrWej;
  if (Nawias !=')')
    {
      StrWej.setstate(std::ios::failbit);
      return StrWej;
    }
  return StrWej;
}

