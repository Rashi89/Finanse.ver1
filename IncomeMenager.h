#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "data.h"
#include "DataMenager.h"

using namespace std;

class IncomeMenager{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    vector <Data> daty;
    DataMenager dataMenager;

public:
    IncomeMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        daty = dataMenager.wczytajDaty(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };



};
#endif
