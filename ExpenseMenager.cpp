#include <iostream>
#include <vector>

#include "Expense.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"
#include "Markup.h"

void ExpenseMenager::dodajItem() {
    Expense expense;

    cout << " >>> DODAWANIE NOWEGO ITEMU <<<" << endl << endl;
    expense=podajNowyItem();
    expenses.push_back(expense);
    plikiZExpenses.dopiszItemDoPliku(expense);

    //plikiZUsers.dopiszUzytkownikaDoPliku(user);
}

Expense ExpenseMenager::podajNowyItem() {
	vector <Data> daty;
    Expense expense;
	Data data;
	char znak;
    int amount,dataJakoInt;
    string data1,item,dataJakoString;

    cout<<"Czy chcesz dodac nowy produkt z dzisiejsza data? <t/n>"<<endl;
    cin>>znak;
    if(znak=='n')
    {
        cout << "Podaj date: ";
        cin.sync();
        data1=wczytajLinie();
        if(dataMenager.podajDate(data1)==true)
        {
            expense.ustawExpenseID(pobierzIdNowegoItemu());
            expense.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);
            expense.ustawDate(data1);
            dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(data1);
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
        cout<<"Dzisiejsza data: "<<endl;
        data =dataMenager.pobierzDzisiejszaDate();

        data1=data.pobierzDataZMyslnikami();
        cout<<data1<<endl;
        expense.ustawDate(data1);
        dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(data1);
        dataJakoInt=konwersjaStringNaInt(dataJakoString);
        cout<<dataJakoInt<<endl;
        //expense.ustawDataJakoInt(dataJakoInt);
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
        //cout<<expenses.size()<<endl;
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

void ExpenseMenager::wyswietlItem(Expense expense)
{
    cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.pobierzExpenseID()<<endl;
    cout<<"Data: "<< expense.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.pobierzItem()<<endl;
    cout<<"Koszt: "<< expense.pobierzAmount()<<endl;
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
