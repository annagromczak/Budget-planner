#include "BudgetPlanner.h"

void BudgetPlanner::userRegistration()
{
    userManager.userRegistration();
}

int BudgetPlanner::userLogin()
{
    userManager.userLogin();
    if (userManager.isUserLogged())
    {
        budgetManager = new BudgetManager(INCOMES_XML_FILE_NAME, EXPENSES_XML_FILE_NAME, userManager.getIdLoggedUser());
    }
}

void BudgetPlanner::changeLoggedUserPassword()
{
    if (userManager.isUserLogged())
    {
            userManager.changeLoggedUserPassword();
    }
    else
    {
        cout << "To change password, first you have to log in." << endl;
        system("pause");
    }
}

void BudgetPlanner::userLogout()
{
    userManager.userLogout();
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetPlanner::addIncome()
{
    if (userManager.isUserLogged())
    {
            budgetManager -> addIncome();
    }
    else
    {
        cout << "To add income, first you have to log in." << endl;
        system("pause");
    }
}

void BudgetPlanner::addExpense()
{
    if (userManager.isUserLogged())
    {
            budgetManager -> addExpense();
    }
    else
    {
        cout << "To add expense, first you have to log in." << endl;
        system("pause");
    }
}

void BudgetPlanner::balanceSheetOfTheCurrentMonth()
{
    if (userManager.isUserLogged())
    {
        budgetManager -> displayBalanceSheetOfTheCurrentMonth();
    }
    else
    {
        cout << "To display balance sheet of the current month, first you have to log in." << endl;
        system("pause");
    }
}

void BudgetPlanner::balanceSheetOfThePreviousMonth()
{
    if (userManager.isUserLogged())
    {
        budgetManager -> displayBalanceSheetOfThePreviousMonth();
    }
    else
    {
        cout << "To display balance sheet of the previous month, first you have to log in." << endl;
        system("pause");
    }
}
void BudgetPlanner::balanceSheetOfTheSelectedPeriod()
{
    if (userManager.isUserLogged())
    {
        budgetManager -> displayBalanceSheetOfTheSelectedPeriod();
    }
    else
    {
        cout << "To display balance sheet of the selected period, first you have to log in." << endl;
        system("pause");
    }
}

bool BudgetPlanner::isUserLogged()
{
   userManager.isUserLogged();
}
