#include "Finanse.h"
#include "UsersMenager.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"
#include "IncomeMenager.h"
#include "MetodyPomocnicze.h"

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
        expenseMenager = new ExpenseMenager(NAZWA_PLIKU_Z_EXPENSES,usersMenager.pobierzIdZalogowanegoUzytkownika());
        //dataMenager = new DataMenager(usersMenager.pobierzIdZalogowanegoUzytkownika());
        incomeMenager =  new IncomeMenager(NAZWA_PLIKU_Z_INCOMES,usersMenager.pobierzIdZalogowanegoUzytkownika());

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
        incomeMenager->wyswietlWszystkieIncome();
    }
}
 void Finanse::wyswietlItemyZTegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->wyswietlIncomeZBiezacegoMiesiaca();
        expenseMenager->wyswietlItemyZBiezacegoMiesiaca();
    }
 }
  void Finanse::wyswietlItemyZPoprzedniegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->wyswietlIncomeZPoprzedniegoMiesiaca();
        expenseMenager->wyswietlItemyZPoprzedniegoMiesiaca();
    }
 }

 void Finanse::obliczWydatkiZObecnegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        float bilans = incomeMenager->obliczPrzychodyZObecnegoMiesiaca()-expenseMenager->obliczWydatkiZObecnegoMiesiaca();
       cout<<"Bilans z obecnego miesiaca: "<<bilans<<endl;
    }
 }
 void Finanse::obliczWydatkiZPoprzedniegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        float bilans = incomeMenager->obliczPrzychodyZPoprzedniegoMiesiaca()-expenseMenager->obliczWydatkiZPoprzedniegoMiesiaca();
        cout<<"Bilans z poprzedniego miesiaca: "<<bilans<<endl;
    }
 }

  void Finanse::wyswietlItemyZPodanegoZakresu()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        string dataPoczatkowa;
        string dataKoncowa;
        cout<<"Podaj date poczatkowa: ";
        cin>>dataPoczatkowa;
        cout<<"Podaj date koncowa: ";
        cin>>dataKoncowa;
        incomeMenager->wyswietlIncomeZPodanegoZakresu(dataPoczatkowa,dataKoncowa);
        expenseMenager->wyswietlItemyZPodanegoZakresu(dataPoczatkowa,dataKoncowa);
        if(incomeMenager->czyWpisanaDataJestPoprawna(dataPoczatkowa)==true && incomeMenager->czyWpisanaDataJestPoprawna(dataKoncowa)==true)
        {
           obliczWydatkiZPodanegoOkresu(dataPoczatkowa,dataKoncowa);
        }
    }
 }
 void Finanse::obliczWydatkiZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa)
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        float przychodyZTegoOkresu=incomeMenager->obliczPrzychodyZPodanegoOkresu(dataPoczatkowa,dataKoncowa);
       cout<<"Suma przychodow w podanym okresie: "<<przychodyZTegoOkresu<<endl;
       float wydatkiZTegoOkresu=expenseMenager->obliczWydatkiZPodanegoOkresu(dataPoczatkowa,dataKoncowa);
       cout<<"Suma wydatkow w podanym okresie: "<<wydatkiZTegoOkresu<<endl;
        float bilans = incomeMenager->obliczPrzychodyZPodanegoOkresu(dataPoczatkowa,dataKoncowa)-expenseMenager->obliczWydatkiZPodanegoOkresu(dataPoczatkowa,dataKoncowa);
        cout<<"Bilans z wybranego okresu: "<<bilans<<endl;
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
        incomeMenager->sortowanie();
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

bool Finanse::czyUzytkownikJestZalogowany()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
        return true;
    else
        return false;
}

char Finanse::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char Finanse::wybierzOpcjeZMenuUzytkownika()
{
    usersMenager.wybierzOpcjeZMenuUzytkownika();
}
