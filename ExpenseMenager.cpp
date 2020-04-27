#include <iostream>
#include <vector>

#include "Expense.h"
#include "ExpenseMenager.h"
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
    Expense expense;
	char znak;
    int amount;
    string data1,item;

    expense.ustawExpenseID(pobierzIdNowegoItemu());
    expense.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout<<"Czy chcesz dodac nowy produkt z dzisiejsza data? <t/n>"<<endl;
    cin>>znak;
    if(znak=='n')
    {
        cout << "Podaj date: ";
        cin.sync();
        data1=wczytajLinie();
        expense.ustawDate(data1);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=wczytajLinie();
        expense.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amount;
        expense.ustawAmount(amount);
    }
    else{
        cout<<"Dzisiejsza data: "<<endl;
        data1=dataMenager.dzisiejszaData();
        cout<<data1<<endl;
        expense.ustawDate(data1);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=wczytajLinie();
        expense.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amount;
        expense.ustawAmount(amount);
    }


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

void ExpenseMenager::wyswietlItem(Expense expense)
{
    cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.pobierzExpenseID()<<endl;
    cout<<"Data: "<< expense.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.pobierzItem()<<endl;
    cout<<"Koszt: "<< expense.pobierzAmount()<<endl;
}

string ExpenseMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}
