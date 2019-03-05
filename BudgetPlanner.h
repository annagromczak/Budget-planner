#ifndef BUDGETPLANNER_H
#define BUDGETPLANNER_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "MenuManager.h"

using namespace std;

class BudgetPlanner
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string USERS_XML_FILE_NAME;
    const string INCOMES_XML_FILE_NAME;
    const string EXPENSES_XML_FILE_NAME;

public:
    BudgetPlanner(string usersXMLFileName, string incomesXMLFileName, string expensesXMLFileName) : userManager(usersXMLFileName), INCOMES_XML_FILE_NAME(incomesXMLFileName), EXPENSES_XML_FILE_NAME(expensesXMLFileName)  {
        budgetManager = NULL;
        };
    ~BudgetPlanner()
        {
           delete budgetManager;
           budgetManager = NULL;
        }

    bool isUserLogged();

    void userRegistration();
    int userLogin();

    void addIncome();
    void addExpense();
    void balanceSheetOfTheCurrentMonth();
    void balanceSheetOfThePreviousMonth();
    void balanceSheetOfTheSelectedPeriod();
    void changeLoggedUserPassword();
    void userLogout();
};

#endif // BUDGETPLANNER_H

