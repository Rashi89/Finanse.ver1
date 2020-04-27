#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>
#include <sstream>

#include "Income.h"
#include "data.h"
#include "IncomeMenager.h"
#include "DataMenager.h"
#include "Markup.h"
//#include "MetodyPomocnicze.h"

void IncomeMenager::dodajIncome() {
    Income income;
    Data data;

    char znak;

    cout << " >>> DODAWANIE NOWEGO ITEMU <<<" << endl << endl;
    cout<<"Czy chcesz dodac nowy produkt z dzisiejsza data? <t/n>"<<endl;
    cin>>znak;
    if(znak=='n')
    {
        cout << "Podaj date: ";
        cin.sync();
        string wpisanaData=MetodyPomocnicze::wczytajLinie();
        if(dataMenager.czyDataJestZPrzedzialu(wpisanaData)==true)
        {
            income=podajNowyItem(znak,wpisanaData);
            incomes.push_back(income);
            plikiZIncomes.dopiszItemDoPliku(income);
        }
        else cout<<"Zla data!"<<endl;
    }
    else if(znak=='t')
    {
        //cout<<"Dzisiejsza data: "<<endl;
        data =dataMenager.pobierzDzisiejszaDate();

        string wpisanaData=data.pobierzDataZMyslnikami();
        income=podajNowyItem(znak,wpisanaData);
        incomes.push_back(income);
        plikiZIncomes.dopiszItemDoPliku(income);
    }
}

Income IncomeMenager::podajNowyItem(char znak, string wpisanaData) {

    vector <Data> daty;
    Income income;
    Data data;

    float amount;
    int dataJakoInt;
    string amountJakoString,item,dataJakoString;

    if(znak=='n')
    {
        if(dataMenager.podajDate(wpisanaData)==true)
        {
            income.ustawIncomeID(pobierzIdNowegoItemu());
            income.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);
            income.ustawDate(wpisanaData);
            dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(wpisanaData);
            dataJakoInt=MetodyPomocnicze::konwersjaStringNaInt(dataJakoString);
            income.ustawDataJakoInt(dataJakoInt);
            cout << "Podaj nazwe produktu: ";
            cin.sync();
            item=MetodyPomocnicze::wczytajLinie();
            income.ustawItem(item);
            cout << "Podaj kwote: ";
            cin.sync();
            cin>>amountJakoString;
            string amountZKropka = MetodyPomocnicze::zamienPrzecinekNakropke(amountJakoString);
            income.ustawAmountJakoString(amountZKropka);
            amount = MetodyPomocnicze::zamianaStringNaFloat(amountZKropka);
            income.ustawAmount(amount);
        }

        else cout<<"Zle dane!"<<endl;
                }
    else if(znak=='t')
    {
        income.ustawIncomeID(pobierzIdNowegoItemu());
        income.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);

        income.ustawDate(wpisanaData);
        dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(wpisanaData);
        dataJakoInt=MetodyPomocnicze::konwersjaStringNaInt(dataJakoString);
        income.ustawDataJakoInt(dataJakoInt);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=MetodyPomocnicze::wczytajLinie();
        income.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amountJakoString;
        string amountZKropka = MetodyPomocnicze::zamienPrzecinekNakropke(amountJakoString);
        income.ustawAmountJakoString(amountZKropka);
        amount = MetodyPomocnicze::zamianaStringNaFloat(amountZKropka);
        income.ustawAmount(amount);
    }
    else
        cout<<"Zly znak"<<endl;
        return income;
}

