#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>
#include <sstream>

#include "MetodyPomocnicze.h"
#include "IncomeMenager.h"

string MetodyPomocnicze::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}

float MetodyPomocnicze::zamianaStringNaFloat(string liczba)
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

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}

string MetodyPomocnicze::zamienPrzecinekNakropke(string liczba)
{
    string liczbaZKropka ="";
    for(int i=0;i<liczba.length();i++)
    {
        if(liczba[i]!=',')
        {
            liczbaZKropka+=liczba[i];
        }
        else if(liczba[i]==',')
        {
            liczbaZKropka+='.';
        }
    }
    return liczbaZKropka;
}

char MetodyPomocnicze::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
