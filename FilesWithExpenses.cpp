#include "FilesWithExpenses.h"

vector <Expense> FilesWithExpenses::loadExpensesFromFile(int idZalogowanegoUzytkownika) {
    vector <Expense> expenses;
    Expense expense;

    string dataJakoString;
    int dataJakoInt;

    CMarkup xml;
    xml.Load( NAME_FILE_EXPENSES );
    xml.FindElem("EXPENSES");
    xml.IntoElem();
    while ( xml.FindElem("EXPENSE") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        if(nUserID==idZalogowanegoUzytkownika) {
            expense.setUserID(nUserID);
            xml.FindElem( "EXPENSEID" );
            int nExpenseID =atoi( MCD_2PCSZ(xml.GetData()) );
            expense.setExpenseID(nExpenseID);
            xml.FindElem("DATE");
            MCD_STR strDate = xml.GetData();
            expense.setDate(strDate);
            dataJakoString=dataMenager.swapDateWithStringWithoutDash(strDate);
            dataJakoInt=AdditionalMethods::swapStringForInt(dataJakoString);
            expense.setDateAsInt(dataJakoInt);
            xml.FindElem("ITEM");
            MCD_STR strItem = xml.GetData();
            expense.setItem(strItem);
            xml.FindElem( "AMOUNT" );
            MCD_STR strAmount = xml.GetData();
            expense.setAmountAsString(strAmount);
            float amountJakoFloat = AdditionalMethods::swapStringForFloat(strAmount);
            expense.setAmount(amountJakoFloat);
            xml.OutOfElem();
            expenses.push_back(expense);
        } else
            xml.OutOfElem();
    }
    return expenses;
}

void FilesWithExpenses::appendExpenseToFile(Expense expense) {
    CMarkup xml;
    if(xml.Load( NAME_FILE_EXPENSES )==false) {
        xml.AddElem( "EXPENSES" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.getUserID() );
        xml.AddElem( "EXPENSEID", expense.getExpenseID() );
        xml.AddElem( "DATE", expense.getDate() );
        xml.AddElem( "ITEM", expense.getItem() );
        xml.AddElem( "AMOUNT", expense.getAmountAsString() );

        xml.OutOfElem();
        xml.Save( NAME_FILE_EXPENSES );
    } else {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.getUserID() );
        xml.AddElem( "EXPENSEID", expense.getExpenseID() );
        xml.AddElem( "DATE", expense.getDate() );
        xml.AddElem( "ITEM", expense.getItem() );
        xml.AddElem( "AMOUNT", expense.getAmountAsString() );
        xml.OutOfElem();
        xml.Save( NAME_FILE_EXPENSES );
    }
}
