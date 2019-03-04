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

char MenuManager::dateIncomeManager()
{
    char choice;

    cout << "1. Add an income with today's date" << endl;
    cout << "2. Add an income with a different date" << endl;

    choice = HelperMethods::getChar();

    return choice;
}

char MenuManager::dateExpenseManager()
{
    char choice;

    cout << "1. Add an expense with today's date" << endl;
    cout << "2. Add an expense with a different date" << endl;

    choice = HelperMethods::getChar();

    return choice;
}
