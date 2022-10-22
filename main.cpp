//#define TRACE_ON
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include "head.h"
#include "menu.h"

/// mettre la console en plein écran  ///

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleOutputCP(1252);
    introduction();
    /// mettre en commentaire introduction après l'avoir vu une 1 ère fois ///
    menu();
    return 0;
}






