#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

typedef struct{
    float poprawne=0;
    float niepoprawne=0;
    float ilosc_pytan=0;  
    float wynik_proc;
}Statystyki;
/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */
float Statystyka(int poprawne, int niepoprawne, int ilosc_pytan);
#endif
