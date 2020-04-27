#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>

#include "Income.h"
#include "data.h"
#include "IncomeMenager.h"
#include "DataMenager.h"
#include "Markup.h"

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
        string wpisanaData=wczytajLinie();
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

    int amount,dataJakoInt;
    string item,dataJakoString;

    if(znak=='n')
    {
        if(dataMenager.podajDate(wpisanaData)==true)
        {
            income.ustawIncomeID(pobierzIdNowegoItemu());
            income.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);
            income.ustawDate(wpisanaData);
            dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(wpisanaData);
            dataJakoInt=konwersjaStringNaInt(dataJakoString);
            income.ustawDataJakoInt(dataJakoInt);
            cout << "Podaj nazwe produktu: ";
            cin.sync();
            item=wczytajLinie();
            income.ustawItem(item);
            cout << "Podaj kwote: ";
            cin.sync();
            cin>>amount;
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
        dataJakoInt=konwersjaStringNaInt(dataJakoString);

        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=wczytajLinie();
        income.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amount;
        income.ustawAmount(amount);
    }
    else
        cout<<"Zly znak"<<endl;
        return income;
}

void IncomeMenager::wyswietlWszystkieIncome()
{
    if (!incomes.empty()) {
        cout << "             >>>PRODUKTY<<<" << endl;
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
}

void IncomeMenager::wyswietlIncomeZBiezacegoMiesiaca()
{
     if (!incomes.empty()) {
        cout << "             >>>PRODUKTY<<<" << endl;
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
    int podanyMiesiac=pobierzbiezacyMiesiac();
    int dzien=income.pobierzDataJakoInt()%100;
    int miesiac=(income.pobierzDataJakoInt()%10000-dzien)/100;
    if(miesiac==podanyMiesiac){
    cout<<"ID uzytkownika: "<< income.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< income.pobierzIncomeID()<<endl;
    cout<<"Data: "<< income.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< income.pobierzItem()<<endl;
    cout<<"Koszt: "<< income.pobierzAmount()<<endl;
    }
}


int IncomeMenager::pobierzbiezacyMiesiac()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return st.wMonth;
}

int IncomeMenager::pobierzIdNowegoItemu() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().pobierzIncomeID() + 1;
}

string IncomeMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}

int IncomeMenager::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}
