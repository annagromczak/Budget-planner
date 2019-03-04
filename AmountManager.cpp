#include "AmountManager.h"

string AmountManager::changeCommaToDot(string enteredAmount)
{
    for (int i=0; i<enteredAmount.length(); i++)
    {
        if(enteredAmount[i] == 44)
        {
            enteredAmount = enteredAmount.replace(i,1,".");
        }
    }
    return enteredAmount;
}

bool AmountManager::isContainOnlyNumbersAndDots(string enteredAmount)
{
    for (int i=0; i<enteredAmount.length(); i++)
    {
        if(enteredAmount[i] > 57 || enteredAmount[i] < 48 && enteredAmount[i] != 46)
        {
            return false;
        }
    }
    return true;
}

bool AmountManager::isContainOnlyOneDot(string enteredAmount)
{
    int numberOfDots = 0;

    for (int i=0; i<enteredAmount.length(); i++)
    {
        if (enteredAmount[i] == 46 )
        {
            numberOfDots += 1;
        }
    }

    if (numberOfDots <= 1)
    {
        return true;
    }
    else if (numberOfDots > 1)
    {
        return false;
    }
}

bool AmountManager::isAmountCorrect(string enteredAmount)
{
    string amount = "";
    double amountDouble;
    amount = changeCommaToDot(enteredAmount);

    if ((isContainOnlyOneDot(amount) == true) && (isContainOnlyNumbersAndDots(amount) == true) && (amountDouble > 0))
        return true;
    else
        return false;
}

double AmountManager::roundNumberToTwoDecimalPlaces(double number)
{
    double numberTwoDecimalPlaces = 0;

    numberTwoDecimalPlaces = round(number*100)/100;

    return numberTwoDecimalPlaces;
}

