#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyki.hh"


TEST_CASE("Sprawdzenie statystyki testu"){

    Statystyki s;

    s.ilosc_pytan = 4;
    s.poprawne = 3;
    s.niepoprawne = 1;

    float wynik=75;

    CHECK(Statystyka(s.poprawne, s.niepoprawne, s.ilosc_pytan)==wynik);
}