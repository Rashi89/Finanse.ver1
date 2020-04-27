#ifndef EXPENSEMENAGER_H
#define EXPENSEMENAGER_H
#include <iostream>
#include <vector>

#include "Expense.h"
#include "ExpenseMenager.h"

using namespace std;

class ExpenseMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Expense> expenses;

    Expense podajNowyItem();
    int pobierzIdNowegoItemu();

public:
    ExpenseMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        expenses = wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajItem();
    void dopiszItemDoPliku(Expense expense);
    vector <Expense> wczytajItemyZPliku(int idZalogowanegoUzytkownika);

     string wczytajLinie();

};

#endif
