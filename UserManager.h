#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersXML.h"

using namespace std;

class UserManager
{
    vector <User> users;
    int idLoggedUser;
    UsersXML usersXML;

private:
    User enterNewUser();
    int getIdNewUser();
    bool isLoginExist(string login);

public:
    UserManager(string usersXMLFileName) : usersXML(usersXMLFileName)
    {idLoggedUser = 0;
     users = usersXML.loadUsersFromFile();};

    void userRegistration();
    int userLogin();
    int getIdLoggedUser();
    bool isUserLogged();
    void changeLoggedUserPassword();
    int userLogout();
};

#endif // USERMANAGER_H
