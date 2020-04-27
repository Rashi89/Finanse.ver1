#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
#include <winbase.h>

#include "DataMenager.h"

bool DataMenager::giveDate(string givenDate) {
    vector <Data> daty;
    Data data;
    int id,year,month,day;
    year=changeDateToYear(givenDate);
    month=changeDateToMonth(givenDate);
    day=changeDateToDay(givenDate);
    if(isDateGood(year, month, day)==true) {
        data.setID(getIDnewData());
        data.setYear(year);
        data.setMonth(month);
        data.setDay(day);
        data.setDateWithDashesAsString(givenDate);
        data.setDateWithoutDasesAsInt(AdditionalMethods::swapStringForInt(swapDateWithStringWithoutDash(givenDate)));
        daty.push_back(data);
        return true;
    } else return false;
}

Data DataMenager::loadTodayDate()
{
    vector <Data> daty;
    Data data;
    SYSTEMTIME st;
    GetSystemTime(&st);
        data.setID(getIDnewData());
        data.setYear(st.wYear);
        data.setMonth(st.wMonth);
        data.setDay(st.wDay);
        string givenDate;
        givenDate+=AdditionalMethods::swapIntForString(st.wYear);
        givenDate+="-";
        if(st.wMonth<10)
        {
            givenDate+="0";
            givenDate+=AdditionalMethods::swapIntForString(st.wMonth);
            givenDate+="-";
        }
        else{
            givenDate+=AdditionalMethods::swapIntForString(st.wMonth);
            givenDate+="-";
        }
        if(st.wDay<10)
        {
            givenDate+="0";
            givenDate+=AdditionalMethods::swapIntForString(st.wDay);
        }
        else{
           givenDate+=AdditionalMethods::swapIntForString(st.wDay);
        }

        data.setDateWithDashesAsString(givenDate);
        data.setDateWithoutDasesAsInt(AdditionalMethods::swapStringForInt(swapDateWithStringWithoutDash(givenDate)));
        daty.push_back(data);
        return data;
}

int DataMenager::getIDnewData() {
    vector <Data> daty;
    if (daty.empty() == true)
        return 1;
    else
        return daty.back().getID() + 1;
}

bool DataMenager::isLapYear(int year) {
    if(year%4==0&&year%100!=0) {
        return true;
    } else if(year%400==0) {
        return true;
    } else {
        return false;
    }
}

bool DataMenager::isDateGood(int year, int month, int day) {
    if(month>12)
        return false;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) {
        if(day<=31&&day>=1) {
            return true;
        } else
            return false;
    } else if(month==4||month==6||month==9||month==11) {
        if(day<=30&&day>=1) {
            return true;
        } else
            return false;
    } else if(month==2) {
        if(isLapYear(year)==true) {
            if(day<=29&&day>=1) {
                return true;
            } else
                return false;
        } else {
            if(day<=28&&day>=1) {
                return true;
            } else
                return false;
        }
    }
}

