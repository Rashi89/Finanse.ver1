#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Data
{
    string dataZMyslnikami;
    int id;
    int rok;
    int miesiac;
    int dzien;
    int dataBezMyslnikow;

public:

    Data(string dataZMyslnikami="",int id=0, int rok=0, int miesiac=0, int dzien=0,int dataBezMyslnikow=0)
    {
        this->dataZMyslnikami = dataZMyslnikami;
        this->id = id;
        this->rok = rok;
        this->miesiac = miesiac;
        this->dzien = dzien;
        this->dataBezMyslnikow = dataBezMyslnikow;
    }

    //bool operator<(const Data &other);
    //setery
    void ustawDataZMyslnikami(string nowaData);
    void ustawID(int noweId);
    void ustawRok(int nowyRok);
    void ustawMiesiac(int nowyMiesiac);
    void ustawDzien(int nowyDzien);
    void ustawDataBezMyslnikow(int nowaDataBezMyslnikow);
    //getery
    string pobierzDataZMyslnikami();
    int pobierzID();
    int pobierzRok();
    int pobierzMiesiac();
    int pobierzDzien();
    int pobierzDateBezMyslnikow();

};
#endif // UZYTKOWNIK_H
