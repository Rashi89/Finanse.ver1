#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>

#include "Expense.h"
#include "data.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"
#include "Markup.h"

void ExpenseMenager::dodajItem() {
    Expense expense;
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
            expense=podajNowyItem(znak,wpisanaData);
            expenses.push_back(expense);
            plikiZExpenses.dopiszItemDoPliku(expense);
        }
        else cout<<"Zla data!"<<endl;
    }
    else if(znak=='t')
    {
        //cout<<"Dzisiejsza data: "<<endl;
        data =dataMenager.pobierzDzisiejszaDate();

        string wpisanaData=data.pobierzDataZMyslnikami();
        expense=podajNowyItem(znak,wpisanaData);
        expenses.push_back(expense);
        plikiZExpenses.dopiszItemDoPliku(expense);
    }
}

Expense ExpenseMenager::podajNowyItem(char znak, string wpisanaData) {

    vector <Data> daty;
    Expense expense;
    Data data;

    int amount,dataJakoInt;
    string item,dataJakoString;

    if(znak=='n')
    {
        if(dataMenager.podajDate(wpisanaData)==true)
        {
            expense.ustawExpenseID(pobierzIdNowegoItemu());
            expense.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);
            expense.ustawDate(wpisanaData);
            dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(wpisanaData);
            dataJakoInt=konwersjaStringNaInt(dataJakoString);
            expense.ustawDataJakoInt(dataJakoInt);
            cout << "Podaj nazwe produktu: ";
            cin.sync();
            item=wczytajLinie();
            expense.ustawItem(item);
            cout << "Podaj kwote: ";
            cin.sync();
            cin>>amount;
            expense.ustawAmount(amount);
        }

        else cout<<"Zle dane!"<<endl;
                }
    else if(znak=='t')
    {
        expense.ustawExpenseID(pobierzIdNowegoItemu());
        expense.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);

        expense.ustawDate(wpisanaData);
        dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(wpisanaData);
        dataJakoInt=konwersjaStringNaInt(dataJakoString);

        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=wczytajLinie();
        expense.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amount;
        expense.ustawAmount(amount);
    }
    else
        cout<<"Zly znak"<<endl;
        return expense;
}

int ExpenseMenager::pobierzIdNowegoItemu() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().pobierzExpenseID() + 1;
}

