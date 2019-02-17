#include <iostream>

#include "BudgetPlanner.h"
#include "MenuManager.h"

using namespace std;

int main()
{
    BudgetPlanner budgetPlanner("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true)
    {
        if (budgetPlanner.isUserLogged() == false)
        {
            choice = MenuManager::chooseMainMenuOption();

            switch (choice)
            {
            case '1':
                budgetPlanner.userRegistration();
                break;
            case '2':
                budgetPlanner.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no option on the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = MenuManager::chooseUserMenuOption();

            switch (choice)
            {
            case '1':
                budgetPlanner.addIncome();
                break;
            case '2':
                budgetPlanner.addExpense();
                break;
            case '3':
                budgetPlanner.balanceSheetOfTheCurrentMonth();
                break;
            case '4':
                budgetPlanner.balanceSheetOfThePreviousMonth();
                break;
            case '5':
                budgetPlanner.balanceSheetOfTheSelectedPeriod();
                break;
            case '6':
                budgetPlanner.changeLoggedUserPassword();
                break;
            case '7':
                budgetPlanner.userLogout();
                break;
            }

        }
    }

    return 0;
}
