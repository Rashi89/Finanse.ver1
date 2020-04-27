#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>

#include "ExpenseMenager.h"

void ExpenseMenager::addExpense() {
    Expense expense;
    Data data;

    char sign;

    cout << " >>> DODAWANIE NOWEGO ITEMU <<<" << endl << endl;
    cout<<"Czy chcesz dodac nowy produkt z dzisiejsza data? <t/n>"<<endl;
    cin>>sign;
    if(sign=='n')
    {
        cout << "Podaj date: ";
        cin.sync();
        string givenData=AdditionalMethods::loadLines();
        if(dataMenager.isDateFormat(givenData)==true&&dataMenager.isCorrectDate(givenData)==true){
        if(dataMenager.isDateInARange(givenData)==true)
        {
            expense=getNewItemData(sign,givenData);
            expenses.push_back(expense);
            filesWithExpenses.appendExpenseToFile(expense);
        }
        else cout<<"Zla data!"<<endl;
    }
    else if(dataMenager.isDateFormat(givenData)==false) cout<<"Zly format daty!"<<endl;
    else if(dataMenager.isCorrectDate(givenData)==false) cout<<"Zla data"<<endl;
    system("pause");
    }
    else if(sign=='t')
    {
        data =dataMenager.loadTodayDate();

        string givenData=data.getDateWithDashesAsString();
        expense=getNewItemData(sign,givenData);
        expenses.push_back(expense);
        filesWithExpenses.appendExpenseToFile(expense);
    }
}

Expense ExpenseMenager::getNewItemData(char sign, string givenData) {

    vector <Data> daty;
    Expense expense;
    Data data;

    int dateAsInt;
    float amount;
    string amountAsString,itemName,dateAsString;

    if(sign=='n')
    {
        if(dataMenager.giveDate(givenData)==true)
        {
            expense.setExpenseID(getIDNewExpense());
            expense.setUserID(ID_LOGGED_USER);
            expense.setDate(givenData);
            dateAsString=dataMenager.swapDateWithStringWithoutDash(givenData);
            dateAsInt=AdditionalMethods::swapStringForInt(dateAsString);
            expense.setDateAsInt(dateAsInt);
            cout << "Podaj nazwe produktu: ";
            cin.sync();
            itemName=AdditionalMethods::loadLines();
            expense.setItem(itemName);
            cout << "Podaj kwote: ";
            cin.sync();
            cin>>amountAsString;
            string amountWithDot = AdditionalMethods::swapCommaToDot(amountAsString);
            expense.setAmountAsString(amountWithDot);
            amount = AdditionalMethods::swapStringForFloat(amountWithDot);
            expense.setAmount(amount);

        }

        else cout<<"Zle dane!"<<endl;
                }
    else if(sign=='t')
    {
        expense.setExpenseID(getIDNewExpense());
        expense.setUserID(ID_LOGGED_USER);

        expense.setDate(givenData);
        dateAsString=dataMenager.swapDateWithStringWithoutDash(givenData);
        dateAsInt=AdditionalMethods::swapStringForInt(dateAsString);
        expense.setDateAsInt(dateAsInt);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        itemName=AdditionalMethods::loadLines();
        expense.setItem(itemName);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amountAsString;
        string amountWithDot = AdditionalMethods::swapCommaToDot(amountAsString);
        expense.setAmountAsString(amountWithDot);
        amount = AdditionalMethods::swapStringForFloat(amountWithDot);
        expense.setAmount(amount);

    }
    else
        cout<<"Zly znak"<<endl;
        return expense;
}

int ExpenseMenager::getIDNewExpense() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseID() + 1;
}

