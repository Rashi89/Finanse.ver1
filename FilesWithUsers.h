#ifndef PLIKIZUSERS_H
#define PLIKIZUSERS_H
#include <iostream>
#include <vector>
//
#include "User.h"
#include "Markup.h"


using namespace std;

class FilesWithUsers {

    const string NAME_FILE_USERS;

public:
    FilesWithUsers(string nameFileUsers): NAME_FILE_USERS(nameFileUsers) {};
    vector <User> loadUsersFromFile();
    void appendUserToFile(User user);
    void saveAllUsersToFile(vector <User> &users);

};
#endif
