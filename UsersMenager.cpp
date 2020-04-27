#include <iostream>
#include <vector>

#include "UsersMenager.h"

void UsersMenager::registerUser() {
    User user=getDetailsNewUser();
    users.push_back(user);
    filesWithUsers.appendUserToFile(user);
}
void UsersMenager::loginUser() {
    User user;
    string login="", password="";

    cout<<"Podaj login: ";
    login=AdditionalMethods::loadLines();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> pobierzLogin() == login) {
            for (int i = 3; i > 0; i--) {
                cout << "Podaj haslo. Pozostalo prob: " << i << ": ";
                password = AdditionalMethods::loadLines();

                if (itr -> pobierzHaslo() == password) {
                    idLoggedUser=itr -> pobierzID();
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

void UsersMenager::logoutUser() {
    idLoggedUser=0;
    cout<<"Wylogowales sie!"<<endl;
}

void UsersMenager::changePasswordLoggedUser() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin.sync();
    newPassword = AdditionalMethods::loadLines();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> pobierzID() == idLoggedUser) {

            itr -> ustawHaslo(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    filesWithUsers.saveAllUsersToFile(users);
}

User UsersMenager::getDetailsNewUser() {
    User user;

    user.ustawID(getIDNewUser());

    string name,surname,login,password;

    do {
        cout << "Podaj imie: ";
        cin.sync();
        name=AdditionalMethods::loadLines();
        user.ustawImie(name);
        cout << "Podaj nazwisko: ";
        cin.sync();
        surname=AdditionalMethods::loadLines();
        user.ustawNazwisko(surname);
        cout << "Podaj login: ";
        cin.sync();
        login=AdditionalMethods::loadLines();
        user.ustawLogin(login);
    } while (isLoginExist(user.pobierzLogin()) == true);
    cout << "Podaj haslo: ";
    cin.sync();
    password=AdditionalMethods::loadLines();
    user.ustawHaslo(password);

    return user;
}

int UsersMenager::getIDNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().pobierzID() + 1;
}

/*void UsersMenager::showUser(User user) {
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
            showUser(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak uzytkownikow." << endl << endl;
    }
}*/

int UsersMenager::loadIDLoggedUser()
{
    return idLoggedUser;
}

bool UsersMenager::isUserLoggedIn()
{
    if(idLoggedUser>0)
        return true;
    else
        return false;
}

bool UsersMenager::isLoginExist(string login) {
    for(int i=0; i<users.size(); i++) {
        if(users[i].pobierzLogin()==login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

char UsersMenager::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z tego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AdditionalMethods::loadSign();

    return choice;
}
