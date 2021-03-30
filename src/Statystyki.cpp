#include <iostream>
#include "Statystyki.hh"



/*
 *  Rozpoczety modul statystyki
 *  Wyswietla ilosc poprawnych i niepoprawnych odpowiedzi, oraz procentowy wynik testu
 */



float Statystyka(int poprawne, int niepoprawne, int ilosc_pytan)
{
    float wynik_proc;
    std::cout << "Ilosc poprawnych odpowiedzi:   " << poprawne << std::endl;
    std::cout << "Ilosc niepoprawnych odpowiedzi:    " << niepoprawne << std::endl;
    wynik_proc = 100*poprawne/ilosc_pytan;
    std::cout << "Procentowy wynik testu:   " << wynik_proc << "%" << std::endl;
    return wynik_proc;
}


