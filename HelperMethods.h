#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelperMethods
{
public:
    static string conversionIntToString(int number);
    static int conversionStringToInt(string number);
    static string changeFirstLetterToUpperAndOtherLettesToLower(string text);
    static int getIntegerNumber();
    static char getChar();
    static string getNumber(string text, int signPosition);
    static string getLine();
};

#endif
