#ifndef PLIKIZEXPENSES_H
#define PLIKIZEXPENSES_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
//
#include "Expense.h"
#include "Markup.h"
#include "data.h"
#include "DataMenager.h"

using namespace std;

class PlikiZExpenses
{
    DataMenager dataMenager;
    int konwersjaStringNaInt(string liczba);
public:
    vector <Expense> wczytajItemyZPliku(int idZalogowanegoUzytkownika);
    vector <Data> wczytajDatyZPliku(int idZalogowanegoUzytkownika);
    void dopiszItemDoPliku(Expense expense);
    float zamianaStringNaFloat(string liczba);
};
#endif
