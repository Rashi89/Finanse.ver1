#include "User.h"

void User::ustawID(int noweID) {
    if(noweID>=0)
        ID=noweID;
}
void User::ustawImie(string newName) {
    name=newName;
}
void User::ustawNazwisko(string newSurname) {
    surname=newSurname;
}
void User::ustawLogin(string newLogin) {
    login=newLogin;
}
void User::ustawHaslo(string newPassword) {
    password=newPassword;
}

int User::pobierzID() {
    return ID;
}
string User::pobierzImie() {
    return name;
}
string User::pobierzNazwisko() {
    return surname;
}
string User::pobierzLogin() {
    return login;
}
string User::pobierzHaslo() {
    return password;
}

