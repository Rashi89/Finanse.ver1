#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
#include <winbase.h>

#include <windows.h>
#include "DataMenager.h"
#include "data.h"

Data DataMenager::podajDate() {
    Data data;
    string wpisanaData;
    int id,rok,miesiac,dzien;
    cout<<"Podaj date: ";
    cin>> wpisanaData;
    rok=zamienDateNaRok(wpisanaData);
    miesiac=zamienDateNaMiesiac(wpisanaData);
    dzien=zamienDateNaDzien(wpisanaData);
    //cout<<rok<<" "<<miesiac<<" "<<dzien<<endl;
    if(czyDataJestPoprawna(rok, miesiac, dzien)==true) {
        data.ustawID(pobierzIDNowejDaty());
        data.ustawRok(rok);
        data.ustawMiesiac(miesiac);
        data.ustawDzien(dzien);
        data.ustawDataZMyslnikami(wpisanaData);
        data.ustawDataBezMyslnikow(konwersjaStringNaInt(zamienDateNaNapisBezMyslnikow(wpisanaData)));
        daty.push_back(data);
    } else
        cout<<"Bledna data!"<<endl;
}

Data DataMenager::pobierzDzisiejszaDate()
{
    Data data;
    SYSTEMTIME st;
    GetSystemTime(&st);
        data.ustawID(pobierzIDNowejDaty());
        data.ustawRok(st.wYear);
        data.ustawMiesiac(st.wMonth);
        data.ustawDzien(st.wDay);
        string wpisanaData;
        wpisanaData+=konwersjaIntNaString(st.wYear);
        wpisanaData+="-";
        if(st.wMonth<10)
        {
            wpisanaData+="0";
            wpisanaData+=konwersjaIntNaString(st.wMonth);
            wpisanaData+="-";
        }
        else{
            wpisanaData+=konwersjaIntNaString(st.wMonth);
            wpisanaData+="-";
        }
        if(st.wDay<10)
        {
            wpisanaData+="0";
            wpisanaData+=konwersjaIntNaString(st.wDay);
        }
        else{
           wpisanaData+=konwersjaIntNaString(st.wDay);
        }

        data.ustawDataZMyslnikami(wpisanaData);
        data.ustawDataBezMyslnikow(konwersjaStringNaInt(zamienDateNaNapisBezMyslnikow(wpisanaData)));
        daty.push_back(data);
}

int DataMenager::pobierzIDNowejDaty() {
    if (daty.empty() == true)
        return 1;
    else
        return daty.back().pobierzID() + 1;
}
void DataMenager::wyswietlDaty() {
    if (!daty.empty()) {
        cout << "             >>> DATY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout<<daty.size()<<endl;
        for (vector <Data> :: iterator itr = daty.begin(); itr != daty.end(); itr++) {
            wyswietlDate(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak dat." << endl << endl;
    }
    //system("pause");
}
void DataMenager::wyswietlDate(Data data) {
    if(data.pobierzMiesiac()<10&&data.pobierzDzien()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-0"<<data.pobierzMiesiac()<<"-0"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else if(data.pobierzMiesiac()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-0"<<data.pobierzMiesiac()<<"-"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else if(data.pobierzDzien()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-"<<data.pobierzMiesiac()<<"-0"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else{
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-"<<data.pobierzMiesiac()<<"-"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    }
}

bool DataMenager::czyRokJestPrzestepny(int rok) {
    if(rok%4==0&&rok%100!=0) {
        return true;
    } else if(rok%400==0) {
        return true;
    } else {
        return false;
    }
}
bool DataMenager::czyDataJestPoprawna(int rok, int miesiac, int dzien) {
    if(miesiac>12)
        return false;
    if(miesiac==1||miesiac==3||miesiac==5||miesiac==7||miesiac==8||miesiac==10||miesiac==12) {
        if(dzien<=31&&dzien>=1) {
            return true;
        } else
            return false;
    } else if(miesiac==4||miesiac==6||miesiac==9||miesiac==11) {
        if(dzien<=30&&dzien>=1) {
            return true;
        } else
            return false;
    } else if(miesiac==2) {
        if(czyRokJestPrzestepny(rok)==true) {
            if(dzien<=29&&dzien>=1) {
                return true;
            } else
                return false;
        } else {
            if(dzien<=28&&dzien>=1) {
                return true;
            } else
                return false;
        }
    }
}

int DataMenager::zamienDateNaRok(string wpisanaData) {
    int rok;
    string pojedynczaDana = "";
    int numerPojedynczejDanej = 1;
    for(int pozycjaZnaku=0; pozycjaZnaku<wpisanaData.length(); pozycjaZnaku++) {
        if (wpisanaData[pozycjaZnaku] != '-') {
            pojedynczaDana += wpisanaData[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanej) {
            case 1:
                rok=(atoi(pojedynczaDana.c_str()));
                break;
            }
            pojedynczaDana = "";
            numerPojedynczejDanej++;
        }
    }
    return rok;
}
int DataMenager::zamienDateNaMiesiac(string wpisanaData) {
    int miesiac;
    string pojedynczaDana = "";
    int numerPojedynczejDanej = 1;
    for(int pozycjaZnaku=0; pozycjaZnaku<wpisanaData.length(); pozycjaZnaku++) {
        if (wpisanaData[pozycjaZnaku] != '-') {
            pojedynczaDana += wpisanaData[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanej) {
            case 2:
                miesiac=(atoi(pojedynczaDana.c_str()));
                break;
            }
            pojedynczaDana = "";
            numerPojedynczejDanej++;
        }
    }
    return miesiac;
}
int DataMenager::zamienDateNaDzien(string wpisanaData) {
    int dzien,liczba;
    string pojedynczaDana = "";
    int numerPojedynczejDanej = 1;
    for(int pozycjaZnaku=wpisanaData.length()-1; pozycjaZnaku>0; pozycjaZnaku--) {
        if (wpisanaData[pozycjaZnaku] != '-') {
            pojedynczaDana += wpisanaData[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanej) {
            case 1:
                liczba=(atoi(pojedynczaDana.c_str()));
                if(liczba%10==0) {
                    dzien=liczba/10;
                } else
                    dzien=liczba%10*10+(liczba-liczba%10)/10;
                break;
            }
            pojedynczaDana = "";
            numerPojedynczejDanej++;
        }
    }
    return dzien;
}

string DataMenager::zamienDateNaNapisBezMyslnikow(string wpisanaData) {
    string dataBezMyslnikow="";

    int liczbaMyslinkow=0;
    for(int pozycjaZnaku=0; pozycjaZnaku<wpisanaData.length(); pozycjaZnaku++) {
        if(wpisanaData[pozycjaZnaku]=='-') {
            ;
        } else {
            dataBezMyslnikow+=wpisanaData[pozycjaZnaku];
        }
    }
    return dataBezMyslnikow;
}

string DataMenager::dzisiejszaData() {

    Data data;
    data=pobierzDzisiejszaDate();
    vector <Data> :: iterator itr = daty.end()-1;
    pobierzDzisiejszaDateJakoString(*itr);
    cout <<pobierzDzisiejszaDateJakoString(*itr)<<endl;
    return pobierzDzisiejszaDateJakoString(*itr);

}
string DataMenager::pobierzDzisiejszaDateJakoString(Data data)
{
    string dataZMyslnikami="";
    dataZMyslnikami=data.pobierzDataZMyslnikami();

    return dataZMyslnikami;
}








int DataMenager::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}

string DataMenager::konwersjaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
void DataMenager::sortowanie()
{
    sort(daty.begin(),daty.end());
}