void ExpenseMenager::wyswietlWszystkieItemy()
{
    if (!expenses.empty()) {
        cout << "             >>>PRODUKTY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            wyswietlItem(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void ExpenseMenager::wyswietlWszystkieDaty()
{
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
}

void ExpenseMenager::wyswietlDate(Data data) {
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

void ExpenseMenager::sortowanie()
{
    //vector <Data> daty;
    sortowanieItemow(expenses);
    //dataMenager.sortowanie(daty);
   //sort(daty.begin(),daty.end());
}

void ExpenseMenager::sortowanieItemow(vector <Expense> &expenses)
{
    sort(expenses.begin(),expenses.end());

}

void ExpenseMenager::wyswietlItem(Expense expense)
{
    cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.pobierzExpenseID()<<endl;
    cout<<"Data: "<< expense.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.pobierzItem()<<endl;
    cout<<"Koszt: "<< expense.pobierzAmount()<<endl;
    cout<<"Data jako int: "<<expense.pobierzDataJakoInt()<<endl;
}

void ExpenseMenager::wyswietlItemyZBiezacegoMiesiaca()
{
     if (!expenses.empty()) {
        cout << "             >>>PRODUKTY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            wyswietlItemZTegoMiesiaca(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

int ExpenseMenager::pobierzbiezacyMiesiac()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return st.wMonth;
}
void ExpenseMenager::wyswietlItemZTegoMiesiaca(Expense expense)
{
    int podanyMiesiac=pobierzbiezacyMiesiac();
    int dzien=expense.pobierzDataJakoInt()%100;
    int miesiac=(expense.pobierzDataJakoInt()%10000-dzien)/100;
    if(miesiac==podanyMiesiac){
    cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.pobierzExpenseID()<<endl;
    cout<<"Data: "<< expense.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.pobierzItem()<<endl;
    cout<<"Koszt: "<< expense.pobierzAmount()<<endl;
    }
}

int ExpenseMenager::obliczWydatkiZObecnegoMiesiaca()
{
    int podanyMiesiac=pobierzbiezacyMiesiac();
    int sumaWydatkow=0;
    if (!expenses.empty()) {
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            int dzien=itr->pobierzDataJakoInt()%100;
            int miesiac=(itr->pobierzDataJakoInt()%10000-dzien)/100;
            if(miesiac==podanyMiesiac){
                sumaWydatkow+=itr->pobierzAmount();
            }
        }
        cout<<"Suma wydatkow z obecnego miesiac: "<<sumaWydatkow<<endl;
        return sumaWydatkow;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void ExpenseMenager::wyswietlItemyZPoprzedniegoMiesiaca()
{
     if (!expenses.empty()) {
        cout << "             >>>PRODUKTY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            wyswietlItemZPoprzedniegoMiesiaca(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void ExpenseMenager::wyswietlItemZPoprzedniegoMiesiaca(Expense expense)
{
    int podanyMiesiac=pobierzbiezacyMiesiac()-1;
    int dzien=expense.pobierzDataJakoInt()%100;
    int miesiac=(expense.pobierzDataJakoInt()%10000-dzien)/100;
    if(miesiac==podanyMiesiac){
    cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.pobierzExpenseID()<<endl;
    cout<<"Data: "<< expense.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.pobierzItem()<<endl;
    cout<<"Koszt: "<< expense.pobierzAmount()<<endl;
    }
}

int ExpenseMenager::obliczWydatkiZPoprzedniegoMiesiaca()
{
    int podanyMiesiac=pobierzbiezacyMiesiac()-1;
    int sumaWydatkow=0;
    if (!expenses.empty()) {
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            int dzien=itr->pobierzDataJakoInt()%100;
            int miesiac=(itr->pobierzDataJakoInt()%10000-dzien)/100;
            if(miesiac==podanyMiesiac){
                sumaWydatkow+=itr->pobierzAmount();
            }
        }
        cout<<"Suma wydatkow z poprzedniego miesiaca: "<<sumaWydatkow<<endl;
        return sumaWydatkow;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}
bool ExpenseMenager::czyWpisanaDataJestPoprawna(string data)
{
    int rok=dataMenager.zamienDateNaRok(data);
    int miesiac=dataMenager.zamienDateNaMiesiac(data);
    int dzien=dataMenager.zamienDateNaDzien(data);

    if(dataMenager.czyDataJestPoprawna(rok, miesiac, dzien)==true)
        return true;
    else return false;
}
void ExpenseMenager::wyswietlItemyZPodanegoZakresu()
{
    string dataPoczatkowa;
    string dataKoncowa;
    cout<<"Podaj date poczatkowa: ";
    cin>>dataPoczatkowa;
    cout<<"Podaj date koncowa: ";
    cin>>dataKoncowa;
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
    else cout<<"Bledna data poczatkowa!"<<endl;

    if(czyWpisanaDataJestPoprawna(dataKoncowa)==true){
        rokDatyKoncowej=dataMenager.zamienDateNaRok(dataKoncowa);
        miesiacDatyKoncowej=dataMenager.zamienDateNaMiesiac(dataKoncowa);
        dzienDatyKoncowej=dataMenager.zamienDateNaDzien(dataKoncowa);

        //cout<<rokDatyKoncowej<<" "<<miesiacDatyKoncowej<<" "<<dzienDatyKoncowej<<endl;
    }
     else
     {
         cout<<"Bledna data koncowa!"<<endl;
     }

     if(czyWpisanaDataJestPoprawna(dataKoncowa)==true&&czyWpisanaDataJestPoprawna(dataPoczatkowa)==true)
     {
             if(rokDatyPoczatkowej<rokDatyKoncowej){
             wyswietlItemyZZakresu(dataPoczatkowa,dataKoncowa);
             }
             else if(rokDatyPoczatkowej==rokDatyKoncowej)
             {
                 if(miesiacDatyPoczatkowej<miesiacDatyKoncowej)
                 {
                    wyswietlItemyZZakresu(dataPoczatkowa,dataKoncowa);
                 }
                 else if(miesiacDatyPoczatkowej==miesiacDatyKoncowej)
                 {
                     if(dzienDatyPoczatkowej<dzienDatyKoncowej)
                     {
                        wyswietlItemyZZakresu(dataPoczatkowa,dataKoncowa);
                     }
                     else if(dzienDatyPoczatkowej==dzienDatyKoncowej)
                     {
                        wyswietlItemyZZakresu(dataPoczatkowa,dataKoncowa);
                     }
                     else if(dzienDatyPoczatkowej>dzienDatyKoncowej) cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa"<<endl;
                 }
                 else if(miesiacDatyPoczatkowej>miesiacDatyKoncowej) cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa"<<endl;
             }
             else if(rokDatyPoczatkowej>rokDatyKoncowej) cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa"<<endl;
     }

}

void ExpenseMenager::wyswietlItemyZZakresu(string dataPoczatkowa,string dataKoncowa)
{
    string dataPoczatkowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataPoczatkowa);
    int dataPoczatkowaJakoInt = konwersjaStringNaInt(dataPoczatkowaBezMyslnikow);
    //cout<<dataPoczatkowaJakoInt<<endl;
    string dataKoncowaBezMyslnikow=dataMenager.zamienDateNaNapisBezMyslnikow(dataKoncowa);
    int dataKoncowaJakoInt = konwersjaStringNaInt(dataKoncowaBezMyslnikow);
    //cout<<dataKoncowaJakoInt<<endl;
     if (!expenses.empty()) {
        cout << "             >>>PRODUKTY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            //itr->pobierzDataJakoInt();
            if(dataPoczatkowaJakoInt<=itr->pobierzDataJakoInt()&&itr->pobierzDataJakoInt()<=dataKoncowaJakoInt)
            {
                cout<<"ID uzytkownika: "<< itr->pobierzUserID()<<endl;
                cout<<"ID itemu: "<< itr->pobierzExpenseID()<<endl;
                cout<<"Data: "<< itr->pobierzDate()<<endl;
                cout<<"Nazwa itemu: "<< itr->pobierzItem()<<endl;
                cout<<"Koszt: "<< itr->pobierzAmount()<<endl;
            }
        }
        int wydatkiZTegoOkresu=obliczWydatkiZPodanegoOkresu(dataPoczatkowaJakoInt,dataKoncowaJakoInt);
       cout<<"Suma wydatkow w podanym okresie: "<<wydatkiZTegoOkresu<<endl;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

int ExpenseMenager::obliczWydatkiZPodanegoOkresu(int dataPoczatkowaJakoInt,int dataKoncowaJakoInt)
{
    int sumaWydatkowZPodanegoOkresu=0;
    if (!expenses.empty()) {
        //cout<<incomes.size()<<endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            //itr->pobierzDataJakoInt();
            if(dataPoczatkowaJakoInt<=itr->pobierzDataJakoInt()&&itr->pobierzDataJakoInt()<=dataKoncowaJakoInt)
            {
                sumaWydatkowZPodanegoOkresu+=itr->pobierzAmount();
            }
        }
        return sumaWydatkowZPodanegoOkresu;

        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

string ExpenseMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}

int ExpenseMenager::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}
