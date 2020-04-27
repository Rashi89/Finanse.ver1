#include "Income.h"

void Income::ustawIncomeID(int newIncomeID) {
    if(newIncomeID>=0)
        incomeID=newIncomeID;
}
void Income::ustawUserID(int newUserID) {
    if(newUserID>=0)
        userID=newUserID;
}
void Income::ustawDate(string newDate) {
    date=newDate;
}
void Income::ustawItem(string newItem) {
    item=newItem;
}
void Income::ustawAmount(int newAmount) {
    if(newAmount>=0)
    amount=newAmount;
}
void Income::ustawDataJakoInt(int newDataJakoInt)
{
    dataJakoInt=newDataJakoInt;
}

    bool Income::operator<(const Income &other)
{
    return dataJakoInt < other.dataJakoInt;
}


int Income::pobierzIncomeID() {
    return incomeID;
}
int Income::pobierzUserID() {
    return userID;
}
string Income::pobierzDate() {
    return date;
}
string Income::pobierzItem() {
    return item;
}
int Income::pobierzAmount() {
    return amount;
}

int Income::pobierzDataJakoInt() {
    return dataJakoInt;
}
