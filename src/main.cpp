#include <iostream>
#include "BazaTestu.hh"






int main(int argc, char **argv)
{

  if (argc < 2) {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }


  
  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;
  
  WyrazenieZesp WyrZ;
  LZespolona Dzialanie;
  LZespolona Wprowadzona_Odpowiedz;
  Statystyki s;
  while (PobierzNastpnePytanie(&BazaT,&WyrZ)) {
    std::cout << WyrZ << std::endl;
    try
      {
        Dzialanie=Obliczenia(WyrZ);
      }
    catch (std::runtime_error& e) 
      {
        std::cout << "Nastapil wyjatek" << std::endl
                  << e.what();
        break;
      }
    int proby=0;
    do{
      std::cout << "Podaj odpowiedz: " << std::endl;
      std::cin >> Wprowadzona_Odpowiedz; 
      std::cout << std::endl;
      if(!std::cin.good())
        {
          std::cout << "Niestety, Twoja odpowiedz zapisana jest w zlym formacie!" << std::endl;
          std::cout << "(Poprawny zapis: (x+yi)" << std::endl;
          std::cin.clear();
          std::cin.ignore(1000, '\n');
          if(proby<3)
            {
              if(proby<2)
              {
               std::cout << "Sprobuj jeszcze raz! Wykorzystane proby:" << proby+1 << "/3" << std::endl; 
              }
              proby++;
            }
          if(proby==3)
          {
            std::cout << "Wykorzystales wszystkie proby. Poprawny zapis:" << std::endl;
            s.niepoprawne++;
            s.ilosc_pytan++;
            std::cout << Dzialanie << std::endl;
            break;
          }
        }
      else
        {
          if(Wprowadzona_Odpowiedz==Dzialanie)
            {
              std::cout << "Brawo! Udzieliles poprawnej odpowiedzi we wlasciwym formacie :3" << std::endl;
              s.poprawne++;
              s.ilosc_pytan++;
              break;
            }
          else if (Wprowadzona_Odpowiedz!=Dzialanie)
            {
              std::cout << "Bledna odpowiedz." << std::endl;
              s.niepoprawne++;
              s.ilosc_pytan++;
              break;
            }
        }
      }while(proby<=3);
      std::cout << "Teraz przejdziesz do kolejnego przykladu." << std::endl;
      
  }
  LZespolona z, z1, z2, z3, z4;
  z.re = 1;
  z.im = 1;
  z1.re = -1;
  z1.im = 1;
  z2.re = 0;
  z2.im = 1;
  z3.re = 0;
  z3.im = -1;
  z4.re = 0;
  z4.im = 0;



  std::cout << std::endl;
  std::cout << " Koniec testu" << std::endl;
  std::cout << s.ilosc_pytan << std::endl;
  Statystyka(s.poprawne, s.niepoprawne, s.ilosc_pytan);
  std::cout << std::endl;
  try
  {
    arg(z); arg(z1); arg(z2); arg(z3); arg(z4);
  }
  catch(std::exception& e)
  {
    std::cout << "wyjatek:" << e.what() << '\n';
  }
  

}
