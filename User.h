#ifndef USER_H
#define USER_H
#include <iostream>


using namespace std;


class User {
    int ID;
    string name;
    string surname;
    string login;
    string password;

public:

    User(int id=0, string name="",string surname="",string login="",string password="") {
        this->ID = ID;
        this->name=name;
        this->surname=surname;
        this->login=login;
        this->password=password;
    }

    //setery
    void ustawID(int newID);
    void ustawImie(string newName);
    void ustawNazwisko(string newSurname);
    void ustawLogin(string newLogin);
    void ustawHaslo(string newPassword);
    //getery
    string pobierzImie();
    int pobierzID();
    string pobierzNazwisko();
    string pobierzLogin();
    string pobierzHaslo();

};
#endif
