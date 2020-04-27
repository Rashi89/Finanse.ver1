#ifndef EXPENSEMENAGER_H
#define EXPENSEMENAGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "Expense.h"
#include "PlikiZExpenses.h"
#include "DataMenager.h"
#include "Markup.h"
#include "data.h"
#include "MetodyPomocnicze.h"

using namespace std;

class ExpenseMenager //:public DataMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Expense> expenses;
    vector <Data> daty;
    PlikiZExpenses plikiZExpenses;
    DataMenager dataMenager;

    Expense podajNowyItem(char znak, string wpisanaData);
    int pobierzIdNowegoItemu();
    void wyswietlItem(Expense expense);
    int konwersjaStringNaInt(string liczba);
    void wyswietlItemZTegoMiesiaca(Expense expense);
    void wyswietlItemZPoprzedniegoMiesiaca(Expense expense);
    int pobierzbiezacyMiesiac();
    void sortowanieItemow(vector <Expense> &expense);
    bool czyWpisanaDataJestPoprawna(string data);
    void wyswietlItemyZZakresu(string dataPoczatkowa,string dataKoncowa);
    void wyswietlDate(Data data);

public:
    ExpenseMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        expenses = plikiZExpenses.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        daty = dataMenager.wczytajDaty(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajItem();
    void wyswietlWszystkieItemy();
    void wyswietlWszystkieDaty();
    void wyswietlItemyZBiezacegoMiesiaca();
    void wyswietlItemyZPoprzedniegoMiesiaca();
    void sortowanie();
    float obliczWydatkiZObecnegoMiesiaca();
    float obliczWydatkiZPoprzedniegoMiesiaca();
    void wyswietlItemyZPodanegoZakresu(string dataPoczatkowa,string dataKoncowa);
    float obliczWydatkiZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa);


    float zamianaStringNaFloat(string liczba);
    string zamienKropkeNaPrzecinek(string liczba);


};

#endif
