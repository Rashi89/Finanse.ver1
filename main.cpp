#include <iostream>
#include <vector>
#include "Markup.h"
#include "Finanse.h"
#include "DataMenager.h"

using namespace std;

int main() {
    Finanse finanse;
    //finanse.rejestracjaUzytkownika();
    //finanse.wyswietlWszystkichUzytkownikow();
    finanse.logowanieUzytownika();
    //finanse.wyswietlWszystkieItemy();
    //finanse.wylogowanieZalogowanegoUzytkownika();
    //finanse.zmianaHaslaZalogowanegoUzytkownika();
    //finanse.dodajItem();
    finanse.sortowanie();
    finanse.wyswietlWszystkieItemy();
    //DataMenager dataMenager;
    //dataMenager.wczytajDatyZPliku();
    //dataMenager.pobierzDzisiejszaDate();
    //dataMenager.wyswietlDaty();
    //dataMenager.dzisiejszaData();
    //finanse.sortowanie();
    //finanse.wyswietlWszystkieDaty();



    return 0;
}
