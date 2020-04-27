#include "Markup.h"
#include "Income.h"
#include "PlikiZIncomes.h"
#include "data.h"
#include "DataMenager.h"


vector <Income> PlikiZIncomes::wczytajItemyZPliku(int idZalogowanegoUzytkownika)
{
    vector <Income> incomes;
    Income income;

    string dataJakoString;
    int dataJakoInt;

    CMarkup xml;
    xml.Load( "Income.xml" );
    xml.FindElem("INCOMES"); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("INCOME") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        if(nUserID==idZalogowanegoUzytkownika){
        income.ustawUserID(nUserID);
        xml.FindElem( "INCOMEID" );
        int nIncomeID =atoi( MCD_2PCSZ(xml.GetData()) );
        income.ustawIncomeID(nIncomeID);
        xml.FindElem("DATE");
        MCD_STR strDate = xml.GetData();
        income.ustawDate(strDate);
        dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(strDate);
        dataJakoInt=konwersjaStringNaInt(dataJakoString);
        income.ustawDataJakoInt(dataJakoInt);
        xml.FindElem("ITEM");
        MCD_STR strItem = xml.GetData();
        income.ustawItem(strItem);
        xml.FindElem( "AMOUNT" );
        MCD_STR strAmount = xml.GetData();
        income.ustawAmountJakoString(strAmount);
        float amountJakoFloat = zamianaStringNaFloat(strAmount);
        income.ustawAmount(amountJakoFloat);
        xml.OutOfElem();
        incomes.push_back(income);
        }
        else xml.OutOfElem();
    }
    return incomes;
}

void PlikiZIncomes::dopiszItemDoPliku(Income income)
{
    CMarkup xml;
    if(xml.Load( "Income.xml" )==false) {
        xml.AddElem( "INCOMES" );
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "USERID", income.pobierzUserID() );
        xml.AddElem( "INCOMEID", income.pobierzIncomeID() );
        xml.AddElem( "DATE", income.pobierzDate() );
        xml.AddElem( "ITEM", income.pobierzItem() );
        xml.AddElem( "AMOUNT", income.pobierzAmountJakoString() );

        xml.OutOfElem();
        xml.Save( "Income.xml" );
    } else {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "USERID", income.pobierzUserID() );
        xml.AddElem( "INCOMEID", income.pobierzIncomeID() );
        xml.AddElem( "DATE", income.pobierzDate() );
        xml.AddElem( "ITEM", income.pobierzItem() );
        xml.AddElem( "AMOUNT", income.pobierzAmountJakoString() );
        xml.OutOfElem();
        xml.Save( "Income.xml" );
    }
}

int PlikiZIncomes::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}
float PlikiZIncomes::zamianaStringNaFloat(string liczba)
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
