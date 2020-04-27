#include <iostream>
#include <vector>
#include "Markup.h"
#include "Finanse.h"
#include "DataMenager.h"
#include "ExpenseMenager.h"

using namespace std;

int main() {
    Finanse finanse;

    finanse.logowanieUzytownika();

    finanse.dodajItem();
    //finanse.wyswietlWszystkieItemy();
    //finanse.wyswietlWszystkieDaty();
   // finanse.sortowanie();
   // finanse.wyswietlItemyZTegoMiesiaca();
    //finanse.wyswietlItemyZPoprzedniegoMiesiaca();
    //finanse.wyswietlItemyZPodanegoZakresu();
    //DataMenager dataMenager;
    //dataMenager.dzisiejszaDataJakoInt();

    return 0;
}
