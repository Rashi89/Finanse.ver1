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
    void wyswietlItem(Income income);
    void wyswietlIncomeZTegoMiesiaca(Income income);
    void wyswietlItemZPoprzedniegoMiesiaca(Income income);
    int pobierzbiezacyMiesiac();

    void wyswietlIncomeZZakresu(string dataPoczatkowa,string dataKoncowa);

public:
    IncomeMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        incomes= plikiZIncomes.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        daty = dataMenager.wczytajDaty(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };

    void dodajIncome();
    void wyswietlWszystkieIncome();
    void wyswietlIncomeZBiezacegoMiesiaca();
    void wyswietlIncomeZPoprzedniegoMiesiaca();
    void wyswietlIncomeZPodanegoZakresu(string dataPoczatkowa, string dataKoncowa);
    int obliczPrzychodyZObecnegoMiesiaca();
    int obliczPrzychodyZPoprzedniegoMiesiaca();
    int obliczPrzychodyZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa);

    bool czyWpisanaDataJestPoprawna(string data);




    string wczytajLinie();
    float zamianaStringNaFloat(string liczba);
    string zamienKropkeNaPrzecinek(string liczba);



};
#endif
