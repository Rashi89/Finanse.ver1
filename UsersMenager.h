#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <vector>

#include "User.h"
#include "PlikiZUsers.h"
#include "Markup.h"

using namespace std;

class UsersMenager {

    int idZalogowanegoUzytkownika;
    vector <User> users;
    PlikiZUsers plikiZUsers;

    void wyswietlUzytkownika(User user);
    int pobierzIdNowegoUzytkownika();
    User podajDaneNowegoUzytkownika();

public:
    UsersMenager() {
        idZalogowanegoUzytkownika=0;
        users = plikiZUsers.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();


    string wczytajLinie();
    bool czyIstniejeLogin(string login);

};
#endif
