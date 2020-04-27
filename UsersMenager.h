#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <vector>

#include "User.h"
#include "PlikiZUsers.h"
#include "ExpenseMenager.h"
#include "DataMenager.h"
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
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();



    string wczytajLinie();
    bool czyIstniejeLogin(string login);

};
#endif
