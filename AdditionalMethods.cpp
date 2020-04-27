#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>
#include <sstream>

#include "AdditionalMethods.h"

string AdditionalMethods::loadLines() {
    string entry;
    getline(cin, entry);
    return entry;
}

float AdditionalMethods::swapStringForFloat(string number)
{
    string whole="",fraction="";
    int commaPosition=0;
    for(int i=0;i<number.length();i++)
    {
        if(number[i]!=','&&number[i]!='.')
        {
            whole+=number[i];
            commaPosition+=1;
        }
        else if(number[i]==',')
        {
            i=number.length()-1;
        }
        else if(number[i]=='.')
        {
             i=number.length()-1;
        }
    }
    for(int i = commaPosition+1;i<number.length();i++)
    {
        fraction+=number[i];
    }

    int wholeNumber = swapStringForInt(whole);
    float fractionNumber = swapStringForInt(fraction);
    float numberAsFloat;
    if(fraction[0]=='0'){
    numberAsFloat = wholeNumber+fractionNumber/100;
    }
    else
    {
        numberAsFloat = wholeNumber+fractionNumber/100;
    }
    return numberAsFloat;
}

int AdditionalMethods::swapStringForInt(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;
    return intNumber;
}

string AdditionalMethods::swapCommaToDot(string number)
{
    string numberWithDot ="";
    for(int i=0;i<number.length();i++)
    {
        if(number[i]!=',')
        {
            numberWithDot+=number[i];
        }
        else if(number[i]==',')
        {
            numberWithDot+='.';
        }
    }
    return numberWithDot;
}

char AdditionalMethods::loadSign()
{
    string entry = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            sign = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

string AdditionalMethods::swapIntForString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