void ExpenseMenager::wyswietlWszystkieItemy()
{
    if (!expenses.empty()) {
        cout << "             >>>WYDATKI<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            showExpense(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

/*void ExpenseMenager::wyswietlWszystkieDaty()
{
    if (!daty.empty()) {
        cout << "             >>> DATY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout<<daty.size()<<endl;
        for (vector <Data> :: iterator itr = daty.begin(); itr != daty.end(); itr++) {
            wyswietlDate(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak dat." << endl << endl;
    }
}

void ExpenseMenager::wyswietlDate(Data data) {
    if(data.pobierzMiesiac()<10&&data.pobierzDzien()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-0"<<data.pobierzMiesiac()<<"-0"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else if(data.pobierzMiesiac()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-0"<<data.pobierzMiesiac()<<"-"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else if(data.pobierzDzien()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-"<<data.pobierzMiesiac()<<"-0"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else{
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-"<<data.pobierzMiesiac()<<"-"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    }
}*/

void ExpenseMenager::sorting()
{
    sortingExpense(expenses);
}

void ExpenseMenager::sortingExpense(vector <Expense> &expenses)
{
    sort(expenses.begin(),expenses.end());
}

void ExpenseMenager::showExpense(Expense expense)
{
    //cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.getExpenseID()<<endl;
    cout<<"Data: "<< expense.getDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.getItem()<<endl;
    cout<<"Koszt: "<< expense.getAmount()<<endl;
    //cout<<"Data jako int: "<<expense.getDateAsInt()<<endl;
}

void ExpenseMenager::showItemsFromThisMonth()
{
     if (!expenses.empty()) {
        cout << "             >>>WYDATKI<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            showExpenseFromThisMonth(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void ExpenseMenager::showExpenseFromThisMonth(Expense expense)
{
    int thisMonth=dataMenager.thisMonth();
    int day=expense.getDateAsInt()%100;
    int month=(expense.getDateAsInt()%10000-day)/100;
    if(month==thisMonth){
    //cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.getExpenseID()<<endl;
    cout<<"Data: "<< expense.getDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.getItem()<<endl;
    cout<<"Koszt: "<< expense.getAmount()<<endl;
    cout << endl;
    }
}

float ExpenseMenager::calculateExpensesFromThisMonth()
{
    int thisMonth=dataMenager.thisMonth();
    float sumExpenses=0;
    if (!expenses.empty()) {
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            int day=itr->getDateAsInt()%100;
            int month=(itr->getDateAsInt()%10000-day)/100;
            if(month==thisMonth){
                sumExpenses+=itr->getAmount();
            }
        }
        cout<<"Suma wydatkow z obecnego miesiaca: "<<sumExpenses<<endl;
        return sumExpenses;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void ExpenseMenager::showItemsFromPreviousMonth()
{
     if (!expenses.empty()) {
        cout << "             >>>WYDATKI<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            showExpenseFromPreviousMonth(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void ExpenseMenager::showExpenseFromPreviousMonth(Expense expense)
{
    int previousMonth=dataMenager.thisMonth()-1;
    int day=expense.getDateAsInt()%100;
    int month=(expense.getDateAsInt()%10000-day)/100;
    if(month==previousMonth){
    //cout<<"ID uzytkownika: "<< expense.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< expense.getExpenseID()<<endl;
    cout<<"Data: "<< expense.getDate()<<endl;
    cout<<"Nazwa itemu: "<< expense.getItem()<<endl;
    cout<<"Koszt: "<< expense.getAmount()<<endl;
    cout << endl;
    }
}

float ExpenseMenager::calculateExpensesFromPreviousMonth()
{
    int previousMonth=dataMenager.thisMonth()-1;
    float sumExpenses=0;
    if (!expenses.empty()) {
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            int day=itr->getDateAsInt()%100;
            int month=(itr->getDateAsInt()%10000-day)/100;
            if(month==previousMonth){
                sumExpenses+=itr->getAmount();
            }
        }
        cout<<"Suma wydatkow z poprzedniego miesiaca: "<<sumExpenses<<endl;
        return sumExpenses;
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

bool ExpenseMenager::isCorrectDate(string date)
{
    int year=dataMenager.changeDateToYear(date);
    int month=dataMenager.changeDateToMonth(date);
    int day=dataMenager.changeDateToDay(date);

    if(dataMenager.isDateGood(year, month, day)==true)
        return true;
    else return false;
}

void ExpenseMenager::showItemsFromRangeProvided(string startingDate,string endDate)
{
    int yearStartingDate=0;
    int monthStartingDate=0;
    int dayStartingDate=0;
    int yearEndDate=0;
    int monthEndDate=0;
    int dayEndDate=0;

    if(isCorrectDate(startingDate)==true){
        yearStartingDate=dataMenager.changeDateToYear(startingDate);
        monthStartingDate=dataMenager.changeDateToMonth(startingDate);
        dayStartingDate=dataMenager.changeDateToDay(startingDate);
    }
    else cout<<"Bledna data poczatkowa!"<<endl;

    if(isCorrectDate(endDate)==true){
        yearEndDate=dataMenager.changeDateToYear(endDate);
        monthEndDate=dataMenager.changeDateToMonth(endDate);
        dayEndDate=dataMenager.changeDateToDay(endDate);
    }
     else
     {
         cout<<"Bledna data koncowa!"<<endl;
     }

     if(isCorrectDate(endDate)==true&&isCorrectDate(startingDate)==true)
     {
             if(yearStartingDate<yearEndDate){
             showExpenseFromRangeProvided(startingDate,endDate);
             }
             else if(yearStartingDate==yearEndDate)
             {
                 if(monthStartingDate<monthEndDate)
                 {
                    showExpenseFromRangeProvided(startingDate,endDate);
                 }
                 else if(monthStartingDate==monthEndDate)
                 {
                     if(dayStartingDate<dayEndDate)
                     {
                        showExpenseFromRangeProvided(startingDate,endDate);
                     }
                     else if(dayStartingDate==dayEndDate)
                     {
                        showExpenseFromRangeProvided(startingDate,endDate);
                     }
                     else if(dayStartingDate>dayEndDate) cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa!"<<endl;
                 }
                 else if(monthStartingDate>monthEndDate) cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa!"<<endl;
             }
             else if(yearStartingDate>yearEndDate) cout<<"Data koncowa nie moze byc wczesniej niz poczatkowa!"<<endl;
     }
}

void ExpenseMenager::showExpenseFromRangeProvided(string startingDate,string endDate)
{
    string startingDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(startingDate);
    int startingDataIsInt = AdditionalMethods::swapStringForInt(startingDateWithoutDash);
    string endDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(endDate);
    int endDateIsInt = AdditionalMethods::swapStringForInt(endDateWithoutDash);
     if (!expenses.empty()) {
        cout << "             >>>WYDATKI<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if(startingDataIsInt<=itr->getDateAsInt()&&itr->getDateAsInt()<=endDateIsInt)
            {
                //cout<<"ID uzytkownika: "<< itr->pobierzUserID()<<endl;
                cout<<"ID itemu: "<< itr->getExpenseID()<<endl;
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

float ExpenseMenager::calculateExpensesFromRangeProvided(string startingData,string endDate)
{
    string startingDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(startingData);
    int startingDataIsInt = AdditionalMethods::swapStringForInt(startingDateWithoutDash);
    string endDateWithoutDash=dataMenager.swapDateWithStringWithoutDash(endDate);
    int endDateIsInt = AdditionalMethods::swapStringForInt(endDateWithoutDash);
    float sumExpenseFromRangeProvided=0;

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if(startingDataIsInt<=itr->getDateAsInt()&&itr->getDateAsInt()<=endDateIsInt)
            {
                sumExpenseFromRangeProvided+=itr->getAmount();
            }
        }
        return sumExpenseFromRangeProvided;
        cout << endl;
}
