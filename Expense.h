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

public:

    Expense(int expenseID=0, int userID=0, string date="", string item="",int amount=0) {
        this->expenseID = expenseID;
        this->userID=userID;
        this->date=date;
        this->item=item;
        this->amount=amount;
    }

    //setery
    void ustawExpenseID(int newExpenseID);
    void ustawUserID(int newUserID);
    void ustawDate(string newDate);
    void ustawItem(string newItem);
    void ustawAmount(int newAmount);
    //getery
    int pobierzExpenseID();
    int pobierzUserID();
    string pobierzDate();
    string pobierzItem();
    int pobierzAmount();

};




#endif
