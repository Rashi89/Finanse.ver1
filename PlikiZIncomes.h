#ifndef PLIKIZINCOMES_H
#define PLIKIZINCOMES_H
#include <iostream>
#include <vector>
//
#include "Income.h"
#include "Markup.h"
#include "data.h"
#include "DataMenager.h"

using namespace std;

class PlikiZIncomes
{
    DataMenager dataMenager;
    int konwersjaStringNaInt(string liczba);
public:
    vector <Income> wczytajItemyZPliku(int idZalogowanegoUzytkownika);
    vector <Data> wczytajDatyZPliku(int idZalogowanegoUzytkownika);
    void dopiszItemDoPliku(Income income);
    float zamianaStringNaFloat(string liczba);
};
#endif
