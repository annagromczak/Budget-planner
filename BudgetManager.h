#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "IncomesXML.h"
#include "ExpensesXML.h"
#include "HelperMethods.h"
#include "MenuManager.h"
#include "Income.h"
#include "Expense.h"
#include "DateManager.h"
#include "AmountManager.h"

using namespace std;

class BudgetManager
{
    const int ID_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    vector <Income> selectedIncomes;
    vector <Expense> selectedExpenses;
    IncomesXML incomesXML;
    ExpensesXML expensesXML;

private:
    Income addNewIncome();
    Expense addNewExpense();
    int enterIncomeDate();
    double enterIncomeAmount();
    int enterExpenseDate();
    double enterExpenseAmount();
    void sortIncomesByDate(vector <Income> &selectedIncomes);
    void sortExpensesByDate(vector <Expense> &selectedExpenses);
    void showBalance(int startDateInt, int endDateInt);
    float getIncomesSum(vector <Income> &selectedIncomes);
    float getExpensesSum(vector <Expense> &selectedExpenses);
    void showIncomes(Income income);
    void showExpenses(Expense expense);
    vector <Income> getSetectedIncomes(int startDateInt, int endDateInt);
    vector <Expense> getSetectedExpenses(int startDateInt, int endDateInt);

public:
    BudgetManager(string incomesXMLFileName, string expensesXMLFileName, int idLoggedUser) : incomesXML(incomesXMLFileName), expensesXML(expensesXMLFileName), ID_LOGGED_USER(idLoggedUser)
    {
        incomes = incomesXML.loadIncomesFromFile(ID_LOGGED_USER);
        expenses = expensesXML.loadExpensesFromFile(ID_LOGGED_USER);
    };

    void addIncome();
    void addExpense();
    void displayBalanceSheetOfTheCurrentMonth();
    void displayBalanceSheetOfThePreviousMonth();
    void displayBalanceSheetOfTheSelectedPeriod();

};

#endif
