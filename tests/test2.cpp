#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 6;
    x.im = 4;

    y.re = 3;
    y.im = 2;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez LZespolona2") {
    LZespolona x, y, t;
    
    t.re = 2.4;
    t.im = (-0.8);
    
    x.re = 12;
    x.im = 4;

    y.re = 4;
    y.im = 3;
   
    CHECK(x/y == t);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}
TEST_CASE("Test LZespolona dzielenie przez LZespolona2") {
    LZespolona x, y;
    
    x.re = 12;
    x.im = 4;

    y.re = 0;
    y.im = 0;
   
    WARN_THROWS(x/y);
}

