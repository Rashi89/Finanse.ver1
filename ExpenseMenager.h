#ifndef EXPENSEMENAGER_H
#define EXPENSEMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "Expense.h"
#include "FilesWithExpenses.h"
#include "DataMenager.h"
#include "Markup.h"
#include "data.h"
#include "AdditionalMethods.h"

using namespace std;

class ExpenseMenager {
    const int ID_LOGGED_USER;

    vector <Expense> expenses;
    vector <Data> daty;
    FilesWithExpenses filesWithExpenses;
    DataMenager dataMenager;

    Expense getNewItemData(char sign, string givenData);
    int getIDNewExpense();
    void showExpense(Expense expense);
    void showExpenseFromThisMonth(Expense expense);
    void showExpenseFromPreviousMonth(Expense expense);
    void sortingExpense(vector <Expense> &expense);
    bool isCorrectDate(string data);
    void showExpenseFromRangeProvided(string startingDate,string endDate);
    int getIDLastExpense();

public:
    ExpenseMenager(string nameFileExpenses,int idLoggedUser): filesWithExpenses(nameFileExpenses),ID_LOGGED_USER(idLoggedUser) {
        expenses = filesWithExpenses.loadExpensesFromFile(ID_LOGGED_USER);
        daty = dataMenager.loadData(ID_LOGGED_USER);
    };
    void addExpense();
    void wyswietlWszystkieItemy();
    void wyswietlWszystkieDaty();
    void showItemsFromThisMonth();
    void showItemsFromPreviousMonth();
    void sorting();
    float calculateExpensesFromThisMonth();
    float calculateExpensesFromPreviousMonth();
    void showItemsFromRangeProvided(string dataPoczatkowa,string dataKoncowa);
    float calculateExpensesFromRangeProvided(string dataPoczatkowa,string dataKoncowa);

};

#endif
