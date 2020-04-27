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
    int dataJakoInt;
    string amountJakoString;

public:

    Income(int incomeID=0, int userID=0, string date="", string item="",float amount=0.0, int dataJakoInt=0,string amountJakoString="") {
        this->incomeID = incomeID;
        this->userID=userID;
        this->date=date;
        this->item=item;
        this->amount=amount;
        this->dataJakoInt=dataJakoInt;
        this->amountJakoString=amountJakoString;
    }
    bool operator<(const Income &other);

    //setery
    void ustawIncomeID(int newIncomeID);
    void ustawUserID(int newUserID);
    void ustawDate(string newDate);
    void ustawItem(string newItem);
    void ustawAmount(float newAmount);
    void ustawDataJakoInt(int newDataJakoInt);
    //getery
    int pobierzIncomeID();
    int pobierzUserID();
    string pobierzDate();
    string pobierzItem();
    float pobierzAmount();
    int pobierzDataJakoInt();
    void ustawAmountJakoString(string newAmountJakoString);
    string pobierzAmountJakoString();

};
#endif
