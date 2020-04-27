#ifndef DATAMENAGER_H
#define DATAMENAGER_H
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "data.h"


using namespace std;

class DataMenager
{
    vector <Data> daty;

    void wyswietlDate(Data data);
    int pobierzIDNowejDaty();
    bool czyRokJestPrzestepny(int rok);
    bool czyDataJestPoprawna(int rok, int miesiac, int dzien);
    int zamienDateNaRok(string wpisanaData);
    int zamienDateNaMiesiac(string wpisanaData);
    int zamienDateNaDzien(string wpisanaData);
    string zamienDateNaNapisBezMyslnikow(string wpisanaData);
    int konwersjaStringNaInt(string liczba);
    string konwersjaIntNaString(int liczba);


public:
    Data podajDate(string wpisanaData);
    void wyswietlDaty();
    void sortowanie();
    Data pobierzDzisiejszaDate();
    string dzisiejszaData();
    string pobierzDzisiejszaDateJakoString(Data data);




};
#endif
