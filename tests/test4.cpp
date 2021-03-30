#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test roznicy liczb zespolonych o wartosciach 0") {
    LZespolona x, y, t;
    
    x.re = 0;
    x.im = 0;

    y.re = 0;
    y.im = 0;

    t.re = 0;
    t.im = 0;
 
   CHECK(x+y==t);
}
TEST_CASE("Test roznicy liczb zespolonych o wartosciach 0.0"){
    LZespolona x, y, t;
    
    x.re = 0.0;
    x.im = 0.0;

    y.re = 0.0;
    y.im = 0.0;

    t.re = 0.0;
    t.im = 0.0;
    
    CHECK(x+y == t);
}
TEST_CASE("Test roznicy liczb zespolonych o wartosciach 0.0000"){
    LZespolona x, y, t;
    
    x.re = 0.0000;
    x.im = 0.0000;

    y.re = 0.0000;
    y.im = 0.0000;

    t.re = 0.0000;
    t.im = 0.0000;
    
    CHECK(x+y == t);
}