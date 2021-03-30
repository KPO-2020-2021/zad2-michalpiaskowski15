#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"


TEST_CASE("Test porownania takich samych liczb zespolonych") {
    LZespolona x, y;
    
    x.re = 6;
    x.im = 6;

    y.re = 6;
    y.im = 6;
 
   CHECK(x==y);
}

TEST_CASE("Test porownania roznych liczb zespolonych") {
    LZespolona x, y;
    
    x.re = 6;
    x.im = 6;

    y.re = 2;
    y.im = 2;
 
   CHECK_FALSE(x==y);
}
TEST_CASE("Test porownania minimalnie innych liczb zespolonych") {
    LZespolona x, y;
    
    x.re = 6;
    x.im = 6;

    y.re = 6.1;
    y.im = 6.1;
 
   CHECK_FALSE(x==y);
}