void IncomeMenager::wyswietlWszystkieIncome()
{
    if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            wyswietlItem(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}
void IncomeMenager::wyswietlItem(Income income)
{
    cout<<"ID uzytkownika: "<< income.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< income.pobierzIncomeID()<<endl;
    cout<<"Data: "<< income.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< income.pobierzItem()<<endl;
    cout<<"Koszt: "<< income.pobierzAmount()<<endl;
    cout<<"Data jako int: "<<income.pobierzDataJakoInt()<<endl;
    cout<<"Income jako string: "<<income.pobierzAmountJakoString()<<endl;
}

void IncomeMenager::wyswietlIncomeZBiezacegoMiesiaca()
{
     if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            wyswietlIncomeZTegoMiesiaca(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void IncomeMenager::wyswietlIncomeZTegoMiesiaca(Income income)
{
    int podanyMiesiac=dataMenager.pobierzbiezacyMiesiac();
    int dzien=income.pobierzDataJakoInt()%100;
    int miesiac=(income.pobierzDataJakoInt()%10000-dzien)/100;
    if(miesiac==podanyMiesiac){
    cout<<"ID uzytkownika: "<< income.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< income.pobierzIncomeID()<<endl;
    cout<<"Data: "<< income.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< income.pobierzItem()<<endl;
    cout<<"Koszt: "<< income.pobierzAmount()<<endl;
    cout << endl;
    }
}

float IncomeMenager::obliczPrzychodyZObecnegoMiesiaca()
{
    int podanyMiesiac=dataMenager.pobierzbiezacyMiesiac();
    float sumaWydatkow=0;
    if (!incomes.empty()) {
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            int dzien=itr->pobierzDataJakoInt()%100;
            int miesiac=(itr->pobierzDataJakoInt()%10000-dzien)/100;
            if(miesiac==podanyMiesiac){
                sumaWydatkow+=itr->pobierzAmount();
            }
        }
        cout<<"Suma przychodow z obecnego miesiaca: "<<sumaWydatkow<<endl;
        return sumaWydatkow;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}


void IncomeMenager::wyswietlIncomeZPoprzedniegoMiesiaca()
{
     if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            wyswietlItemZPoprzedniegoMiesiaca(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}
void IncomeMenager::wyswietlItemZPoprzedniegoMiesiaca(Income income)
{
    int podanyMiesiac=dataMenager.pobierzbiezacyMiesiac()-1;
    int dzien=income.pobierzDataJakoInt()%100;
    int miesiac=(income.pobierzDataJakoInt()%10000-dzien)/100;
    if(miesiac==podanyMiesiac){
    cout<<"ID uzytkownika: "<< income.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< income.pobierzIncomeID()<<endl;
    cout<<"Data: "<< income.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< income.pobierzItem()<<endl;
    cout<<"Koszt: "<< income.pobierzAmount()<<endl;
    cout << endl;
    }
}

float IncomeMenager::obliczPrzychodyZPoprzedniegoMiesiaca()
{
    int podanyMiesiac=dataMenager.pobierzbiezacyMiesiac()-1;
    float sumaWydatkow=0;
    if (!incomes.empty()) {
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            int dzien=itr->pobierzDataJakoInt()%100;
            int miesiac=(itr->pobierzDataJakoInt()%10000-dzien)/100;
            if(miesiac==podanyMiesiac){
                sumaWydatkow+=itr->pobierzAmount();
            }
        }
        cout<<"Suma przychodow z poprzedniego miesiaca: "<<sumaWydatkow<<endl;
        return sumaWydatkow;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}
void IncomeMenager::wyswietlIncomeZPodanegoZakresu(string dataPoczatkowa, string dataKoncowa)
{
    int rokDatyPoczatkowej=0;
    int miesiacDatyPoczatkowej=0;
    int dzienDatyPoczatkowej=0;
    int rokDatyKoncowej=0;
    int miesiacDatyKoncowej=0;
    int dzienDatyKoncowej=0;

    if(czyWpisanaDataJestPoprawna(dataPoczatkowa)==true){
        rokDatyPoczatkowej=dataMenager.zamienDateNaRok(dataPoczatkowa);
        miesiacDatyPoczatkowej=dataMenager.zamienDateNaMiesiac(dataPoczatkowa);
        dzienDatyPoczatkowej=dataMenager.zamienDateNaDzien(dataPoczatkowa);

        //cout<<rokDatyPoczatkowej<<" "<<miesiacDatyPoczatkowej<<" "<<dzienDatyPoczatkowej<<endl;
    }
    else; //cout<<"Bledna data poczatkowa!"<<endl;

    if(czyWpisanaDataJestPoprawna(dataKoncowa)==true){
        rokDatyKoncowej=dataMenager.zamienDateNaRok(dataKoncowa);
        miesiacDatyKoncowej=dataMenager.zamienDateNaMiesiac(dataKoncowa);
        dzienDatyKoncowej=dataMenager.zamienDateNaDzien(dataKoncowa);

        //cout<<rokDatyKoncowej<<" "<<miesiacDatyKoncowej<<" "<<dzienDatyKoncowej<<endl;
    }
     else
     {
         ;//cout<<"Bledna data koncowa!"<<endl;
     }

     if(czyWpisanaDataJestPoprawna(dataKoncowa)==true&&czyWpisanaDataJestPoprawna(dataPoczatkowa)==true)
     {
             if(rokDatyPoczatkowej<rokDatyKoncowej){
             wyswietlIncomeZZakresu(dataPoczatkowa,dataKoncowa);
             }
             else if(rokDatyPoczatkowej==rokDatyKoncowej)
             {
                 if(miesiacDatyPoczatkowej<miesiacDatyKoncowej)
                 {
                    wyswietlIncomeZZakresu(dataPoczatkowa,dataKoncowa);
                 }
                 else if(miesiacDatyPoczatkowej==miesiacDatyKoncowej)
                 {
                     if(dzienDatyPoczatkowej<dzienDatyKoncowej)
                     {
                        wyswietlIncomeZZakresu(dataPoczatkowa,dataKoncowa);
                     }
                     else if(dzienDatyPoczatkowej==dzienDatyKoncowej)
                     {
                        wyswietlIncomeZZakresu(dataPoczatkowa,dataKoncowa);
                     }
                     else if(dzienDatyPoczatkowej>dzienDatyKoncowej) ;//cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa"<<endl;
                 }
                 else if(miesiacDatyPoczatkowej>miesiacDatyKoncowej) ;//cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa"<<endl;
             }
             else if(rokDatyPoczatkowej>rokDatyKoncowej) ;//cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa"<<endl;
     }

}

void IncomeMenager::wyswietlIncomeZZakresu(string dataPoczatkowa,string dataKoncowa)
{
    string dataPoczatkowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataPoczatkowa);
    int dataPoczatkowaJakoInt = MetodyPomocnicze::konwersjaStringNaInt(dataPoczatkowaBezMyslnikow);
    string dataKoncowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataKoncowa);
    int dataKoncowaJakoInt = MetodyPomocnicze::konwersjaStringNaInt(dataKoncowaBezMyslnikow);
     if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            //itr->pobierzDataJakoInt();
            if(dataPoczatkowaJakoInt<=itr->pobierzDataJakoInt()&&itr->pobierzDataJakoInt()<=dataKoncowaJakoInt)
            {
                cout<<"ID uzytkownika: "<< itr->pobierzUserID()<<endl;
                cout<<"ID itemu: "<< itr->pobierzIncomeID()<<endl;
                cout<<"Data: "<< itr->pobierzDate()<<endl;
                cout<<"Nazwa itemu: "<< itr->pobierzItem()<<endl;
                cout<<"Koszt: "<< itr->pobierzAmount()<<endl;
                cout << endl;
            }
        }

        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

float IncomeMenager::obliczPrzychodyZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa)
{
    string dataPoczatkowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataPoczatkowa);
    int dataPoczatkowaJakoInt = MetodyPomocnicze::konwersjaStringNaInt(dataPoczatkowaBezMyslnikow);
    string dataKoncowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataKoncowa);
    int dataKoncowaJakoInt = MetodyPomocnicze::konwersjaStringNaInt(dataKoncowaBezMyslnikow);
    float sumaPrzychodowZPodanegoOkresu=0;
    if (!incomes.empty()) {
        //cout<<incomes.size()<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            //itr->pobierzDataJakoInt();
            if(dataPoczatkowaJakoInt<=itr->pobierzDataJakoInt()&&itr->pobierzDataJakoInt()<=dataKoncowaJakoInt)
            {
                sumaPrzychodowZPodanegoOkresu+=itr->pobierzAmount();
            }
        }
        return sumaPrzychodowZPodanegoOkresu;

        cout << endl;
}
}

bool IncomeMenager::czyWpisanaDataJestPoprawna(string data)
{
    int rok=dataMenager.zamienDateNaRok(data);
    int miesiac=dataMenager.zamienDateNaMiesiac(data);
    int dzien=dataMenager.zamienDateNaDzien(data);

    if(dataMenager.czyDataJestPoprawna(rok, miesiac, dzien)==true)
        return true;
    else return false;
}
void IncomeMenager::sortowanie()
{
    sortowanieItemow(incomes);
}

void IncomeMenager::sortowanieItemow(vector <Income> &incomes)
{
    sort(incomes.begin(),incomes.end());

}


int IncomeMenager::pobierzIdNowegoItemu() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().pobierzIncomeID() + 1;
}
