#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "DateManager.h"

using namespace std;

class Income
{
    int incomeId;
    int userId;
    int date;
    string item;
    double amount;

public:
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif // EXPENSE
