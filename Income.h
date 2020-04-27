#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Income {
    int incomeID;
    int userID;
    string date;
    string item;
    float amount;
    int dateAsInt;
    string amountAsString;

public:

    Income(int incomeID=0, int userID=0, string date="", string item="",float amount=0.0, int dateAsInt=0,string amountAsString="") {
        this->incomeID = incomeID;
        this->userID=userID;
        this->date=date;
        this->item=item;
        this->amount=amount;
        this->dateAsInt=dateAsInt;
        this->amountAsString=amountAsString;
    }
    bool operator<(const Income &other);

    //setery
    void setIncomeID(int newIncomeID);
    void setUserID(int newUserID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    void setDateAsInt(int newDateAsInt);
    void setAmountAsString(string newAmountAsString);
    //getery
    int getIncomeID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
    int getDateAsInt();
    string getAmountAsString();

};
#endif
