#include "Finanse.h"
#include "UsersMenager.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"
#include "IncomeMenager.h"

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
        //dataMenager = new DataMenager(usersMenager.pobierzIdZalogowanegoUzytkownika());
        incomeMenager =  new IncomeMenager(usersMenager.pobierzIdZalogowanegoUzytkownika());

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
 void Finanse::wyswietlItemyZTegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->wyswietlItemyZBiezacegoMiesiaca();
    }
 }
  void Finanse::wyswietlItemyZPoprzedniegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->wyswietlItemyZPoprzedniegoMiesiaca();
    }
 }

 void Finanse::obliczWydatkiZObecnegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->obliczWydatkiZObecnegoMiesiaca();
    }
 }
 void Finanse::obliczWydatkiZPoprzedniegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->obliczWydatkiZPoprzedniegoMiesiaca();
    }
 }

  void Finanse::wyswietlItemyZPodanegoZakresu()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->wyswietlItemyZPodanegoZakresu();
    }
 }

void Finanse::wyswietlWszystkieDaty()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->wyswietlWszystkieDaty();
    }
}
void Finanse::sortowanie()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        expenseMenager->sortowanie();
    }
}

void Finanse::dodajIncome()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->dodajIncome();
    }
    else
    {
        cout<<"Aby dodac item nalezy sie zalogowac!"<<endl;
        system("pause");
    }
}
