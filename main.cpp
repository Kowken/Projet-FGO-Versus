//#define TRACE_ON
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include "head.h"
#include "menu.h"

/// mettre la console en plein �cran  ///

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleOutputCP(1252);
    introduction();
    /// mettre en commentaire introduction apr�s l'avoir vu une 1 �re fois ///
    menu();
    return 0;
}






