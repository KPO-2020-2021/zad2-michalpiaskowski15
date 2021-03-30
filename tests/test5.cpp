#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test mnozenia liczby zespolonej przez wartosci zerowe") {
    LZespolona x, y, t;
    
    x.re = 6;
    x.im = 3;

    y.re = 0;
    y.im = 0;

    t.re = 0;
    t.im = 0;
    
   CHECK(x*y==t);
}
TEST_CASE("Test mnozenia liczby zespolonej przez (1+0i)") {
    LZespolona x, y, t;
    
    x.re = 6;
    x.im = 3;

    y.re = 1;
    y.im = 0;

    t.re = 6;
    t.im = 3;
    
   CHECK(x*y==t);
}
TEST_CASE("Test mnozenia liczby zespolonej przez (0+1i)") {
    LZespolona x, y, t;
    
    x.re = 6;
    x.im = 3;

    y.re = 0;
    y.im = 1;

    t.re = -3;
    t.im = 6;
    
   CHECK(x*y==t);
}
TEST_CASE("Test mnozenia liczby zespolonej przez (1+1i)") {
    LZespolona x, y, t;
    
    x.re = 6;
    x.im = 3;

    y.re = 1;
    y.im = 1;

    t.re = 3;
    t.im = 9;
    
   CHECK(x*y==t);
}