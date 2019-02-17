#ifndef USERSXML_H
#define USERSXML_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "HelperMethods.h"
#include "Markup.h"

using namespace std;

class UsersXML
{
    const string usersXMLFileName;
    CMarkup xml;

private:
    bool isFileEmpty(string usersXMLFileName);
    User getUserInformation(string login);

public:
    UsersXML(string USERS_XML_FILE_NAME) : usersXMLFileName(USERS_XML_FILE_NAME){};

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changeUserPassword(int idLoggedUser, string newPassword);
};

#endif
