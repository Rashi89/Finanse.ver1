#include <iostream>

#include "UsersMenager.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"
#include "IncomeMenager.h"

#include "AdditionalMethods.h"

using namespace std;

class Finanse
{
    UsersMenager usersMenager;
    ExpenseMenager *expenseMenager;
    IncomeMenager   *incomeMenager;
    DataMenager *dataMenager;
    const string NAME_FILE_INCOMES;
    const string NAME_FILE_EXPENSES;

public:
    Finanse(string nameFileUsers,string nameFileIncomes, string nameFileExpenses) : usersMenager(nameFileUsers),NAME_FILE_INCOMES(nameFileIncomes), NAME_FILE_EXPENSES(nameFileExpenses)
    {
        expenseMenager=NULL;
        incomeMenager=NULL;
        dataMenager=NULL;
    }
    ~Finanse()
    {
        delete expenseMenager;
        expenseMenager=NULL;
        delete incomeMenager;
        incomeMenager=NULL;
        delete dataMenager;
        dataMenager=NULL;
    }
    void registerUser();
    //void wyswietlWszystkichUzytkownikow();
    void loginUser();
    void logoutUser();
    void changePasswordLoggedUser();
    void addExpense();
    void addIncome();
    //void wyswietlWszystkieItemy();
    //void wyswietlWszystkieDaty();
    void showItemsFromThisMonth();
    void showItemsFromPreviousMonth();
    void showItemsFromRangeProvided();
    void calculateBilansFromThisMonth();
    void calculateBilansFromPreviousMonth();
    void calculateBilansFromRangeProvided(string startData,string endData);
    void sorting();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};
