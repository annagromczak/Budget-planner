#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

#include "IncomesXML.h"
#include "ExpensesXML.h"
#include "HelperMethods.h"
#include "MenuManager.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class BudgetManager
{
    const int ID_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomesXML incomesXML;
    ExpensesXML expensesXML;

private:
    Income addNewIncome();
    Expense addNewExpense();

public:
    BudgetManager(string incomesXMLFileName, string expensesXMLFileName, int idLoggedUser) : incomesXML(incomesXMLFileName), expensesXML(expensesXMLFileName), ID_LOGGED_USER(idLoggedUser)
    {incomes = incomesXML.loadIncomesFromFile(ID_LOGGED_USER);
    expenses = expensesXML.loadExpensesFromFile(ID_LOGGED_USER);};

    void addIncome();
    void addExpense();
    void displayBalanceSheetOfTheCurrentMonth();
    void displayBalanceSheetOfThePreviousMonth();
    void displayBalanceSheetOfTheSelectedPeriod();

};

#endif
