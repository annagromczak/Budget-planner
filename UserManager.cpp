#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = enterNewUser();
    users.push_back(user);
    usersXML.addUserToFile(user);

    cout << endl << "The account was successfully created." << endl << endl;
    system("pause");
}

User UserManager::enterNewUser()
{
    User user;

    user.setUserId(getIdNewUser());

    string login;
    do
    {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isLoginExist(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Enter name: ";
    cin >> name;
    user.setName(HelperMethods::changeFirstLetterToUpperAndOtherLettesToLower(name));

    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    user.setSurname(HelperMethods::changeFirstLetterToUpperAndOtherLettesToLower(surname));

    cin.ignore();
    return user;
}

int UserManager::getIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isLoginExist(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "There is the user with the same login." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::userLogin()
{
    string login = "", password = "";

    cout << endl << "Enter login: ";
    cin >> login;

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int numerOfAttempts = 3; numerOfAttempts > 0; numerOfAttempts--)
            {
                cout << "Enter password. There are still attempts: " << numerOfAttempts << ": ";
                cin >> password;

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    idLoggedUser = users[i].getUserId();
                    cin.ignore();
                    return idLoggedUser;
                }
            }
            cout << "An incorrect password was entered 3 times." << endl;
            system("pause");
            cin.ignore();
            return 0;
        }
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    cin.ignore();
    return 0;
}

int UserManager::getIdLoggedUser()
{
    return idLoggedUser;
}

bool UserManager::isUserLogged()
{
    if (idLoggedUser > 0)
        return true;
    else
        return false;
}

void UserManager::changeLoggedUserPassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    cin >> newPassword;

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getUserId() == idLoggedUser)
        {
            users[i].setPassword(newPassword);
        }
    }

    usersXML.changeUserPassword(getIdLoggedUser(), newPassword);

    cin.ignore();
    cout << "The new password has been saved." << endl;
    system("pause");
}

int UserManager::userLogout()
{
    idLoggedUser = 0;
    return idLoggedUser;
}
