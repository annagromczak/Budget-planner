#include "DateManager.h"

bool DateManager::isYearLeap(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}

bool DateManager::isNumberOfDayCorrect(int enteredYear, int enteredMonth, int enteredDay)
{
    if (enteredMonth == 1 || enteredMonth == 3 || enteredMonth == 5 || enteredMonth == 7 || enteredMonth == 8 || enteredMonth == 10 || enteredMonth == 12)
    {
        enteredDay > 0 && enteredDay < 32;
        return true;
    }
    else if (enteredMonth == 2)
    {
        if (isYearLeap(enteredYear) == true)
        {
            enteredDay > 0 && enteredDay < 29;
            return true;
        }
        else
        {
            enteredDay > 0 && enteredDay < 28;
            return true;
        }
    }
    else if (enteredMonth == 4 || enteredMonth == 6 || enteredMonth == 9 || enteredMonth == 11)
    {
        enteredDay > 0 && enteredDay < 31;
        return true;
    }
    else
        return false;
}

bool DateManager::isNumberOfMonthCorrect (int enteredMonth, int enteredYear, int currentYear, int currentMonth)
{
    if ((enteredMonth > 0 && enteredMonth < 13) && (enteredYear == currentYear) && (enteredMonth <= currentMonth))
        return true;
    else if ((enteredMonth > 0 && enteredMonth < 13) && (enteredYear < currentYear))
        return true;
    else
        return false;
}

bool DateManager::isNumberOfYearCorrect (int year, int currentYear)
{
    if ((year >= 2000) && (year <= currentYear))
        return true;
    else
        return false;
}

bool DateManager::isDateCorrect(string enteredDateString)
{
    if (enteredDateString.length() == 10)
    {
        string enteredYearString = enteredDateString.substr(0,4);
        string enteredMonthString = enteredDateString.substr(5,2);
        string enteredDayString = enteredDateString.substr(8,2);

        int enteredYear = HelperMethods::conversionStringToInt(enteredYearString);
        int enteredMonth = HelperMethods::conversionStringToInt(enteredMonthString);
        int enteredDay = HelperMethods::conversionStringToInt(enteredDayString);

        time_t currentDate = time(0);
        tm * time = localtime(&currentDate);
        int currentYear = 1900 + time->tm_year;
        int currentMonth = 1 + time->tm_mon;
        int currentDay = time->tm_mday;

        if ((isNumberOfYearCorrect(enteredYear, currentYear) == true) && (isNumberOfMonthCorrect(enteredMonth, enteredYear, currentYear, currentMonth) == true) && (isNumberOfDayCorrect(enteredYear, enteredMonth, enteredDay) == true))
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

int DateManager::changeDateStringToInt(string enteredDateString)
{
    string enteredYearString = "", enteredMonthString = "", enteredDayString = "";

    enteredYearString = enteredDateString.substr(0,4);
    enteredMonthString = enteredDateString.substr(5,2);
    enteredDayString = enteredDateString.substr(8,2);

    string shortEnteredDateString = enteredYearString + enteredMonthString + enteredDayString;
    int enteredDateInt = HelperMethods::conversionStringToInt(shortEnteredDateString);

    return enteredDateInt;
}

int DateManager::getCurrentDate()
{
    time_t currentDate = time(0);
    tm * time = localtime(&currentDate);

    int currentYear = 1900 + time->tm_year;
    int currentMonth = 1 + time->tm_mon;
    int currentDay = time->tm_mday;

    string dateString = "";
    int dateInt = currentYear * 10000 + currentMonth * 100 + currentDay;

    return dateInt;
}

int DateManager::getFirstDayCurrentMonth()
{
    string dateString = "";
    int dateInt = 0;

    dateInt = getCurrentDate();
    dateString = HelperMethods::conversionIntToString(dateInt);
    dateString = dateString.replace(6,2,"01");;

    dateInt = HelperMethods::conversionStringToInt(dateString);

    return dateInt;
}

int DateManager::getFirstDayPreviousMonth()
{
    int dateInt = 0;

    time_t currentDate = time(0);
    tm * time = localtime(&currentDate);

    int currentYear = 1900 + time->tm_year;
    int currentMonth = 1 + time->tm_mon;

    if (currentMonth != 1)
    {
        dateInt = currentYear * 10000 + (currentMonth - 1) * 100 + 1;
    }
    else
    {
        dateInt = (currentYear - 1) * 10000 + 12 * 100 + 1;
    }

    return dateInt;
}

int DateManager::getLastDayPreviousMonth()
{
    int dateInt = 0;
    int firstDayPreviousMonth = getFirstDayPreviousMonth();
    string firstDayPreviousMonthString = HelperMethods::conversionIntToString(firstDayPreviousMonth);
    string previousMonthString = firstDayPreviousMonthString.substr(4,2);
    string currentYearString = firstDayPreviousMonthString.substr(0,4);
    int previousMonthInt = HelperMethods::conversionStringToInt(previousMonthString);
    int currentYear = HelperMethods::conversionStringToInt(currentYearString);

    if (previousMonthInt == 1 || previousMonthInt == 3 || previousMonthInt == 5 || previousMonthInt == 7 || previousMonthInt == 8 || previousMonthInt == 10 || previousMonthInt == 12)
    {
        dateInt = currentYear * 10000 + previousMonthInt * 100 + 31;
    }
    else if (previousMonthInt == 2)
    {
        if (isYearLeap(currentYear)==true)
        {
            dateInt = currentYear * 10000 + previousMonthInt * 100 + 29;
        }
        else
        {
            dateInt = currentYear * 10000 + previousMonthInt * 100 + 28;
        }
    }
    else
    {
        dateInt = currentYear * 10000 + previousMonthInt * 100 + 30;
    }

    return dateInt;
}

string DateManager::convertDateFromIntToStringWithDash(int dateInt)
{
    string dateString = "";
    string date = "";

    date = HelperMethods::conversionIntToString(dateInt);

    dateString = date.insert(4,"-");
    dateString = date.insert(7,"-");

    return dateString;
}
