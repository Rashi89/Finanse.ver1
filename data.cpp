#include "Data.h"

    void Data::ustawDataZMyslnikami(string nowaData)
    {
        dataZMyslnikami=nowaData;
    }
    void Data::ustawID(int noweID)
    {
        if(noweID>=0)
            id=noweID;
    }
    void Data::ustawRok(int nowyRok)
    {
        if(nowyRok>=0)
        rok=nowyRok;
    }
    void Data::ustawMiesiac(int nowyMiesiac)
    {
        if(nowyMiesiac>=1&&nowyMiesiac<=12)
        miesiac=nowyMiesiac;
    }
    void Data::ustawDzien(int nowyDzien)
    {
        if(nowyDzien>=1&&nowyDzien<=31)
            dzien=nowyDzien;
    }
    void Data::ustawDataBezMyslnikow(int nowaDataBezMyslnikow)
    {
        dataBezMyslnikow=nowaDataBezMyslnikow;
    }

    string Data::pobierzDataZMyslnikami()
    {
        return dataZMyslnikami;
    }
    int Data::pobierzID()
    {
        return id;
    }
    int Data::pobierzRok()
    {
        return rok;
    }
    int Data::pobierzMiesiac()
    {
        return miesiac;
    }
    int Data::pobierzDzien()
    {
        return dzien;
    }
    int Data::pobierzDateBezMyslnikow()
    {
        return dataBezMyslnikow;
    }

    //bool Data::operator<(const Data &other)
//{
   // return dataBezMyslnikow < other.dataBezMyslnikow;
//}
