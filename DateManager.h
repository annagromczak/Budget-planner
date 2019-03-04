#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include <time.h>

#include "HelperMethods.h"

using namespace std;

class DateManager
{
    bool isNumberOfDayCorrect(int enteredYear, int enteredMonth, int enteredDay);
    bool isNumberOfMonthCorrect (int enteredMonth, int enteredYear, int currentYear, int currentMonth);
    bool isNumberOfYearCorrect (int year, int currentYear);
    bool isYearLeap(int year);
    bool checkNumberOfDaysInSelectMonth(int year, int month, int days);

public:
    int changeDateStringToInt(string dateString);
    int getCurrentDate();
    int getFirstDayCurrentMonth();
    bool isDateCorrect(string enteredDateString);
    string convertDateFromIntToStringWithDash(int dateInt);
    int getFirstDayPreviousMonth();
    int getLastDayPreviousMonth();
};

#endif
