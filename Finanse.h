#include <iostream>

#include "UsersMenager.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"

using namespace std;

class Finanse
{
    UsersMenager usersMenager;
    ExpenseMenager *expenseMenager;
    //DataMenager *dataMenager;

public:
    Finanse()
    {
        expenseMenager=NULL;
        //dataMenager=NULL;
    }
    ~Finanse()
    {
        delete expenseMenager;
        expenseMenager=NULL;
        //delete dataMenager;
        //dataMenager=NULL;

    }
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    void logowanieUzytownika();
    void wylogowanieZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajItem();
    void wyswietlWszystkieItemy();
    void wyswietlWszystkieDaty();
    void wyswietlItemyZTegoMiesiaca();
    void wyswietlItemyZPoprzedniegoMiesiaca();
    void obliczWydatkiZObecnegoMiesiaca();
    void obliczWydatkiZPoprzedniegoMiesiaca();
    void wyswietlItemyZPodanegoZakresu();
    void sortowanie();
};
