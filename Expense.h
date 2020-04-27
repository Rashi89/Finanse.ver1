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
    int dateAsInt;
    string amountAsString;

public:

    Expense(int expenseID=0, int userID=0, string date="", string item="",float amount=0.0, int dateAsInt=0, string amountAsString="") {
        this->expenseID = expenseID;
        this->userID=userID;
        this->date=date;
        this->item=item;
        this->amount=amount;
        this->dateAsInt=dateAsInt;
        this->amountAsString=amountAsString;
    }
    bool operator<(const Expense &other);

    //setery
    void setExpenseID(int newExpenseID);
    void setUserID(int newUserID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    void setDateAsInt(int newDateAsInt);
    void setAmountAsString(string newAmountAsString);
    //getery
    int getExpenseID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
    int getDateAsInt();
    string getAmountAsString();

};
#endif
