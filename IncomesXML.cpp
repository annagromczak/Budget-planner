#include "IncomesXML.h"

void IncomesXML::addIncomeToFile(Income income)
{
    if(isFileEmpty(incomesXMLfilename) == false)
    {
        xml.AddElem("Incomes");
        xml.IntoElem();
        xml.Save(incomesXMLfilename);
    }

    xml.Load(incomesXMLfilename);
    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save(incomesXMLfilename);
    cout << "The new income has been saved." << endl;
    system ("pause");
}

vector <Income> IncomesXML::loadIncomesFromFile(int ID_LOGGED_USER)
{
    Income income;
    vector <Income> incomes;

    xml.Load(incomesXMLfilename);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        int userIdFile = HelperMethods::conversionStringToInt(xml.GetData());
        if (ID_LOGGED_USER == userIdFile)
        {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(HelperMethods::conversionStringToInt(xml.GetData()));
            xml.FindElem("Date");
            income.setDate(xml.GetData());
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(xml.GetData());

            incomes.push_back(income);
            xml.ResetMainPos();
            xml.OutOfElem();
        }
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
    int idLastIncome = 0;

    xml.Load(incomesXMLfilename);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("IncomeId");
        idLastIncome = HelperMethods::conversionStringToInt(xml.GetData());
        xml.OutOfElem();
    }
    return idLastIncome;
}
