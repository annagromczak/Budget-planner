#ifndef INCOMESXML_H
#define INCOMESXML_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "HelperMethods.h"
#include "UserManager.h"

using namespace std;

class IncomesXML
{
    CMarkup xml;
    const string incomesXMLfilename;
    int lastIncomeId;

private:
    bool isFileEmpty(string incomesXMLfilename);

public:
    IncomesXML(string INCOMES_XML_FILE_NAME) : incomesXMLfilename(INCOMES_XML_FILE_NAME) {};

    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int ID_LOGGED_USER);
    int getIdLastIncome();
};

#endif
