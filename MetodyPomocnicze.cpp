#include <iostream>
#include <vector>
#include <windows.h>
#include <winbase.h>

#include "MetodyPomocnicze.h"

string MetodyPomocnicze::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}
