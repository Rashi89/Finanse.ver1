#include <iostream>
#include <vector>
#include "Markup.h"
#include "UsersMenager.h"

using namespace std;

int main() {
    UsersMenager usersMenager;
    usersMenager.rejestracjaUzytkownika();
    usersMenager.rejestracjaUzytkownika();
    usersMenager.wyswietlWszystkichUzytkownikow();
    //usersMenager.logowanieUzytkownika();
    //usersMenager.wylogowanieZalogowanegoUzytkownika();
    //usersMenager.zmianaHaslaZalogowanegoUzytkownika();
    //usersMenager.wyswietlWszystkichUzytkownikow();

    return 0;
}
