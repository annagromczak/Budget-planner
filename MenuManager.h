#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <iostream>
#include <windows.h>

#include "HelperMethods.h"

using namespace std;

class MenuManager
{
public:
    static char chooseMainMenuOption();
    static char chooseUserMenuOption();
    static char dateIncomeManager();
    static char dateExpenseManager();
};

#endif
