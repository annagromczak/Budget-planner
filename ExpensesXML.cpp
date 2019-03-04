#include "ExpensesXML.h"

void ExpensesXML::addExpenseToFile(Expense expense)
{
    string amount;

    xml.Load(expensesXMLFileName);

    if(isFileEmpty(expensesXMLFileName) == false)
    {
        xml.AddElem("Expenses");
        xml.IntoElem();
        xml.Save(expensesXMLFileName);
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    amount = HelperMethods::conversionDoubleToString(expense.getAmount());
    xml.AddElem("Amount", amount);

    xml.Save(expensesXMLFileName);
    cout << "The new expense has been saved." << endl;
    system ("pause");
}

vector <Expense> ExpensesXML::loadExpensesFromFile(int ID_LOGGED_USER)
{
    Expense expense;
    vector <Expense> expenses;
    int userIdFile = 0;

    xml.Load(expensesXMLFileName);
    xml.ResetPos();
    xml.FindElem("Expenses");
    xml.IntoElem();

    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        userIdFile = HelperMethods::conversionStringToInt(xml.GetData());

        if (ID_LOGGED_USER == userIdFile)
        {
            xml.ResetMainPos();
            xml.IntoElem();

            xml.FindElem("ExpenseId");
            expense.setExpenseId(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("UserId");
            expense.setUserId(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("Date");
            expense.setDate(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("Amount");
            expense.setAmount(HelperMethods::conversionStringToDouble(xml.GetData()));
            xml.ResetMainPos();

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}

bool ExpensesXML::isFileEmpty(string ExpensesXMLFileName)
{
    fstream file;

    file.open(ExpensesXMLFileName.c_str(), ios::in);
    if (file.is_open())
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}

int ExpensesXML::getIdLastExpense()
{
    Expense expense;

    xml.Load(expensesXMLFileName);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        lastExpenseId = HelperMethods::conversionStringToInt(xml.GetData());
        xml.OutOfElem();
    }

    return lastExpenseId;
}
