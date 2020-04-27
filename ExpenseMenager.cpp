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

string ExpenseMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}
