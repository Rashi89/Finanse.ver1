#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "data.h"
#include "DataMenager.h"
#include "PlikiZIncomes.h"

using namespace std;

class IncomeMenager{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    vector <Data> daty;
    DataMenager dataMenager;
    PlikiZIncomes plikiZIncomes;

    Income podajNowyItem(char znak, string wpisanaData);
    int pobierzIdNowegoItemu();
    int konwersjaStringNaInt(string liczba);

public:
    IncomeMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        incomes= plikiZIncomes.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        daty = dataMenager.wczytajDaty(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };

    void dodajIncome();



    string wczytajLinie();



};
#endif
