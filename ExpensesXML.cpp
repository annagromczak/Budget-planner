#include "ExpensesXML.h"

void ExpensesXML::addExpenseToFile(Expense expense)
{
    if(isFileEmpty(expensesXMLFileName) == false)
    {
        xml.AddElem("Expenses");
        xml.IntoElem();
        xml.Save(expensesXMLFileName);
    }

    xml.Load(expensesXMLFileName);
    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save(expensesXMLFileName);
    cout << "The new expense has been saved." << endl;
    system ("pause");
}

vector <Expense> ExpensesXML::loadExpensesFromFile(int ID_LOGGED_USER)
{
    Expense expense;
    vector <Expense> expenses;

    xml.Load(expensesXMLFileName);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expenses"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        int userIdFile = HelperMethods::conversionStringToInt(xml.GetData());
        if (ID_LOGGED_USER == userIdFile)
        {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expense.setExpenseId(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.FindElem("Date");
            expense.setDate(xml.GetData());
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(xml.GetData());

            expenses.push_back(expense);
            xml.ResetMainPos();
            xml.OutOfElem();
        }
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
    int idLastexpense = 0;

    xml.Load(expensesXMLFileName);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        idLastexpense = HelperMethods::conversionStringToInt(xml.GetData());
        xml.OutOfElem();
    }
    return idLastexpense;
}
