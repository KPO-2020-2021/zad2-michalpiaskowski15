#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <ostream>
#include <istream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona 
  {
    double   re;    /*! Pole repezentuje czesc rzeczywista. */
    double   im;    /*! Pole repezentuje czesc urojona. */
  };


/*Definicje*/

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);
bool  operator != (LZespolona  Skl1,  LZespolona  Skl2);


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
std::ostream & operator <<(std::ostream & s, LZespolona Skl1);
std::istream & operator >> (std::istream &StrWej, LZespolona &LZesp);

#endif
