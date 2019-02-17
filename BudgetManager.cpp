#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;
    income = addNewIncome();

    incomes.push_back(income);
    incomesXML.addIncomeToFile(income);
}

Income BudgetManager::addNewIncome()
{
    Income income;

    income.setIncomeId((incomesXML.getIdLastIncome() + 1));
    income.setUserId(ID_LOGGED_USER);

    cout << "Enter date: ";
    income.setDate(HelperMethods::getLine());

    cout << "Enter item: ";
    income.setItem(HelperMethods::getLine());

    cout << "Enter amount: ";
    income.setAmount(HelperMethods::getLine());

    return income;
}

void BudgetManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;
    expense = addNewExpense();

    expenses.push_back(expense);
    expensesXML.addExpenseToFile(expense);
}

Expense BudgetManager::addNewExpense()
{
    Expense expense;

    expense.setExpenseId((expensesXML.getIdLastExpense() + 1));
    expense.setUserId(ID_LOGGED_USER);

    cout << "Enter date: ";
    expense.setDate(HelperMethods::getLine());

    cout << "Enter item: ";
    expense.setItem(HelperMethods::getLine());

    cout << "Enter amount: ";
    expense.setAmount(HelperMethods::getLine());

    return expense;
}

void BudgetManager::displayBalanceSheetOfTheCurrentMonth()
{

}

void BudgetManager::displayBalanceSheetOfThePreviousMonth()
{

}

void BudgetManager::displayBalanceSheetOfTheSelectedPeriod()
{

}
