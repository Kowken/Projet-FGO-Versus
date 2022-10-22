#ifndef CUCHULAINN_H_INCLUDED
#define CUCHULAINN_H_INCLUDED

#include "..\..\head.h"

class BattleContinuationA: public Skills
{
private:
    std::string m_nom="Battle Continuation A";
    std::string nomProprio;
public:
    BattleContinuationA(std::string nomProprio);
    ~BattleContinuationA();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class ProtectionFromArrowsB: public Skills
{
private:
    std::string m_nom="Protection From Arrows B";
    std::string nomProprio;

public:
    ProtectionFromArrowsB(std::string nomProprio);
    ~ProtectionFromArrowsB();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class DisengageC: public Skills
{
private:
    std::string m_nom="Disengage C";
    std::string nomProprio;

public:
    DisengageC(std::string nomProprio);
    ~DisengageC();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class GaeBolg: public NoblePhantasmQuick
{
    int m_degats=16000;
    std::string nomProprio;
    std::string nomNP="Gae Bolg";

public:
    GaeBolg(std::string nomProprio);
    ~GaeBolg();
    std::string getTypeCarte();
    void effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    bool getIsNoblePhantasm();
    std::string getNomProprio();
    void Overcharge();
    std::string getNomNP();
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    int getDegats();
    int getStarGen();
    int getNP();
};

Servant* initialiserCuChulainn(std::string nom);

#endif // CUCHULAINN_H_INCLUDED

