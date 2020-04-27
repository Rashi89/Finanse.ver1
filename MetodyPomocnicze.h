#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "IncomeMenager.h"

using namespace std;

class MetodyPomocnicze{

public:
   static string wczytajLinie();
   static float zamianaStringNaFloat(string liczba);
   static int konwersjaStringNaInt(string liczba);
   static string zamienPrzecinekNakropke(string liczba);

};
#endif
