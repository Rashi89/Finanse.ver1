#include <iostream>
#include <vector>
#include "Markup.h"
#include "Finanse.h"
#include "DataMenager.h"
#include "ExpenseMenager.h"

using namespace std;

int main() {

    char wybor;
    Finanse finanse("Users.xml","Income.xml","Expense.xml");

    while(true)
    {
        if(finanse.isUserLoggedIn()==false)
        {
            wybor = finanse.selectOptionFromMainMenu();

            switch (wybor)
            {
            case '1':
                finanse.registerUser();
                break;
            case '2':
                finanse.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout<<endl<<"Nie ma takiej opcji w menu."<<endl<<endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = finanse.selectOptionFromUserMenu();
            switch (wybor)
            {
            case '1':
                finanse.addIncome();
                break;
            case '2':
                finanse.addExpense();
                break;
            case'3':
                finanse.sorting();
                finanse.showItemsFromThisMonth();
                finanse.calculateBilansFromThisMonth();
                system("pause");
                break;
            case '4':
                finanse.sorting();
                finanse.showItemsFromPreviousMonth();
                finanse.calculateBilansFromPreviousMonth();
                system("pause");
                break;
            case '5':
                finanse.sorting();
                finanse.showItemsFromRangeProvided();
                system("pause");
                break;
            case '6':
                finanse.changePasswordLoggedUser();
                break;
            case '7':
                finanse.logoutUser();
                break;
            }
        }
    }
    return 0;
}
