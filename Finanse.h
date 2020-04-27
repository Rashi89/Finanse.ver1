#include <iostream>

#include "UsersMenager.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"
#include "IncomeMenager.h"

using namespace std;

class Finanse
{
    UsersMenager usersMenager;
    ExpenseMenager *expenseMenager;
    IncomeMenager   *incomeMenager;
    //DataMenager *dataMenager;

public:
    Finanse()
    {
        expenseMenager=NULL;
        incomeMenager=NULL;
        //dataMenager=NULL;
    }
    ~Finanse()
    {
        delete expenseMenager;
        expenseMenager=NULL;
        delete incomeMenager;
        incomeMenager=NULL;
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
    void obliczWydatkiZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa);
    void wyswietlItemyZPodanegoZakresu();
    void sortowanie();

    void dodajIncome();
};
