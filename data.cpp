#include "Data.h"

    void Data::setDateWithDashesAsString(string newDateWithDashesAsString)
    {
        dateWithDashesAsString=newDateWithDashesAsString;
    }
    void Data::setID(int newID)
    {
        if(newID>=0)
            id=newID;
    }
    void Data::setYear(int newYear)
    {
        if(newYear>=0)
        year=newYear;
    }
    void Data::setMonth(int newMonth)
    {
        if(newMonth>=1&&newMonth<=12)
        month=newMonth;
    }
    void Data::setDay(int newDay)
    {
        if(newDay>=1&&newDay<=31)
            day=newDay;
    }
    void Data::setDateWithoutDasesAsInt(int NewDateWithoutDasesAsInt)
    {
        dateWithoutDasesAsInt=NewDateWithoutDasesAsInt;
    }

    string Data::getDateWithDashesAsString()
    {
        return dateWithDashesAsString;
    }
    int Data::getID()
    {
        return id;
    }
    int Data::getYear()
    {
        return year;
    }
    int Data::getMonth()
    {
        return month;
    }
    int Data::getDay()
    {
        return day;
    }
    int Data::getDateWithoutDasesAsInt()
    {
        return dateWithoutDasesAsInt;
    }