int DataMenager::changeDateToYear(string givenDate) {
    int year;
    string singleData = "";
    int numberSingleData = 1;
    for(int signPosition=0; signPosition<givenDate.length(); signPosition++) {
        if (givenDate[signPosition] != '-') {
            singleData += givenDate[signPosition];
        } else {
            switch(numberSingleData) {
            case 1:
                year=(atoi(singleData.c_str()));
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return year;
}

int DataMenager::changeDateToMonth(string givenDate) {
    int month;
    string singleData = "";
    int numberSingleData = 1;
    for(int signPosition=0; signPosition<givenDate.length(); signPosition++) {
        if (givenDate[signPosition] != '-') {
            singleData += givenDate[signPosition];
        } else {
            switch(numberSingleData) {
            case 2:
                month=(atoi(singleData.c_str()));
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return month;
}

int DataMenager::changeDateToDay(string givenDate) {
    int day,number;
    string singleData = "";
    int numberSingleData = 1;
    for(int signPosition=givenDate.length()-1; signPosition>0; signPosition--) {
        if (givenDate[signPosition] != '-') {
            singleData += givenDate[signPosition];
        } else {
            switch(numberSingleData) {
            case 1:
                number=(atoi(singleData.c_str()));
                if(number%10==0) {
                    day=number/10;
                } else
                    day=number%10*10+(number-number%10)/10;
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return day;
}

string DataMenager::swapDateWithStringWithoutDash(string givenDate) {
    string dateWithoutDash="";

    int numberDash=0;
    for(int signPosition=0; signPosition<givenDate.length(); signPosition++) {
        if(givenDate[signPosition]=='-') {
            ;
        } else {
            dateWithoutDash+=givenDate[signPosition];
        }
    }
    return dateWithoutDash;
}

string DataMenager::todayData() {
    Data data;
    data=loadTodayDate();
    string dateWithDash="";
    dateWithDash=data.getDateWithDashesAsString();

    return dateWithDash;
}
string DataMenager::getTodayDataAsString(Data data)
{
    string dateWithDash="";
    dateWithDash=data.getDateWithDashesAsString();

    return dateWithDash;
}

int DataMenager::todayDataAsInt()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    string todayDateAsString;
        todayDateAsString+=AdditionalMethods::swapIntForString(st.wYear);
        todayDateAsString+="-";
        if(st.wMonth<10)
        {
            todayDateAsString+="0";
            todayDateAsString+=AdditionalMethods::swapIntForString(st.wMonth);
            todayDateAsString+="-";
        }
        else{
            todayDateAsString+=AdditionalMethods::swapIntForString(st.wMonth);
            todayDateAsString+="-";
        }
        if(st.wDay<10)
        {
            todayDateAsString+="0";
            todayDateAsString+=AdditionalMethods::swapIntForString(st.wDay);
        }
        else{
           todayDateAsString+=AdditionalMethods::swapIntForString(st.wDay);
        }

        todayDateAsString=swapDateWithStringWithoutDash(todayDateAsString);

        int todayDateAsInt = AdditionalMethods::swapStringForInt(todayDateAsString);
        return todayDateAsInt;
}

vector <Data> DataMenager::loadData(int idLoggedUser)
{
    vector <Data> daty;
    Data data;

    int id,year,month,day;

    CMarkup xml;
    xml.Load( "Expense.xml" );
    xml.FindElem("EXPENSES"); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("EXPENSE") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        if(nUserID==idLoggedUser){
        xml.FindElem( "EXPENSEID" );
        int nIncomeID =atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem("DATE");
        MCD_STR strDate = xml.GetData();
        year=changeDateToYear(strDate);
        month=changeDateToMonth(strDate);
        day=changeDateToDay(strDate);
        data.setID(nIncomeID);
        data.setYear(year);
        data.setMonth(month);
        data.setDay(day);
        data.setDateWithDashesAsString(strDate);
        data.setDateWithoutDasesAsInt(AdditionalMethods::swapStringForInt(swapDateWithStringWithoutDash(strDate)));
        xml.OutOfElem();
        daty.push_back(data);
        }
        else xml.OutOfElem();
    }
    return daty;
}

int DataMenager::calculateDaysCurrentMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int currentMonth=st.wMonth;
    int currentYear =st.wYear;

    if(currentMonth==1||currentMonth==3||currentMonth==5||currentMonth==7||currentMonth==8||currentMonth==10||currentMonth==12) return 31;
    else if(currentMonth==2)
    {
        if(isLapYear(currentYear)==true) return 29;
            else return 28;
    }
    else if(currentMonth==4||currentMonth==6||currentMonth==9||currentMonth==11) return 30;
}

int DataMenager::lastDateInCurrentMonthAsInt()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int maxDay=calculateDaysCurrentMonth();
    int maxDataAsInt = maxDay+st.wMonth*100+st.wYear*10000;
    return maxDataAsInt;
}

bool DataMenager::isDateInARange(string givenDate)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int maxData=lastDateInCurrentMonthAsInt();
    string givenDateWithoutDash=swapDateWithStringWithoutDash(givenDate);
    int givenDateAsInt = AdditionalMethods::swapStringForInt(givenDateWithoutDash);
    int minData= 20000101;
    if(givenDateAsInt>maxData||givenDateAsInt<minData)
        {
            if(st.wMonth<10&&st.wDay<10){
                cout<<"Minimalna data: 2000-01-01"<<endl;
                cout<<"Maksymalna data: "<<st.wYear<<"-0"<<st.wMonth<<"-0"<<calculateDaysCurrentMonth()<<endl;
            }
            else if(st.wMonth<10&&st.wDay>=10){
                cout<<"Minimalna data: 2000-01-01"<<endl;
                cout<<"Maksymalna data: "<<st.wYear<<"-0"<<st.wMonth<<"-"<<calculateDaysCurrentMonth()<<endl;
            }
            else if(st.wMonth>=10&&st.wDay>=10){
                cout<<"Minimalna data: 2000-01-01"<<endl;
                cout<<"Maksymalna data: "<<st.wYear<<"-"<<st.wMonth<<"-"<<calculateDaysCurrentMonth()<<endl;
            }
                return false;
        }
    else return true;
}

int DataMenager::thisMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return st.wMonth;
}

bool DataMenager::isDateFormat(string givenDate)
{
    int isNumbersAndDashes=0;
    for(int i=0;i<givenDate.length();i++)
    {
        if(givenDate[i]=='0'||givenDate[i]=='1'||givenDate[i]=='2'||givenDate[i]=='3'||givenDate[i]=='4'||givenDate[i]=='5'||givenDate[i]=='6'||givenDate[i]=='7'||givenDate[i]=='8'||givenDate[i]=='9'||givenDate[i]=='-')
        {
            isNumbersAndDashes+=1;
        }
        else isNumbersAndDashes=0;
    }
    if(givenDate.length()==10&&givenDate[4]=='-'&&givenDate[7]=='-'&&isNumbersAndDashes==10)
    {
        return true;
    }
    else return false;
}

bool DataMenager::isCorrectDate(string date)
{
    int year=changeDateToYear(date);
    int month=changeDateToMonth(date);
    int day=changeDateToDay(date);

    if(isDateGood(year, month, day)==true)
        return true;
    else return false;
}
