#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <vector>

#include "Expense.h"
#include "ExpenseMenager.h"
#include "PlikiZExpenses.h"
#include "Markup.h"

using namespace std;

class ExpenseMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Expense> expenses;
    PlikiZExpenses plikiZExpenses;

    Expense podajNowyItem();
    int pobierzIdNowegoItemu();

public:
    ExpenseMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        expenses = plikiZExpenses.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajItem();


    string wczytajLinie();

};

#endif
