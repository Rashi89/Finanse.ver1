#include <iostream>

#include "UsersMenager.h"
#include "ExpenseMenager.h"

using namespace std;

class Finanse
{
    UsersMenager usersMenager;
    ExpenseMenager *expenseMenager;

public:
    Finanse()
    {
        expenseMenager=NULL;
    }
    ~Finanse()
    {
        delete expenseMenager;
        expenseMenager=NULL;
    }
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    void logowanieUzytownika();
    void wylogowanieZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajItem();
};
