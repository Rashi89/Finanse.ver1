#include "Markup.h"
#include "Income.h"
#include "PlikiZIncomes.h"


vector <Income> PlikiZIncomes::wczytajItemyZPliku(int idZalogowanegoUzytkownika)
{
    vector <Income> incomes;
    Income income;

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
        xml.FindElem("ITEM");
        MCD_STR strItem = xml.GetData();
        income.ustawItem(strItem);
        xml.FindElem( "AMOUNT" );
        int nAmount =atoi( MCD_2PCSZ(xml.GetData()) );
        income.ustawAmount(nAmount);
        xml.OutOfElem();
        incomes.push_back(income);
        }
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
        xml.AddElem( "AMOUNT", income.pobierzAmount() );

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
        xml.AddElem( "AMOUNT", income.pobierzAmount() );
        xml.OutOfElem();
        xml.Save( "Income.xml" );
    }
}

