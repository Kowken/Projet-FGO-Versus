#ifndef MEDUSA_H_INCLUDED
#define MEDUSA_H_INCLUDED

#include "..\..\head.h"

class MysticEyesAPlus: public Skills
{
private:
    std::string m_nom="Mystic Eyes A+";
    std::string nomProprio;
public:
    MysticEyesAPlus(std::string nomProprio);
    ~MysticEyesAPlus();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class MonstrousStrengthB: public Skills
{
private:
    std::string m_nom="Monstrous Strength B";
    std::string nomProprio;

public:
    MonstrousStrengthB(std::string nomProprio);
    ~MonstrousStrengthB();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class BloodFortAndromedaB: public Skills
{
private:
    std::string m_nom="Blood Fort Andromeda B";
    std::string nomProprio;

public:
    BloodFortAndromedaB(std::string nomProprio);
    ~BloodFortAndromedaB();
    std::string getNom();
    void effet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void ResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetMort(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetDefense(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void description();
    //void ProcessusResetEffet(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);
    void effetParTour(std::vector<Servant*>*equipeEnCours,std::vector<Servant*>*equipeAdverse,int& stockEtoilesEquipeEnCours);

};

class Bellerophon: public NoblePhantasmQuick
{
    int m_degats=8000;
    std::string nomProprio;
    std::string nomNP="Bellerophon";

public:
    Bellerophon(std::string nomProprio);
    ~Bellerophon();
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

Servant* initialiserMedusa(std::string nom);

#endif // MEDUSA_H_INCLUDED
