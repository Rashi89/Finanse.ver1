#ifndef PLIKIZINCOMES_H
#define PLIKIINCOMES_H
#include <iostream>
#include <vector>
//
#include "Income.h"
#include "Markup.h"

using namespace std;

class PlikiZIncomes
{
public:
    vector <Income> wczytajItemyZPliku(int idZalogowanegoUzytkownika);
    void dopiszItemDoPliku(Income income);
};
#endif
