#include "Finanse.h"
#include "UsersMenager.h"
#include "ExpenseMenager.h"

void Finanse::rejestracjaUzytkownika()
{
    usersMenager.rejestracjaUzytkownika();
}

void Finanse::wyswietlWszystkichUzytkownikow()
{
    usersMenager.wyswietlWszystkichUzytkownikow();
}

void Finanse::logowanieUzytownika()
{
    usersMenager.logowanieUzytkownika();
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager = new ExpenseMenager(usersMenager.pobierzIdZalogowanegoUzytkownika());
    }
}

void Finanse::wylogowanieZalogowanegoUzytkownika()
{
    usersMenager.wylogowanieZalogowanegoUzytkownika();
}

void Finanse::zmianaHaslaZalogowanegoUzytkownika()
{
    usersMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void Finanse::dodajItem()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->dodajItem();
    }
    else
    {
        cout<<"Aby dodac item nalezy sie zalogowac!"<<endl;
        system("pause");
    }
}

void Finanse::wyswietlWszystkieItemy()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->wyswietlWszystkieItemy();
    }
}
