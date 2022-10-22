#ifndef ARTORIA_H_INCLUDED
#define ARTORIA_H_INCLUDED

#include "..\..\head.h"

class CharismaB: public Skills
{
private:
    std::string m_nom="Charisma B";
    std::string nomProprio;
public:
    CharismaB(std::string nomProprio);
    ~CharismaB();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class ManaBurstA: public Skills
{
private:
    std::string m_nom="Mana Burst A";
    std::string nomProprio;

public:
    ManaBurstA(std::string nomProprio);
    ~ManaBurstA();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class ShiningPathEX: public Skills
{
private:
    std::string m_nom="Shining Path EX";
    std::string nomProprio;

public:
    ShiningPathEX(std::string nomProprio);
    ~ShiningPathEX();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    //void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class Excalibur: public NoblePhantasmBuster
{
    int m_degats=4000;
    std::string nomProprio;
    std::string nomNP="Excalibur";

public:
    Excalibur(std::string nomProprio);
    ~Excalibur();
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

Servant* initialiserArtoria(std::string nom);


#endif // ARTORIA_H_INCLUDED
