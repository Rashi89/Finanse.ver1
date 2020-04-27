#ifndef DATAMENAGER_H
#define DATAMENAGER_H
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "data.h"
#include "Expense.h"
#include "Income.h"
#include "AdditionalMethods.h"
//#include "IncomeMenager.h"

//#include "ExpenseMenager.h"
//#include "IncomeMenager.h"
//#include "PlikiZIncomes.h"
//#include "data.h"
//#include "Expense.h"
#include "Markup.h"

using namespace std;

class DataMenager
{
    bool isLapYear(int year);
    int getIDnewData();
    string getTodayDataAsString(Data data);
    string todayData();
    int todayDataAsInt();
    int calculateDaysCurrentMonth();
    int lastDateInCurrentMonthAsInt();


public:
    DataMenager(){};
    vector <Data> loadData(int idLoggedUser);
    string swapDateWithStringWithoutDash(string givenDate);
    bool isDateInARange(string givenDate);
    Data loadTodayDate();
    bool giveDate(string givenDate);
    int changeDateToYear(string givenDate);
    int changeDateToMonth(string givenDate);
    int changeDateToDay(string givenDate);
    bool isDateGood(int year, int month, int day);
    int thisMonth();
    bool isDateFormat(string givenDate);
    bool isCorrectDate(string date);


};
#endif
