#include <iostream>
#include "Statystyki.hh"



/*
 *  Rozpoczety modul statystyki
 *  Wyswietla ilosc poprawnych i niepoprawnych odpowiedzi, oraz procentowy wynik testu
 */

void Statystyka(int poprawne, int niepoprawne, int ilosc_pytan, int wynik_proc)
{
    std::cout << "Ilosc poprawnych odpowiedzi" << poprawne << std::endl;
    std::cout << "Ilosc niepoprawnych odpowiedzi" << niepoprawne << std::endl;
    wynik_proc = poprawne/ilosc_pytan;
    std::cout << "Procentowy wynik testu: " << wynik_proc << std::endl;
}

