#include <iostream>
#include "Statystyki.hh"



/*
 *  Rozpoczety modul statystyki
 *  Wyswietla ilosc poprawnych odpowiedzi, oraz procentowy wynik testu
 */

void Statystyka(int Poprawne)
{
    std::cout << "Poprawne odpowiedzi:" << Poprawne << std::endl;
    std::cout << "Procent poprawnych odpowiedzi:" << (Poprawne/4)*100 << "%" << std::endl;
    
}

