#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>
#include <sstream>

#include "IncomeMenager.h"

void IncomeMenager::addIncome() {
    Income income;
    Data data;

    char sign;

    cout << " >>> DODAWANIE NOWEGO ITEMU <<<" << endl << endl;
    cout<<"Czy chcesz dodac nowy produkt z dzisiejsza data? <t/n>"<<endl;
    cin>>sign;
    if(sign=='n')
    {
        cout << "Podaj date (yyyy-mm-dd): ";
        cin.sync();
        string givenData=AdditionalMethods::loadLines();
        if(dataMenager.isDateFormat(givenData)==true&&isCorrectDate(givenData)==true){
        if(dataMenager.isDateInARange(givenData)==true)
        {
            income=getNewItemData(sign,givenData);
            incomes.push_back(income);
            filesWithIncomes.appendIncomeToFile(income);
        }
        else cout<<"Zla data!"<<endl;
    }
    else if(dataMenager.isDateFormat(givenData)==false) cout<<"Zly format daty!"<<endl;
    else if(isCorrectDate(givenData)==false) cout<<"Zla data"<<endl;
    system("pause");
    }
    else if(sign=='t')
    {
        data =dataMenager.loadTodayDate();

        string givenData=data.getDateWithDashesAsString();
        income=getNewItemData(sign,givenData);
        incomes.push_back(income);
        filesWithIncomes.appendIncomeToFile(income);
    }
}

Income IncomeMenager::getNewItemData(char sign, string givenData) {

    vector <Data> daty;
    Income income;
    Data data;

    float amount;
    int dateAsInt;
    string amountAsString,itemName,dateAsString;

    if(sign=='n')
    {
        if(dataMenager.giveDate(givenData)==true)
        {
            income.setIncomeID(getIDNewIncome());
            income.setUserID(ID_LOGGED_USER);
            income.setDate(givenData);
            dateAsString=dataMenager.swapDateWithStringWithoutDash(givenData);
            dateAsInt=AdditionalMethods::swapStringForInt(dateAsString);
            income.setDateAsInt(dateAsInt);
            cout << "Podaj nazwe produktu: ";
            cin.sync();
            itemName=AdditionalMethods::loadLines();
            income.setItem(itemName);
            cout << "Podaj kwote: ";
            cin.sync();
            cin>>amountAsString;
            string amountWithDot = AdditionalMethods::swapCommaToDot(amountAsString);
            income.setAmountAsString(amountWithDot);
            amount = AdditionalMethods::swapStringForFloat(amountWithDot);
            income.setAmount(amount);
        }

        else cout<<"Zla data!"<<endl;
                }
    else if(sign=='t')
    {
        income.setIncomeID(getIDNewIncome());
        income.setUserID(ID_LOGGED_USER);

        income.setDate(givenData);
        dateAsString=dataMenager.swapDateWithStringWithoutDash(givenData);
        dateAsInt=AdditionalMethods::swapStringForInt(dateAsString);
        income.setDateAsInt(dateAsInt);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        itemName=AdditionalMethods::loadLines();
        income.setItem(itemName);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amountAsString;
        string amountWithDot = AdditionalMethods::swapCommaToDot(amountAsString);
        income.setAmountAsString(amountWithDot);
        amount = AdditionalMethods::swapStringForFloat(amountWithDot);
        income.setAmount(amount);
    }
    else
        cout<<"Zly znak"<<endl;
        return income;
}

/*void IncomeMenager::wyswietlWszystkieIncome()
{
    if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            showIncome(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}*/
void IncomeMenager::showIncome(Income income)
{
    //cout<<"ID uzytkownika: "<< income.getUserID()<<endl;
    cout<<"ID itemu: "<< income.getIncomeID()<<endl;
    cout<<"Data: "<< income.getDate()<<endl;
    cout<<"Nazwa itemu: "<< income.getItem()<<endl;
    cout<<"Koszt: "<< income.getAmount()<<endl;
    //cout<<"Data jako int: "<<income.getDateAsInt()<<endl;
    //cout<<"Income jako string: "<<income.getAmountAsString()<<endl;
}

