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
    dopiszItemDoPliku(expense);

    //plikiZUsers.dopiszUzytkownikaDoPliku(user);
}

Expense ExpenseMenager::podajNowyItem() {
    Expense expense;

    expense.ustawExpenseID(pobierzIdNowegoItemu());
    expense.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    int amount;
    string data,item;

        cout << "Podaj date: ";
        cin.sync();
        data=wczytajLinie();
        expense.ustawDate(data);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=wczytajLinie();
        expense.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amount;
        expense.ustawAmount(amount);

    return expense;
}

int ExpenseMenager::pobierzIdNowegoItemu() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().pobierzExpenseID() + 1;
}

void ExpenseMenager::dopiszItemDoPliku(Expense expense)
{
    CMarkup xml;
    if(xml.Load( "Expense.xml" )==false) {
        xml.AddElem( "EXPENSES" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "EXPENSEID", expense.pobierzExpenseID() );
        xml.AddElem( "USERID", expense.pobierzUserID() );
        xml.AddElem( "DATE", expense.pobierzDate() );
        xml.AddElem( "ITEM", expense.pobierzItem() );
        xml.AddElem( "AMOUNT", expense.pobierzAmount() );

        xml.OutOfElem();
        xml.Save( "Expense.xml" );
    } else {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "EXPENSEID", expense.pobierzExpenseID() );
        xml.AddElem( "USERID", expense.pobierzUserID() );
        xml.AddElem( "DATE", expense.pobierzDate() );
        xml.AddElem( "ITEM", expense.pobierzItem() );
        xml.AddElem( "AMOUNT", expense.pobierzAmount() );
        xml.OutOfElem();
        xml.Save( "Expense.xml" );
    }
}

vector <Expense> ExpenseMenager::wczytajItemyZPliku(int idZalogowanegoUzytkownika)
{
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;
    xml.Load( "Expense.xml" );
    xml.FindElem("ExpenseS"); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("Expense") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        if(nUserID==idZalogowanegoUzytkownika){
        expense.ustawUserID(nUserID);
        xml.FindElem( "ExpenseID" );
        int nExpenseID =atoi( MCD_2PCSZ(xml.GetData()) );
        expense.ustawExpenseID(nExpenseID);
        xml.FindElem("DATE");
        MCD_STR strDate = xml.GetData();
        expense.ustawDate(strDate);
        xml.FindElem("ITEM");
        MCD_STR strItem = xml.GetData();
        expense.ustawItem(strItem);
        xml.FindElem( "AMOUNT" );
        int nAmount =atoi( MCD_2PCSZ(xml.GetData()) );
        expense.ustawAmount(nAmount);
        xml.OutOfElem();
        expenses.push_back(expense);
        }
    }
}

string ExpenseMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}
