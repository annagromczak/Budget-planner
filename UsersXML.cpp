#include "UsersXML.h"

void UsersXML::addUserToFile(User user)
{
    xml.Load(usersXMLFileName);

    if(isFileEmpty(usersXMLFileName) == false)
    {
        xml.AddElem("Users");
        xml.IntoElem();
        xml.Save(usersXMLFileName);
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(usersXMLFileName);
}

vector <User> UsersXML::loadUsersFromFile()
{
    User user;
    vector <User> users;

    xml.Load(usersXMLFileName);
    xml.ResetPos();
    xml.FindElem("Users");
    xml.IntoElem();

    while (xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setUserId(HelperMethods::conversionStringToInt(xml.GetData()));

        xml.FindElem("Login");
        user.setLogin(xml.GetData());

        xml.FindElem("Password");
        user.setPassword(xml.GetData());

        xml.FindElem("Name");
        user.setName(xml.GetData());

        xml.FindElem("Surname");
        user.setSurname(xml.GetData());

        xml.ResetMainPos();
        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}

void UsersXML::changeUserPassword(int idLoggedUser, string newPassword)
{
    xml.Load(usersXMLFileName);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        int userIdFile = HelperMethods::conversionStringToInt(xml.GetData());

        if (idLoggedUser == userIdFile)
        {
            xml.ResetMainPos();
            xml.IntoElem();
            xml.FindElem("Password");
            xml.RemoveElem();
            xml.AddElem("Password", newPassword);
            break;
        }
        xml.OutOfElem();
    }

    xml.Save(usersXMLFileName);
}

bool UsersXML::isFileEmpty(string usersXMLFileName)
{
    fstream file;

    file.open(usersXMLFileName.c_str(), ios::in);
    if (file.is_open())
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}
