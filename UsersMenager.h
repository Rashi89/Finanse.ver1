#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "FilesWithUsers.h"
#include "AdditionalMethods.h"

using namespace std;

class UsersMenager {

    int idLoggedUser;
    vector <User> users;
    FilesWithUsers filesWithUsers;

    int getIDNewUser();
    User getDetailsNewUser();

public:
    UsersMenager(string nameFileUsers) : filesWithUsers(nameFileUsers) {
        idLoggedUser=0;
        users = filesWithUsers.loadUsersFromFile();
    };
    void registerUser();
    void loginUser();
    void changePasswordLoggedUser();
    void logoutUser();
    bool isUserLoggedIn();
    int loadIDLoggedUser();
    char selectOptionFromUserMenu();
    bool isLoginExist(string login);

};
#endif
