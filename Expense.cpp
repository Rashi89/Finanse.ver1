#include "Expense.h"

void Expense::ustawExpenseID(int newExpenseID) {
    if(newExpenseID>=0)
        expenseID=newExpenseID;
}
void Expense::ustawUserID(int newUserID) {
    if(newUserID>=0)
        userID=newUserID;
}
void Expense::ustawDate(string newDate) {
    date=newDate;
}
void Expense::ustawItem(string newItem) {
    item=newItem;
}
void Expense::ustawAmount(float newAmount) {
    if(newAmount>=0)
    amount=newAmount;
}
void Expense::ustawDataJakoInt(int newDataJakoInt)
{
    dataJakoInt=newDataJakoInt;
}
void Expense::ustawAmountJakoString(string newAmountJakoString)
{
    amountJakoString=newAmountJakoString;
}

    bool Expense::operator<(const Expense &other)
{
    return dataJakoInt < other.dataJakoInt;
}


int Expense::pobierzExpenseID() {
    return expenseID;
}
int Expense::pobierzUserID() {
    return userID;
}
string Expense::pobierzDate() {
    return date;
}
string Expense::pobierzItem() {
    return item;
}
float Expense::pobierzAmount() {
    return amount;
}

int Expense::pobierzDataJakoInt() {
    return dataJakoInt;
}
string Expense::pobierzAmountJakoString() {
    return amountJakoString;
}
