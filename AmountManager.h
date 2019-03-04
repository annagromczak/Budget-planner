#ifndef AMOUNTMANAGER_H
#define AMOUNTMANAGER_H

#include <iostream>
#include <math.h>

#include "HelperMethods.h"

using namespace std;

class AmountManager
{
    bool isContainOnlyNumbersAndDots(string enteredAmount);
    bool isContainOnlyOneDot(string enteredAmount);

public:
    bool isAmountCorrect(string enteredAmount);
    double roundNumberToTwoDecimalPlaces(double number);
    string changeCommaToDot(string enteredAmount);
};

#endif
