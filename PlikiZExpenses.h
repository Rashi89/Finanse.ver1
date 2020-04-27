#ifndef PLIKIZEXPENSES_H
#define PLIKIZEXPENSES_H
#include <iostream>
#include <vector>
//
#include "Expense.h"
#include "Markup.h"

using namespace std;

class PlikiZExpenses
{
public:
    vector <Expense> wczytajItemyZPliku(int idZalogowanegoUzytkownika);
    void dopiszItemDoPliku(Expense expense);
};
#endif
