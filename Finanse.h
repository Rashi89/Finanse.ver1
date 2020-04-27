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
    const string NAZWA_PLIKU_Z_INCOMES;
    const string NAZWA_PLIKU_Z_EXPENSES;



public:
    Finanse(string nazwaPlikuZUzytkownikami,string nazwaPlikuZIncomes, string nazwaPlikuZExpenses) : usersMenager(nazwaPlikuZUzytkownikami),NAZWA_PLIKU_Z_INCOMES(nazwaPlikuZIncomes), NAZWA_PLIKU_Z_EXPENSES(nazwaPlikuZExpenses)
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
    void dodajIncome();
    void wyswietlWszystkieItemy();
    void wyswietlWszystkieDaty();
    void wyswietlItemyZTegoMiesiaca();
    void wyswietlItemyZPoprzedniegoMiesiaca();
    void obliczWydatkiZObecnegoMiesiaca();
    void obliczWydatkiZPoprzedniegoMiesiaca();
    void obliczWydatkiZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa);
    void wyswietlItemyZPodanegoZakresu();
    void sortowanie();
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();


};
