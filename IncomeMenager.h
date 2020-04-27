#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "Income.h"
#include "data.h"
#include "DataMenager.h"
#include "PlikiZIncomes.h"
#include "MetodyPomocnicze.h"

using namespace std;

class IncomeMenager{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    vector <Data> daty;
    DataMenager dataMenager;
    PlikiZIncomes plikiZIncomes;

    Income podajNowyItem(char znak, string wpisanaData);
    int pobierzIdNowegoItemu();
    void wyswietlItem(Income income);
    void wyswietlIncomeZTegoMiesiaca(Income income);
    void wyswietlItemZPoprzedniegoMiesiaca(Income income);
    void sortowanieItemow(vector <Income> &income);
    void wyswietlIncomeZZakresu(string dataPoczatkowa,string dataKoncowa);

public:
    IncomeMenager(string nazwaPlikuZIncomes,int idZalogowanegoUzytkownika): plikiZIncomes(nazwaPlikuZIncomes),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        incomes= plikiZIncomes.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        daty = dataMenager.wczytajDaty(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };

    void dodajIncome();
    void wyswietlWszystkieIncome();
    void wyswietlIncomeZBiezacegoMiesiaca();
    void wyswietlIncomeZPoprzedniegoMiesiaca();
    void wyswietlIncomeZPodanegoZakresu(string dataPoczatkowa, string dataKoncowa);
    float obliczPrzychodyZObecnegoMiesiaca();
    float obliczPrzychodyZPoprzedniegoMiesiaca();
    float obliczPrzychodyZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa);
    bool czyWpisanaDataJestPoprawna(string data);
    void sortowanie();

};
#endif
