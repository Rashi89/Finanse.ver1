#include <iostream>
#include <vector>

#include "User.h"
#include "UsersMenager.h"
#include "Markup.h"
#include "PlikiZUsers.h"

void UsersMenager::rejestracjaUzytkownika() {
    User user=podajDaneNowegoUzytkownika();
    users.push_back(user);
    plikiZUsers.dopiszUzytkownikaDoPliku(user);
}
void UsersMenager::logowanieUzytkownika() {
    User user;
    string login="", haslo="";

    cout<<"Podaj login: ";
    login=wczytajLinie();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = wczytajLinie();

                if (itr -> pobierzHaslo() == haslo) {
                    idZalogowanegoUzytkownika=itr -> pobierzID();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UsersMenager::wylogowanieZalogowanegoUzytkownika() {
    idZalogowanegoUzytkownika=0;
    cout<<"Wylogowales sie!"<<endl;
}

void UsersMenager::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin.sync();
    noweHaslo = wczytajLinie();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> pobierzID() == idZalogowanegoUzytkownika) {

            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikiZUsers.zapiszWszystkichUzytkownikowDoPliku(users);
}

User UsersMenager::podajDaneNowegoUzytkownika() {
    User user;

    user.ustawID(pobierzIdNowegoUzytkownika());

    string imie,nazwisko,login,haslo;

    do {
        cout << "Podaj imie: ";
        cin.sync();
        imie=wczytajLinie();
        user.ustawImie(imie);
        cout << "Podaj nazwisko: ";
        cin.sync();
        nazwisko=wczytajLinie();
        user.ustawNazwisko(nazwisko);
        cout << "Podaj login: ";
        cin.sync();
        login=wczytajLinie();
        user.ustawLogin(login);
    } while (czyIstniejeLogin(user.pobierzLogin()) == true);
    cout << "Podaj haslo: ";
    cin.sync();
    haslo=wczytajLinie();
    user.ustawHaslo(haslo);

    return user;
}

int UsersMenager::pobierzIdNowegoUzytkownika() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().pobierzID() + 1;
}

void UsersMenager::wyswietlUzytkownika(User user) {
    cout<<"ID uzytkownika: "<< user.pobierzID()<<endl;
    cout<<"Imie uzytkownika: "<< user.pobierzImie()<<endl;
    cout<<"Nazwisko uzytkownika: "<< user.pobierzNazwisko()<<endl;
    cout<<"Login uzytkownika: "<< user.pobierzLogin()<<endl;
    cout<<"Haslo uzytkownika: "<< user.pobierzHaslo()<<endl;

}
void UsersMenager::wyswietlWszystkichUzytkownikow() {
    if (!users.empty()) {
        cout << "             >>> UZYTKOWNICY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout<<users.size()<<endl;
        for (vector <User> :: iterator itr = users.begin(); itr != users.end(); itr++) {
            wyswietlUzytkownika(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak uzytkownikow." << endl << endl;
    }
}

int UsersMenager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}


bool UsersMenager::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika>0)
        return true;
    else
        return false;
}


bool UsersMenager::czyIstniejeLogin(string login) {
    //refaktoryzacja kodu
    for(int i=0; i<users.size(); i++) {
        if(users[i].pobierzLogin()==login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

string UsersMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}
