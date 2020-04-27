#ifndef EXPENSEMENAGER_H
#define EXPENSEMENAGER_H
#include <iostream>
#include <vector>

#include "Expense.h"
#include "ExpenseMenager.h"
#include "PlikiZExpenses.h"
#include "Markup.h"
#include "DataMenager.h"

using namespace std;

class ExpenseMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Expense> expenses;
    vector <Data> daty;
    PlikiZExpenses plikiZExpenses;
    DataMenager dataMenager;

    Expense podajNowyItem();
    int pobierzIdNowegoItemu();
    void wyswietlItem(Expense expense);
    int konwersjaStringNaInt(string liczba);

public:
    ExpenseMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        expenses = plikiZExpenses.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
         daty = dataMenager.wczytajDaty(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajItem();
    void wyswietlWszystkieItemy();
    void wyswietlWszystkieDaty();
    void wyswietlDate(Data data);
    void sortowanie();
    void sortowanieItemow(vector <Expense> &incomes);


    string wczytajLinie();

};

#endif
