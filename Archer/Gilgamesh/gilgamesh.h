#ifndef GILGAMESH_H_INCLUDED
#define GILGAMESH_H_INCLUDED

#include "..\..\head.h"

class CharismaAplus: public Skills
{
private:
    std::string m_nom="Charisma A+";
    std::string nomProprio;
public:
    CharismaAplus(std::string nomProprio);
    ~CharismaAplus();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    //void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class GoldenRuleA: public Skills
{
private:
    std::string m_nom="Golden Rule A";
    std::string nomProprio;

public:
    GoldenRuleA(std::string nomProprio);
    ~GoldenRuleA();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    //void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class TreasuryOfBabylonEX: public Skills
{
private:
    std::string m_nom="Treasury Of Babylon EX";
    std::string nomProprio;

public:
    TreasuryOfBabylonEX(std::string nomProprio);
    ~TreasuryOfBabylonEX();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    //void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class EnumaElish: public NoblePhantasmBuster
{
    int m_degats=3000;
    std::string nomProprio;
    std::string nomNP="Enuma Elish";

public:
    EnumaElish(std::string nomProprio);
    ~EnumaElish();
    std::string getTypeCarte();
    void effet(Servant* Cible,std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void resetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    bool getIsNoblePhantasm();
    std::string getNomProprio();
    void Overcharge();
    std::string getNomNP();
    void description();
    //void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    int getDegats();
    int getStarGen();
    int getNP();
};

Servant* initialiserGilgamesh(std::string nom);
#endif // GILGAMESH_H_INCLUDED
