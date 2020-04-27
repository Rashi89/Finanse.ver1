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
    string amountJakoString,item,dataJakoString;

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
            cin>>amountJakoString;
            income.ustawAmountJakoString(zamienKropkeNaPrzecinek(amountJakoString));
            amount = zamianaStringNaFloat(amountJakoString);
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
        cin>>amountJakoString;
        income.ustawAmountJakoString(zamienKropkeNaPrzecinek(amountJakoString));
        amount = zamianaStringNaFloat(amountJakoString);
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

int IncomeMenager::obliczPrzychodyZObecnegoMiesiaca()
{
    int podanyMiesiac=pobierzbiezacyMiesiac();
    int sumaWydatkow=0;
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
    int podanyMiesiac=pobierzbiezacyMiesiac()-1;
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

int IncomeMenager::obliczPrzychodyZPoprzedniegoMiesiaca()
{
    int podanyMiesiac=pobierzbiezacyMiesiac()-1;
    int sumaWydatkow=0;
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
    int dataPoczatkowaJakoInt = konwersjaStringNaInt(dataPoczatkowaBezMyslnikow);
    //cout<<dataPoczatkowaJakoInt<<endl;
    string dataKoncowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataKoncowa);
    int dataKoncowaJakoInt = konwersjaStringNaInt(dataKoncowaBezMyslnikow);
    //cout<<dataKoncowaJakoInt<<endl;
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
            }
        }
        //int wydatkiZTegoOkresu=obliczWydatkiZPodanegoOkresu(dataPoczatkowaJakoInt,dataKoncowaJakoInt);
       //cout<<"Suma wydatkow w podanym okresie: "<<wydatkiZTegoOkresu<<endl;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

int IncomeMenager::obliczPrzychodyZPodanegoOkresu(string dataPoczatkowa,string dataKoncowa)
{
    string dataPoczatkowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataPoczatkowa);
    int dataPoczatkowaJakoInt = konwersjaStringNaInt(dataPoczatkowaBezMyslnikow);
    string dataKoncowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataKoncowa);
    int dataKoncowaJakoInt = konwersjaStringNaInt(dataKoncowaBezMyslnikow);
    int sumaWydatkowZPodanegoOkresu=0;
    if (!incomes.empty()) {
        //cout<<incomes.size()<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            //itr->pobierzDataJakoInt();
            if(dataPoczatkowaJakoInt<=itr->pobierzDataJakoInt()&&itr->pobierzDataJakoInt()<=dataKoncowaJakoInt)
            {
                sumaWydatkowZPodanegoOkresu+=itr->pobierzAmount();
            }
        }
        return sumaWydatkowZPodanegoOkresu;

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

float IncomeMenager::zamianaStringNaFloat(string liczba)
{
    string calosc="",ulamek="";
    int pozycjaPrzecinka=0;
    for(int i=0;i<liczba.length();i++)
    {
        if(liczba[i]!=','&&liczba[i]!='.')
        {
            calosc+=liczba[i];
            pozycjaPrzecinka+=1;
        }
        else if(liczba[i]==',')
        {
            i=liczba.length()-1;
        }
        else if(liczba[i]=='.')
        {
             i=liczba.length()-1;
        }
    }
    for(int i = pozycjaPrzecinka+1;i<liczba.length();i++)
    {
        ulamek+=liczba[i];
    }

    int caloscLiczby = konwersjaStringNaInt(calosc);
    float ulamkowaLiczby = konwersjaStringNaInt(ulamek);
    float wpisanaLiczbaJakoFloat;
    if(ulamek[0]=='0'){
    wpisanaLiczbaJakoFloat = caloscLiczby+ulamkowaLiczby/100;
    }
    else
    {
        wpisanaLiczbaJakoFloat = caloscLiczby+ulamkowaLiczby/100;
    }
    return wpisanaLiczbaJakoFloat;
}

string IncomeMenager::zamienKropkeNaPrzecinek(string liczba)
{
    string liczbaZKropka ="";
    for(int i=0;i<liczba.length();i++)
    {
        if(liczba[i]!=',')
        {
            liczbaZKropka+=liczba[i];
        }
        else if(liczba[i]==',')
        {
            liczbaZKropka+='.';
        }
    }
    return liczbaZKropka;
}
