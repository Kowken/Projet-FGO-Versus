#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "builder.h"
#include "head.h"


void aide();
void aideServants();
void aideCartes();
void aideNP();
void aideJeu();
void initialiserEquipe(Combat* cbt);
void menu();
void jeu();
void introduction();
void color(int couleurDuTexte,int couleurDeFond);
void gotoligcol(int lig, int col);
void sauvegarde(Combat *c);

#endif // MENU_H_INCLUDED

