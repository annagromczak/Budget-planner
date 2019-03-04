#ifndef EXPENSESXML_H
#define EXPENSESXML_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Expense.h"
#include "HelperMethods.h"
#include "UserManager.h"

using namespace std;

class ExpensesXML
{
    CMarkup xml;
    const string expensesXMLFileName;
    int lastExpenseId;

private:
    bool isFileEmpty(string expensesXMLfilename);

public:
    ExpensesXML(string EXPENSES_XML_FILE_NAME) : expensesXMLFileName(EXPENSES_XML_FILE_NAME) {};

    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int ID_LOGGED_USER);
    int getIdLastExpense();

};

#endif
