#include "Income.h"

void Income::setIncomeID(int newIncomeID) {
    if(newIncomeID>=0)
        incomeID=newIncomeID;
}
void Income::setUserID(int newUserID) {
    if(newUserID>=0)
        userID=newUserID;
}
void Income::setDate(string newDate) {
    date=newDate;
}
void Income::setItem(string newItem) {
    item=newItem;
}
void Income::setAmount(float newAmount) {
    if(newAmount>=0)
    amount=newAmount;
}
void Income::setDateAsInt(int newDateAsInt)
{
    dateAsInt=newDateAsInt;
}

void Income::setAmountAsString(string newAmountAsString)
{
    amountAsString=newAmountAsString;
}

bool Income::operator<(const Income &other)
{
    return dateAsInt < other.dateAsInt;
}


int Income::getIncomeID() {
    return incomeID;
}
int Income::getUserID() {
    return userID;
}
string Income::getDate() {
    return date;
}
string Income::getItem() {
    return item;
}
float Income::getAmount() {
    return amount;
}
int Income::getDateAsInt() {
    return dateAsInt;
}
string Income::getAmountAsString() {
    return amountAsString;
}

