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

int BudgetManager::enterIncomeDate()
{
    int choice = 0;
    int incomeDate = 0;
    DateManager dateManager;
    string enteredDate = "";
    bool dateCorrect = false;
    choice = MenuManager::dateIncomeManager();

    switch (choice)
    {
    case '1':
        incomeDate = dateManager.getCurrentDate();
        break;
    case '2':
        do
        {
            cout << "Enter the date in format yyyy-mm-dd. You can choose a date from 2000-01-01 to the last day of the current month: " << endl;
            enteredDate = HelperMethods::getLine();

            if (dateManager.isDateCorrect(enteredDate) == true)
            {
                incomeDate = dateManager.changeDateStringToInt(enteredDate);
                dateCorrect = true;
            }
            else
            {
                cout << "The entered date is incorrect. Try again." << endl;
                system("pause");
                dateCorrect = false;
            }
        }
        while (dateCorrect == false);
    }
    return incomeDate;
}

double BudgetManager::enterIncomeAmount()
{
    AmountManager amountManager;
    string enteredAmount = "";
    double incomeAmount = 0;
    bool amountCorrect = false;

    do
    {
        cout << "Enter the amount: " << endl;
        enteredAmount = HelperMethods::getLine();

        if(amountManager.isAmountCorrect(enteredAmount) == true)
        {
            incomeAmount = amountManager.roundNumberToTwoDecimalPlaces(HelperMethods::conversionStringToDouble(amountManager.changeCommaToDot(enteredAmount)));
            amountCorrect = true;
        }
        else
        {
            cout << "The entered amount is incorrect. Try again." << endl;
            system("pause");
            amountCorrect = false;
        }
    }
    while (amountCorrect == false);

    return incomeAmount;
}

Income BudgetManager::addNewIncome()
{
    Income income;

    income.setIncomeId((incomesXML.getIdLastIncome() + 1));
    income.setUserId(ID_LOGGED_USER);

    income.setDate(enterIncomeDate());

    cout << "Enter the item: ";
    income.setItem(HelperMethods::getLine());

    income.setAmount(enterIncomeAmount());

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

int BudgetManager::enterExpenseDate()
{
    int choice = 0;
    int expenseDate = 0;
    DateManager dateManager;
    string enteredDate = "";
    bool dateCorrect = false;

    choice = MenuManager::dateIncomeManager();

    switch (choice)
    {
    case '1':
        expenseDate = dateManager.getCurrentDate();
        break;
    case '2':
        do
        {
            cout << "Enter the date in format yyyy-mm-dd. You can choose the date from 2000-01-01 to the last day of the current month: " << endl;
            enteredDate = HelperMethods::getLine();

            if (dateManager.isDateCorrect(enteredDate) == true)
            {
                expenseDate = dateManager.changeDateStringToInt(enteredDate);
                dateCorrect = true;
            }
            else
            {
                cout << "The entered date is incorrect. Try again." << endl;
                system("pause");
                dateCorrect = false;
            }
        }
        while (dateCorrect == false);
    }
    return expenseDate;
}

double BudgetManager::enterExpenseAmount()
{
    AmountManager amountManager;
    string enteredAmount = "";
    double expenseAmount = 0;
    bool amountCorrect = false;

    do
    {
        cout << "Enter the amount: " << endl;
        enteredAmount = HelperMethods::getLine();

        if(amountManager.isAmountCorrect(enteredAmount) == true)
        {
            expenseAmount = amountManager.roundNumberToTwoDecimalPlaces(HelperMethods::conversionStringToDouble(amountManager.changeCommaToDot(enteredAmount)));
            amountCorrect = true;
        }
        else
        {
            cout << "The entered amount is incorrect. Try again." << endl;
            system("pause");
            amountCorrect = false;
        }
    }
    while (amountCorrect == false);

    return expenseAmount;
}

Expense BudgetManager::addNewExpense()
{
    Expense expense;
    DateManager dateManager;
    string enteredDate;
    int choice = 0;
    bool dateCorrect = false;

    expense.setExpenseId((expensesXML.getIdLastExpense() + 1));
    expense.setUserId(ID_LOGGED_USER);

    expense.setDate(enterExpenseDate());

    cout << "Enter the item: ";
    expense.setItem(HelperMethods::getLine());

    expense.setAmount(enterExpenseAmount());

    return expense;
}

void BudgetManager::displayBalanceSheetOfTheCurrentMonth()
{
    DateManager dateManager;
    int startDateInt = dateManager.getFirstDayCurrentMonth();
    int endDateInt = dateManager.getCurrentDate();

    showBalance(startDateInt, endDateInt);
}

void BudgetManager::displayBalanceSheetOfThePreviousMonth()
{
    DateManager dateManagaer;
    int startDateInt = dateManagaer.getFirstDayPreviousMonth();
    int endDateInt = dateManagaer.getLastDayPreviousMonth();

    showBalance(startDateInt, endDateInt);
}

void BudgetManager::displayBalanceSheetOfTheSelectedPeriod()
{
    DateManager dateManager;
    string startDateString = "", endDateString = "";
    int startDateInt = 0, endDateInt = 0;
    bool dateCorrect = false;

    do
    {
        cout << "Enter the begin date of the balance (in format yyyy-mm-dd): " << endl;
        startDateString = HelperMethods::getLine();

        if (dateManager.isDateCorrect(startDateString) == true)
        {
            startDateInt = dateManager.changeDateStringToInt(startDateString);
            cout << "Enter the end date of the balance (in format yyyy-mm-dd): " << endl;
            endDateString = HelperMethods::getLine();

            if (dateManager.isDateCorrect(endDateString) == true)
            {
                endDateInt = dateManager.changeDateStringToInt(endDateString);

                if (startDateInt < endDateInt)
                {
                  dateCorrect = true;
                }
                else
                {
                                  cout << "The entered date is incorrect. Try again." << endl;
                system("pause");
                dateCorrect = false;
                }
            }
            else
            {
                cout << "The entered date is incorrect. Try again." << endl;
                system("pause");
                dateCorrect = false;
            }
        }
        else
        {
            cout << "The entered date is incorrect. Try again." << endl;
            system("pause");
            dateCorrect = false;
        }
    }
    while (dateCorrect == false);

    showBalance(startDateInt, endDateInt);
}

struct CompareIncomeesDate
{
    bool operator() (Income& firstIncome, Income& secondIncome)
    {
        return firstIncome.getDate() < secondIncome.getDate();
    }
};

void BudgetManager::sortIncomesByDate(vector <Income> &selectedIncomes)
{
    sort(selectedIncomes.begin(), selectedIncomes.end(), CompareIncomeesDate());
}

struct CompareExpensesDate
{
    bool operator() (Expense& firstExpense, Expense& secondExpense)
    {
        return firstExpense.getDate() < secondExpense.getDate();
    }
};

void BudgetManager::sortExpensesByDate(vector <Expense> &selectedExpenses)
{
    sort(selectedExpenses.begin(), selectedExpenses.end(), CompareExpensesDate());
}

void BudgetManager::showIncomes(Income income)
{
    DateManager dateManager;

    cout << "Date:               " << dateManager.convertDateFromIntToStringWithDash(income.getDate()) << endl;
    cout << "Item:               " << income.getItem() << endl;
    cout << "Amount:             " << income.getAmount() << endl;
    cout << endl;
}

void BudgetManager::showExpenses(Expense expense)
{
    DateManager dateManager;

    cout << "Date:               " << dateManager.convertDateFromIntToStringWithDash(expense.getDate()) << endl;
    cout << "Item:               " << expense.getItem() << endl;
    cout << "Amount:             " << expense.getAmount() << endl;
    cout << endl;
}

vector <Income> BudgetManager::getSetectedIncomes(int startDateInt, int endDateInt)
{
    vector <Income> selectedIncomes;

    for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if ((itr -> getDate() >= startDateInt) && (itr -> getDate() <= endDateInt))
        {
            selectedIncomes.push_back(*itr);
        }
    }
    return selectedIncomes;
}

