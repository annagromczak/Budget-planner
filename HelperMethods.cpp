#include "HelperMethods.h"

string HelperMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int HelperMethods::conversionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string HelperMethods::changeFirstLetterToUpperAndOtherLettesToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int HelperMethods::getIntegerNumber()
{
    string entrance = "";
    int number = 0;

    while (true)
    {
        getline(cin, entrance);

        stringstream myStream(entrance);
        if (myStream >> number)
            break;
        cout << "It is not a number. Try again. " << endl;
    }
    return number;
}

char HelperMethods::getChar()
{
    string entrance = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entrance);

        if (entrance.length() == 1)
        {
            sign = entrance[0];
            break;
        }
        cout << "It is not a single character. Try again." << endl;
    }
    return sign;
}

string HelperMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

string HelperMethods::getLine()
{
    string line = "";
    getline(cin, line);
    return line;
}
