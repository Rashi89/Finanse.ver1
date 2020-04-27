#ifndef PLIKIZUSERS_H
#define PLIKIZUSERS_H
#include <iostream>
#include <vector>
//
#include "User.h"
#include "Markup.h"

using namespace std;

class PlikiZUsers {


public:

    vector <User> wczytajUzytkownikowZPliku();
    void dopiszUzytkownikaDoPliku(User user);
    void zapiszWszystkichUzytkownikowDoPliku(vector <User> &users);
    User pobierzDaneUzytkownika();

};
#endif