void IncomeMenager::showItemsFromThisMonth()
{
     if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            showIncomeFromThisMonth(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void IncomeMenager::showIncomeFromThisMonth(Income income)
{
    int thisMonth=dataMenager.thisMonth();
    int day=income.getDateAsInt()%100;
    int month=(income.getDateAsInt()%10000-day)/100;
    if(month==thisMonth){
    //cout<<"ID uzytkownika: "<< income.getUserID()<<endl;
    cout<<"ID itemu: "<< income.getIncomeID()<<endl;
    cout<<"Data: "<< income.getDate()<<endl;
    cout<<"Nazwa itemu: "<< income.getItem()<<endl;
    cout<<"Koszt: "<< income.getAmount()<<endl;
    cout << endl;
    }
}

float IncomeMenager::calculateIncomesFromThisMonth()
{
    int thisMonth=dataMenager.thisMonth();
    float sumIncomes=0;
    if (!incomes.empty()) {
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            int day=itr->getDateAsInt()%100;
            int month=(itr->getDateAsInt()%10000-day)/100;
            if(month==thisMonth){
                sumIncomes+=itr->getAmount();
            }
        }
        cout<<"Suma przychodow z obecnego miesiaca: "<<sumIncomes<<endl;
        return sumIncomes;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}


void IncomeMenager::showItemsFromPreviousMonth()
{
     if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            showIncomeFromPreviousMonth(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void IncomeMenager::showIncomeFromPreviousMonth(Income income)
{
    int previousMonth=dataMenager.thisMonth()-1;
    int day=income.getDateAsInt()%100;
    int month=(income.getDateAsInt()%10000-day)/100;
    if(month==previousMonth){
    //cout<<"ID uzytkownika: "<< income.getUserID()<<endl;
    cout<<"ID itemu: "<< income.getIncomeID()<<endl;
    cout<<"Data: "<< income.getDate()<<endl;
    cout<<"Nazwa itemu: "<< income.getItem()<<endl;
    cout<<"Koszt: "<< income.getAmount()<<endl;
    cout << endl;
    }
}

float IncomeMenager::calculateIncomesFromPreviousMonth()
{
    int previousMonth=dataMenager.thisMonth()-1;
    float sumIncomesInPreviousMonth=0;
    if (!incomes.empty()) {
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            int day=itr->getDateAsInt()%100;
            int month=(itr->getDateAsInt()%10000-day)/100;
            if(month==previousMonth){
                sumIncomesInPreviousMonth+=itr->getAmount();
            }
        }
        cout<<"Suma przychodow z poprzedniego miesiaca: "<<sumIncomesInPreviousMonth<<endl;
        return sumIncomesInPreviousMonth;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}
void IncomeMenager::showItemsFromRangeProvided(string startingData, string endDate)
{
    int yearStartingDate=0;
    int monthStartingData=0;
    int dayStartingData=0;
    int yearEndDate=0;
    int monthEndDate=0;
    int dayEndDate=0;

    if(isCorrectDate(startingData)==true){
        yearStartingDate=dataMenager.changeDateToYear(startingData);
        monthStartingData=dataMenager.changeDateToMonth(startingData);
        dayStartingData=dataMenager.changeDateToDay(startingData);
    }
    else;

    if(isCorrectDate(endDate)==true){
        yearEndDate=dataMenager.changeDateToYear(endDate);
        monthEndDate=dataMenager.changeDateToMonth(endDate);
        dayEndDate=dataMenager.changeDateToDay(endDate);
    }
     else
     {
         ;
     }

     if(isCorrectDate(endDate)==true&&isCorrectDate(startingData)==true)
     {
             if(yearStartingDate<yearEndDate){
             showIncomeFromRangeProvided(startingData,endDate);
             }
             else if(yearStartingDate==yearEndDate)
             {
                 if(monthStartingData<monthEndDate)
                 {
                    showIncomeFromRangeProvided(startingData,endDate);
                 }
                 else if(monthStartingData==monthEndDate)
                 {
                     if(dayStartingData<dayEndDate)
                     {
                        showIncomeFromRangeProvided(startingData,endDate);
                     }
                     else if(dayStartingData==dayEndDate)
                     {
                        showIncomeFromRangeProvided(startingData,endDate);
                     }
                     else if(dayStartingData>dayEndDate) ;
                 }
                 else if(monthStartingData>monthEndDate) ;
             }
             else if(yearStartingDate>yearEndDate) ;
     }
}

void IncomeMenager::showIncomeFromRangeProvided(string startingData,string endDate)
{
    string startingDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(startingData);
    int startingDataIsInt = AdditionalMethods::swapStringForInt(startingDateWithoutDash);
    string endDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(endDate);
    int endDateIsInt = AdditionalMethods::swapStringForInt(endDateWithoutDash);
     if (!incomes.empty()) {
        cout << "             >>>PRZYCHODY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if(startingDataIsInt<=itr->getDateAsInt()&&itr->getDateAsInt()<=endDateIsInt)
            {
                //cout<<"ID uzytkownika: "<< itr->pobierzUserID()<<endl;
                cout<<"ID itemu: "<< itr->getIncomeID()<<endl;
                cout<<"Data: "<< itr->getDate()<<endl;
                cout<<"Nazwa itemu: "<< itr->getItem()<<endl;
                cout<<"Koszt: "<< itr->getAmount()<<endl;
                cout << endl;
            }
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

float IncomeMenager::calculateIncomesFromRangeProvided(string startingData,string endDate)
{
    string startingDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(startingData);
    int startingDataIsInt = AdditionalMethods::swapStringForInt(startingDateWithoutDash);
    string endDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(endDate);
    int endDateIsInt = AdditionalMethods::swapStringForInt(endDateWithoutDash);
    float sumIncomesFromRangeProvided=0;
    if (!incomes.empty()) {
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if(startingDataIsInt<=itr->getDateAsInt()&&itr->getDateAsInt()<=endDateIsInt)
            {
                sumIncomesFromRangeProvided+=itr->getAmount();
            }
        }
        return sumIncomesFromRangeProvided;
        cout << endl;
}
}

bool IncomeMenager::isCorrectDate(string date)
{
    int year=dataMenager.changeDateToYear(date);
    int month=dataMenager.changeDateToMonth(date);
    int day=dataMenager.changeDateToDay(date);

    if(dataMenager.isDateGood(year, month, day)==true)
        return true;
    else return false;
}

void IncomeMenager::sorting()
{
    sortingIncomes(incomes);
}

void IncomeMenager::sortingIncomes(vector <Income> &incomes)
{
    sort(incomes.begin(),incomes.end());

}

int IncomeMenager::getIDNewIncome() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeID() + 1;
}
