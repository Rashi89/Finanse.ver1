#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense {
    int expenseID;
    int userID;
    string date;
    string item;
    int amount;
    int dataJakoInt;

public:

    Expense(int expenseID=0, int userID=0, string date="", string item="",int amount=0,int dataJakoInt=0) {
        this->expenseID = expenseID;
        this->userID=userID;
        this->date=date;
        this->item=item;
        this->amount=amount;
        this->dataJakoInt=dataJakoInt;
    }
    bool operator<(const Expense &other);

    //setery
    void ustawExpenseID(int newExpenseID);
    void ustawUserID(int newUserID);
    void ustawDate(string newDate);
    void ustawItem(string newItem);
    void ustawAmount(int newAmount);
    void ustawDataJakoInt(int newDataJakoInt);
    //getery
    int pobierzExpenseID();
    int pobierzUserID();
    string pobierzDate();
    string pobierzItem();
    int pobierzAmount();
    int pobierzDataJakoInt();

};




#endif
