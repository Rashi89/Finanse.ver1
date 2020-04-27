#ifndef PLIKIZINCOMES_H
#define PLIKIZINCOMES_H
#include <iostream>
#include <vector>
//
#include "Income.h"
#include "Markup.h"
#include "data.h"
#include "DataMenager.h"
#include "AdditionalMethods.h"

using namespace std;

class FilesWithIncomes {
    const string NAME_FILE_INCOMES;
    DataMenager dataMenager;

public:
    FilesWithIncomes(string nameFileIncomes): NAME_FILE_INCOMES(nameFileIncomes) {};
    vector <Income> loadIncomesFromFile(int idLoggedUser);
    vector <Data> wczytajDatyZPliku(int idLoggedUser);
    void appendIncomeToFile(Income income);
};
#endif
