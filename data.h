#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data
{
    string dateWithDashesAsString;
    int id;
    int year;
    int month;
    int day;
    int dateWithoutDasesAsInt;

public:

    Data(string dateWithDashesAsString="",int id=0, int year=0, int month=0, int day=0,int dateWithoutDasesAsInt=0)
    {
        this->dateWithDashesAsString = dateWithDashesAsString;
        this->id = id;
        this->year = year;
        this->month = month;
        this->day = day;
        this->dateWithoutDasesAsInt = dateWithoutDasesAsInt;
    }

    //bool operator<(const Data &other);
    //setery
    void setDateWithDashesAsString(string newDateWithDashesAsString);
    void setID(int newID);
    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);
    void setDateWithoutDasesAsInt(int NewDateWithoutDasesAsInt);
    //getery
    string getDateWithDashesAsString();
    int getID();
    int getYear();
    int getMonth();
    int getDay();
    int getDateWithoutDasesAsInt();

};
#endif
