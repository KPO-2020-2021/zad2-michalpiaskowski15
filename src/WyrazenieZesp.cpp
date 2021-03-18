#include "WyrazenieZesp.hh"
#include <iomanip>
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */




void Wyswietl(LZespolona Skl1)
{ 
    std::cout << "(" << std::noshowpos << Skl1.re << std::showpos << Skl1.im << "i)" << std::noshowpos;
}

/*Wyswietlanie odpowiedniego operatora dla WZespolonego*/
std::ostream & operator << (std::ostream & s, Operator Oper)
    {
        switch (Oper)
            {
                case Op_Dodaj:
                return s << '+';
                break;

                case Op_Odejmij:
                return s << '-';
                break;

                case Op_Mnoz:
                return s << '*';
                break;

                case Op_Dziel:
                return s << '/';
                break;

                default:
                return s;
                break;
            }
    }
/************************************************************************************************************/

/*Wyswietlanie WZespolonego*/
std::ostream & operator << (std::ostream &s, WyrazenieZesp WyrZ)
    {
        return s << WyrZ.Arg1 << WyrZ.Oper << WyrZ.Arg2;
    }

/***********************************************************************************************************/
/*Wczytanie Operatora*/
std::istream & operator >> (std::istream &StrWej, Operator &Oper)
    {
        char symbol;
        StrWej >> symbol;
        switch (symbol)
            {
                case '+':
                Oper=Op_Dodaj;
                break;

                case '-':
                Oper=Op_Odejmij;
                break;

                case '*':
                Oper=Op_Mnoz;
                break;

                case '/':
                Oper=Op_Dziel;
                break;

                default:
                StrWej.setstate(std::ios::failbit);
                break;
            }
            return StrWej;
    }
/*********************************************************************************************************/
/*Wczytanie WZespolonego*/
std::istream & operator >> (std::istream &StrWej, WyrazenieZesp &WyrZ)
    {
        StrWej >> WyrZ.Arg1 >> WyrZ.Oper >> WyrZ.Arg2;
        return StrWej;
    }
/*Obliczenia na WZespolonych*/
LZespolona Obliczenia(WyrazenieZesp & WyrZ)
{
    LZespolona Dzialanie;
    switch(WyrZ.Oper)
        {
            case Op_Dodaj:
            Dzialanie = WyrZ.Arg1 + WyrZ.Arg2;
            break;

            case Op_Odejmij:
            Dzialanie = WyrZ.Arg1 - WyrZ.Arg2;
            break;

            case Op_Mnoz:
            Dzialanie = WyrZ.Arg1 * WyrZ.Arg2;
            break;

            case Op_Dziel:
            Dzialanie = WyrZ.Arg1 / WyrZ.Arg2;
            break;
        }
        return Dzialanie;
}
