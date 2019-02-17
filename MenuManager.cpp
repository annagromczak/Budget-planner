#include "MenuManager.h"

char MenuManager::chooseMainMenuOption()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MANU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Close the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelperMethods::getChar();

    return choice;
}

char MenuManager::chooseUserMenuOption()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display Balance sheet of the current month" << endl;
    cout << "4. Display Balance sheet of the previous month" << endl;
    cout << "5. Display Balance sheet of the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelperMethods::getChar();

    return choice;
}
