#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "Income.h"
#include "data.h"
#include "DataMenager.h"
#include "FilesWithIncomes.h"
#include "AdditionalMethods.h"

using namespace std;

class IncomeMenager {
    const int ID_LOGGED_USER;

    vector <Income> incomes;
    vector <Data> daty;
    DataMenager dataMenager;
    FilesWithIncomes filesWithIncomes;

    Income getNewItemData(char sign, string givenData);
    int getIDNewIncome();
    void showIncome(Income income);
    void showIncomeFromThisMonth(Income income);
    void showIncomeFromPreviousMonth(Income income);
    void sortingIncomes(vector <Income> &income);
    void showIncomeFromRangeProvided(string startingDate,string endDate);

public:
    IncomeMenager(string nameFileIncomes,int idLoggedUser): filesWithIncomes(nameFileIncomes),ID_LOGGED_USER(idLoggedUser) {
        incomes= filesWithIncomes.loadIncomesFromFile(ID_LOGGED_USER);
        daty = dataMenager.loadData(ID_LOGGED_USER);
    };

    void addIncome();
    void showItemsFromThisMonth();
    void showItemsFromPreviousMonth();
    void showItemsFromRangeProvided(string startingDate, string endDate);
    float calculateIncomesFromThisMonth();
    float calculateIncomesFromPreviousMonth();
    float calculateIncomesFromRangeProvided(string startingDate,string endDate);
    bool isCorrectDate(string date);
    void sorting();

};
#endif
