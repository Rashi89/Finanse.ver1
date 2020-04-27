#include "FilesWithIncomes.h"

vector <Income> FilesWithIncomes::loadIncomesFromFile(int idZalogowanegoUzytkownika) {
    vector <Income> incomes;
    Income income;

    string dataJakoString;
    int dataJakoInt;

    CMarkup xml;
    xml.Load( NAME_FILE_INCOMES );
    xml.FindElem("INCOMES");
    xml.IntoElem();
    while ( xml.FindElem("INCOME") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        if(nUserID==idZalogowanegoUzytkownika) {
            income.setUserID(nUserID);
            xml.FindElem( "INCOMEID" );
            int nIncomeID =atoi( MCD_2PCSZ(xml.GetData()) );
            income.setIncomeID(nIncomeID);
            xml.FindElem("DATE");
            MCD_STR strDate = xml.GetData();
            income.setDate(strDate);
            dataJakoString=dataMenager.swapDateWithStringWithoutDash(strDate);
            dataJakoInt=AdditionalMethods::swapStringForInt(dataJakoString);
            income.setDateAsInt(dataJakoInt);
            xml.FindElem("ITEM");
            MCD_STR strItem = xml.GetData();
            income.setItem(strItem);
            xml.FindElem( "AMOUNT" );
            MCD_STR strAmount = xml.GetData();
            income.setAmountAsString(strAmount);
            float amountJakoFloat = AdditionalMethods::swapStringForFloat(strAmount);
            income.setAmount(amountJakoFloat);
            xml.OutOfElem();
            incomes.push_back(income);
        } else
            xml.OutOfElem();
    }
    return incomes;
}

void FilesWithIncomes::appendIncomeToFile(Income income) {
    CMarkup xml;
    if(xml.Load( NAME_FILE_INCOMES )==false) {
        xml.AddElem( "INCOMES" );
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "USERID", income.getUserID() );
        xml.AddElem( "INCOMEID", income.getIncomeID() );
        xml.AddElem( "DATE", income.getDate() );
        xml.AddElem( "ITEM", income.getItem() );
        xml.AddElem( "AMOUNT", income.getAmountAsString() );

        xml.OutOfElem();
        xml.Save( NAME_FILE_INCOMES );
    } else {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "USERID", income.getUserID() );
        xml.AddElem( "INCOMEID", income.getIncomeID() );
        xml.AddElem( "DATE", income.getDate() );
        xml.AddElem( "ITEM", income.getItem() );
        xml.AddElem( "AMOUNT", income.getAmountAsString() );
        xml.OutOfElem();
        xml.Save( NAME_FILE_INCOMES );
    }
}
