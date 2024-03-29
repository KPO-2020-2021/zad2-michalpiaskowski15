#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp 
  {
    LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
    Operator     Oper;   // Opertor wyrazenia arytmetycznego
    LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  };


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


void Wyswietl(WyrazenieZesp  WyrZ);
LZespolona Obliczenia(WyrazenieZesp  &WyrZ);
std::ostream & operator << (std::ostream & s, WyrazenieZesp WyrZ);
std::ostream & operator << (std::ostream & s, Operator Oper);
#endif
