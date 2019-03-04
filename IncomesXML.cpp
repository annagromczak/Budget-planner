#include "IncomesXML.h"

void IncomesXML::addIncomeToFile(Income income)
{
    string amount;

    xml.Load(incomesXMLfilename);

    if(isFileEmpty(incomesXMLfilename) == false)
    {
        xml.AddElem("Incomes");
        xml.IntoElem();
        xml.Save(incomesXMLfilename);
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    amount = HelperMethods::conversionDoubleToString(income.getAmount());
    xml.AddElem("Amount", amount);

    xml.Save(incomesXMLfilename);
    cout << "The new income has been saved." << endl;
    system ("pause");
}

vector <Income> IncomesXML::loadIncomesFromFile(int ID_LOGGED_USER)
{
    Income income;
    vector <Income> incomes;
    int userIdFile = 0;

    xml.Load(incomesXMLfilename);
    xml.ResetPos();
    xml.FindElem("Incomes");
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        userIdFile = HelperMethods::conversionStringToInt(xml.GetData());

        if (ID_LOGGED_USER == userIdFile)
        {
            xml.ResetMainPos();
            xml.IntoElem();

            xml.FindElem("IncomeId");
            income.setIncomeId(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("UserId");
            income.setUserId(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("Date");
            income.setDate(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("Amount");
            income.setAmount(HelperMethods::conversionStringToDouble(xml.GetData()));
            xml.ResetMainPos();

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}

bool IncomesXML::isFileEmpty(string incomesXMLFileName)
{
    fstream file;

    file.open(incomesXMLFileName.c_str(), ios::in);
    if (file.is_open())
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}

int IncomesXML::getIdLastIncome()
{
    Income income;

    xml.Load(incomesXMLfilename);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("IncomeId");
        lastIncomeId = HelperMethods::conversionStringToInt(xml.GetData());
        xml.OutOfElem();
    }
    return lastIncomeId;
}
