#ifndef PLIKIZEXPENSES_H
#define PLIKIZEXPENSES_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
//
#include "Expense.h"
#include "Markup.h"
#include "data.h"
#include "DataMenager.h"
#include "AdditionalMethods.h"

using namespace std;

class FilesWithExpenses {
    const string NAME_FILE_EXPENSES;
    DataMenager dataMenager;
public:
    FilesWithExpenses(string nameFileExpenses): NAME_FILE_EXPENSES(nameFileExpenses) {};
    vector <Expense> loadExpensesFromFile(int idZalogowanegoUzytkownika);
    vector <Data> wczytajDatyZPliku(int idZalogowanegoUzytkownika);
    void appendExpenseToFile(Expense expense);
    int getLastID();
};
#endif
