#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Expense {
    int expenseID;
    int userID;
    string date;
    string item;
    float amount;
    int dataJakoInt;
    string amountJakoString;

public:

    Expense(int expenseID=0, int userID=0, string date="", string item="",float amount=0.0, int dataJakoInt=0, string amountJakoString="") {
        this->expenseID = expenseID;
        this->userID=userID;
        this->date=date;
        this->item=item;
        this->amount=amount;
        this->dataJakoInt=dataJakoInt;
        this->amountJakoString=amountJakoString;
    }
    bool operator<(const Expense &other);

    //setery
    void ustawExpenseID(int newExpenseID);
    void ustawUserID(int newUserID);
    void ustawDate(string newDate);
    void ustawItem(string newItem);
    void ustawAmount(float newAmount);
    void ustawDataJakoInt(int newDataJakoInt);
    void ustawAmountJakoString(string newAmountJakoString);
    //getery
    int pobierzExpenseID();
    int pobierzUserID();
    string pobierzDate();
    string pobierzItem();
    float pobierzAmount();
    int pobierzDataJakoInt();
    string pobierzAmountJakoString();

};
#endif