vector <Expense> BudgetManager::getSetectedExpenses(int startDateInt, int endDateInt)
{
    vector <Expense> selectedExpenses;

    for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if ((itr -> getDate() >= startDateInt) && (itr -> getDate() <= endDateInt))
        {
            selectedExpenses.push_back(*itr);
        }
    }
    return selectedExpenses;
}

void BudgetManager::showBalance(int startDateInt, int endDateInt)
{
    DateManager dateManager;

    selectedIncomes = getSetectedIncomes(startDateInt, endDateInt);
    sortIncomesByDate(selectedIncomes);
    selectedExpenses = getSetectedExpenses(startDateInt, endDateInt);
    sortExpensesByDate(selectedExpenses);

    system("cls");
    cout << "Balance sheet from " << dateManager.convertDateFromIntToStringWithDash(startDateInt) << " to " << dateManager.convertDateFromIntToStringWithDash(endDateInt) << "." << endl;
    if (!selectedIncomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
        {
            showIncomes(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There is not income." << endl << endl;
    }

    if (!selectedExpenses.empty())
    {
        cout << endl << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
        {
            showExpenses(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There is not expense." << endl << endl;
    }

    cout << endl << "             >>> SUM <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl << "Sum of incomes: " << getIncomesSum(selectedIncomes) << endl;
    cout << "Sum of expenses: " << getExpensesSum(selectedExpenses) << endl;
    cout << "Balance: " << getIncomesSum(selectedIncomes) - getExpensesSum(selectedExpenses) << endl << endl;
    system("pause");
}


float BudgetManager::getIncomesSum(vector <Income> &selectedIncomes)
{
    float incomesSum = 0;
    double amount = 0;

    for (vector <Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
    {
        amount = itr -> getAmount();
        incomesSum +=  amount;
    }

    return incomesSum;
}

float BudgetManager::getExpensesSum(vector <Expense> &selectedExpenses)
{
    float expensesSum = 0;
    double amount = 0;

    for (vector <Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
    {
        amount = itr -> getAmount();
        expensesSum +=  amount;
    }

    return expensesSum;
}
