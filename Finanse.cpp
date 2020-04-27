#include "Finanse.h"

void Finanse::registerUser()
{
    usersMenager.registerUser();
}

/*void Finanse::wyswietlWszystkichUzytkownikow()
{
    usersMenager.wyswietlWszystkichUzytkownikow();
}*/

void Finanse::loginUser()
{
    usersMenager.loginUser();
    if(usersMenager.isUserLoggedIn())
    {
        expenseMenager = new ExpenseMenager(NAME_FILE_EXPENSES,usersMenager.loadIDLoggedUser());
        incomeMenager =  new IncomeMenager(NAME_FILE_INCOMES,usersMenager.loadIDLoggedUser());
        dataMenager = new DataMenager();
    }
}

void Finanse::logoutUser()
{
    usersMenager.logoutUser();
}

void Finanse::changePasswordLoggedUser()
{
    usersMenager.changePasswordLoggedUser();
}

void Finanse::addExpense()
{
    if(usersMenager.isUserLoggedIn())
    {
        expenseMenager->addExpense();
    }
    else
    {
        cout<<"Aby dodac item nalezy sie zalogowac!"<<endl;
        system("pause");
    }
}

/*void Finanse::wyswietlWszystkieItemy()
{
    if(usersMenager.isUserLoggedIn())
    {
        expenseMenager->wyswietlWszystkieItemy();
        incomeMenager->wyswietlWszystkieIncome();
    }
}*/
 void Finanse::showItemsFromThisMonth()
 {
     if(usersMenager.isUserLoggedIn())
    {
        incomeMenager->showItemsFromThisMonth();
        expenseMenager->showItemsFromThisMonth();
    }
 }
  void Finanse::showItemsFromPreviousMonth()
 {
     if(usersMenager.isUserLoggedIn())
    {
        incomeMenager->showItemsFromPreviousMonth();
        expenseMenager->showItemsFromPreviousMonth();
    }
 }

 void Finanse::calculateBilansFromThisMonth()
 {
     if(usersMenager.isUserLoggedIn())
    {
        float bilans = incomeMenager->calculateIncomesFromThisMonth()-expenseMenager->calculateExpensesFromThisMonth();
       cout<<"Bilans z obecnego miesiaca: "<<bilans<<endl;
    }
 }
 void Finanse::calculateBilansFromPreviousMonth()
 {
     if(usersMenager.isUserLoggedIn())
    {
        float bilans = incomeMenager->calculateIncomesFromPreviousMonth()-expenseMenager->calculateExpensesFromPreviousMonth();
        cout<<"Bilans z poprzedniego miesiaca: "<<bilans<<endl;
    }
 }

  void Finanse::showItemsFromRangeProvided()
 {
     if(usersMenager.isUserLoggedIn())
    {
        string startingDate;
        string endDate;
        cout<<"Podaj date poczatkowa: ";
        cin>>startingDate;
        cout<<"Podaj date koncowa: ";
        cin>>endDate;
        if(dataMenager->isDateFormat(startingDate)==true&&dataMenager->isDateFormat(endDate)==true){
        if(incomeMenager->isCorrectDate(startingDate)==true && incomeMenager->isCorrectDate(endDate)==true)
        {
        incomeMenager->showItemsFromRangeProvided(startingDate,endDate);
        expenseMenager->showItemsFromRangeProvided(startingDate,endDate);

           calculateBilansFromRangeProvided(startingDate,endDate);
        }
        }
        else cout<<"Zly format daty!"<<endl;
    }
 }
 void Finanse::calculateBilansFromRangeProvided(string startingDate,string endDate)
 {
     if(usersMenager.isUserLoggedIn())
    {
        float incomeFromRangeProvided=incomeMenager->calculateIncomesFromRangeProvided(startingDate,endDate);
       cout<<"Suma przychodow w podanym okresie: "<<incomeFromRangeProvided<<endl;
       float expenseFromRangeProvided=expenseMenager->calculateExpensesFromRangeProvided(startingDate,endDate);
       cout<<"Suma wydatkow w podanym okresie: "<<expenseFromRangeProvided<<endl;
        float bilans = incomeMenager->calculateIncomesFromRangeProvided(startingDate,endDate)-expenseMenager->calculateExpensesFromRangeProvided(startingDate,endDate);
        cout<<"Bilans z wybranego okresu: "<<bilans<<endl;
    }
 }

/*void Finanse::wyswietlWszystkieDaty()
{
    if(usersMenager.isUserLoggedIn())
    {
        expenseMenager->wyswietlWszystkieDaty();
    }
}*/

void Finanse::sorting()
{
    if(usersMenager.isUserLoggedIn())
    {
        incomeMenager->sorting();
        expenseMenager->sorting();
    }
}

void Finanse::addIncome()
{
    if(usersMenager.isUserLoggedIn())
    {
        incomeMenager->addIncome();
    }
    else
    {
        cout<<"Aby dodac item nalezy sie zalogowac!"<<endl;
        system("pause");
    }
}

bool Finanse::isUserLoggedIn()
{
    if(usersMenager.isUserLoggedIn())
        return true;
    else
        return false;
}

char Finanse::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AdditionalMethods::loadSign();

    return choice;
}

char Finanse::selectOptionFromUserMenu()
{
    usersMenager.selectOptionFromUserMenu();
}
