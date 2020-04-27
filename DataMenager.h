#ifndef DATAMENAGER_H
#define DATAMENAGER_H
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "data.h"
#include "Expense.h"
//#include "IncomeMenager.h"

using namespace std;

class DataMenager
{
    //vector <Data> daty;
    bool czyRokJestPrzestepny(int rok);
    int pobierzIDNowejDaty();
    int konwersjaStringNaInt(string liczba);
    string konwersjaIntNaString(int liczba);
    string pobierzDzisiejszaDateJakoString(Data data);
    //string zamienDateNaNapisBezMyslnikow(string wpisanaData);
    string dzisiejszaData();

    int dzisiejszaDataJakoInt();
    int obliczIleDniMaObecnyMiesiac();
    int ostatniaDataWObecnymMiesiacuJakoInt();

public:
    DataMenager(){
        //daty = wczytajDaty(int idZalogowanegoUzytkownika);
    }
    vector <Data> wczytajDaty(int idZalogowanegoUzytkownika);
    string zamienDateNaNapisBezMyslnikow(string wpisanaData);
    bool czyDataJestZPrzedzialu(string wpisanaData);
    Data pobierzDzisiejszaDate();
    bool podajDate(string wpisanaData);
    int zamienDateNaRok(string wpisanaData);
    int zamienDateNaMiesiac(string wpisanaData);
    int zamienDateNaDzien(string wpisanaData);
    bool czyDataJestPoprawna(int rok, int miesiac, int dzien);

};
#endif
