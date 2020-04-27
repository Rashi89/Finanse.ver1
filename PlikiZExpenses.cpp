#include "Markup.h"
#include "Expense.h"
#include "PlikiZExpenses.h"
#include "data.h"
#include "DataMenager.h"


vector <Expense> PlikiZExpenses::wczytajItemyZPliku(int idZalogowanegoUzytkownika)
{
    vector <Expense> expenses;
    Expense expense;

    string dataJakoString;
    int dataJakoInt;

    CMarkup xml;
    xml.Load( "Expense.xml" );
    xml.FindElem("EXPENSES"); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("EXPENSE") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        if(nUserID==idZalogowanegoUzytkownika){
        expense.ustawUserID(nUserID);
        xml.FindElem( "EXPENSEID" );
        int nExpenseID =atoi( MCD_2PCSZ(xml.GetData()) );
        expense.ustawExpenseID(nExpenseID);
        xml.FindElem("DATE");
        MCD_STR strDate = xml.GetData();
        expense.ustawDate(strDate);
        dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(strDate);
        dataJakoInt=konwersjaStringNaInt(dataJakoString);
        expense.ustawDataJakoInt(dataJakoInt);
        xml.FindElem("ITEM");
        MCD_STR strItem = xml.GetData();
        expense.ustawItem(strItem);
        xml.FindElem( "AMOUNT" );
        MCD_STR strAmount = xml.GetData();
        expense.ustawAmountJakoString(strAmount);
        float amountJakoFloat = zamianaStringNaFloat(strAmount);
        expense.ustawAmount(amountJakoFloat);
        xml.OutOfElem();
        expenses.push_back(expense);
        }
        else xml.OutOfElem();
    }
    return expenses;
}

void PlikiZExpenses::dopiszItemDoPliku(Expense expense)
{
    CMarkup xml;
    if(xml.Load( "Expense.xml" )==false) {
        xml.AddElem( "EXPENSES" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.pobierzUserID() );
        xml.AddElem( "EXPENSEID", expense.pobierzExpenseID() );
        xml.AddElem( "DATE", expense.pobierzDate() );
        xml.AddElem( "ITEM", expense.pobierzItem() );
        xml.AddElem( "AMOUNT", expense.pobierzAmountJakoString() );

        xml.OutOfElem();
        xml.Save( "Expense.xml" );
    } else {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.pobierzUserID() );
        xml.AddElem( "EXPENSEID", expense.pobierzExpenseID() );
        xml.AddElem( "DATE", expense.pobierzDate() );
        xml.AddElem( "ITEM", expense.pobierzItem() );
        xml.AddElem( "AMOUNT", expense.pobierzAmountJakoString() );
        xml.OutOfElem();
        xml.Save( "Expense.xml" );
    }
}

int PlikiZExpenses::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}

float PlikiZExpenses::zamianaStringNaFloat(string liczba)
{
    string calosc="",ulamek="";
    int pozycjaPrzecinka=0;
    for(int i=0;i<liczba.length();i++)
    {
        if(liczba[i]!=','&&liczba[i]!='.')
        {
            calosc+=liczba[i];
            pozycjaPrzecinka+=1;
        }
        else if(liczba[i]==',')
        {
            i=liczba.length()-1;
        }
        else if(liczba[i]=='.')
        {
             i=liczba.length()-1;
        }
    }
    for(int i = pozycjaPrzecinka+1;i<liczba.length();i++)
    {
        ulamek+=liczba[i];
    }

    int caloscLiczby = konwersjaStringNaInt(calosc);
    float ulamkowaLiczby = konwersjaStringNaInt(ulamek);
    float wpisanaLiczbaJakoFloat;
    if(ulamek[0]=='0'){
    wpisanaLiczbaJakoFloat = caloscLiczby+ulamkowaLiczby/100;
    }
    else
    {
        wpisanaLiczbaJakoFloat = caloscLiczby+ulamkowaLiczby/100;
    }
    return wpisanaLiczbaJakoFloat;
}
